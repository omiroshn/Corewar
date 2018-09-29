/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:36:08 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/16 14:37:31 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include <inttypes.h>
# include <stddef.h>
# include <libft.h>

struct s_player;

typedef enum			e_event_type
{
	kEventsBegin = 0,
	kEventEndOfGame = kEventsBegin,
	kEventProcessWrite,
	kEventProcessMove,
	kEventProcessCreate,
	kEventProcessDeath,
	kEventNewCycle,
	kEventLive,
	kEventAff,
	kEventPlayerCreate,
	kEventCheckUp,
	kEventUiUpdate,
	kEventsTotal
}						t_event_type;

struct					s_event_ui_update
{
	int					update_speed;
	bool				paused;
};

struct					s_event_player_create
{
	int32_t				id;
	uint16_t			weight;
	uint8_t				num;
};

struct					s_event_game_end
{
	uint8_t				winner_num;
};

struct					s_event_proc_write
{
	int32_t				value;
	int32_t				master_id;
	uint16_t			position;
};

struct					s_event_proc_move
{
	uint16_t			position;
	int32_t				proc_id;
};

struct					s_event_proc_create
{
	int32_t				player_id;
	int32_t				proc_id;
	uint16_t			position;
};

struct					s_event_proc_death
{
	int32_t				proc_id;
};

struct					s_event_new_cycle
{
	uint32_t			cycle_num;
	int32_t				last_alive_player;
	uint16_t			num_live_calls;
};

struct					s_event_live
{
	int32_t				player_id;
	int32_t				caller_id;
	uint8_t				player_num;
};

struct					s_event_check_up
{
	uint16_t			cycles_to_die;
	uint8_t				num_checkups_wo_decrease;
};

struct					s_event_aff
{
	int32_t				caller_id;
	char				c;
};

union					u_event_info
{
	struct s_event_game_end			ge;
	struct s_event_proc_write		wr;
	struct s_event_proc_move		mv;
	struct s_event_proc_create		pc;
	struct s_event_proc_death		pd;
	struct s_event_new_cycle		nc;
	struct s_event_live				lc;
	struct s_event_aff				af;
	struct s_event_player_create	plc;
	struct s_event_check_up			cu;
	struct s_event_ui_update		uu;
};

struct					s_event_header
{
	t_event_type		type;
	uint8_t				arb_str_len;
	uint16_t			arb2_str_len;
};

struct					s_event
{
	struct s_event_header	header;
	union u_event_info		info;
	char					*arbitrary_string;
	char					*arbitrary_string2;
};

void					event_init(
							struct s_event *event,
							t_event_type type);

# define EVENT_DECL(type) struct s_event event; event_init(&event, type);

typedef void			(*t_event_handler)(void *event, void *ctx);

struct					s_event_observer
{
	void				*ctx;
	t_event_handler		handlers[kEventsTotal];
};

void					register_observer(struct s_event_observer *observer);
void					unregister_observer(struct s_event_observer *observer);
void					post_event(struct s_event *event);

void					post_end_of_game(
							uint8_t winner_num);
void					post_proc_write(
							int32_t player_id,
							int32_t value,
							uint16_t memory_pool_position);
void					post_proc_move(
							int32_t proc_id,
							uint16_t new_position);
void					post_proc_create(
							int32_t player_id,
							int32_t proc_id,
							uint16_t position);
void					post_proc_death(
							int32_t proc_id);
void					post_new_cycle(
							uint32_t new_cycle,
							int32_t last_alive_player,
							uint16_t num_live_calls);
void					post_live(
							int32_t caller_id,
							int32_t player_id,
							uint8_t player_num);
void					post_aff(
							int32_t caller_id,
							char c);
void					post_player_create(
							int32_t player_id,
							uint16_t player_weight,
							uint8_t player_num,
							t_tuple name_comment_code_tuple);
void					post_check_up(
							uint16_t cycles_to_die,
							uint8_t num_checkups_wo_decrease);
void					post_ui_update(
							bool paused,
							int update_speed);

extern char		*g_event_type_to_string[kEventsTotal];
extern size_t	g_event_type_to_packet_size[kEventsTotal];

#endif
