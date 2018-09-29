/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 14:58:42 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/02 15:04:50 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSES_H
# define CURSES_H

# include "op.h"
# include "dlist.h"
# include "timer.h"

# include <ncurses.h>
# include <stdbool.h>

# define P "______                                        _                 _           __ _       _     _     "
# define R "| ___ \\                                      | |               | |         / _(_)     (_)   | |    "
# define E "| |_/ / __ ___  ___ ___    __ _ _ __  _   _  | | _____ _   _   | |_ ___   | |_ _ _ __  _ ___| |__  "
# define S "|  __/ '__/ _ \\/ __/ __|  / _` | '_ \\| | | | | |/ / _ \\ | |  | | __/ _ \\  |  _| | '_ \\| / __| '_ \\ "
# define SS "| |  | | |  __/\\__ \\__ \\ | (_| | | | | |_| | |   <  __/ |_|  | | || (_) | | | | | | | | \\__ \\ | | |"
# define K "\\_|  |_|  \\___||___/___/  \\__,_|_| |_|\\__, | |_|\\_\\___|\\_ _, |  \\__\\___/  |_| |_|_| |_|_|___/_| |_|"
# define EE "                                       __/ |            __/ |                                       "
# define Y "                                       |___/            |___/                                       "

struct			s_win
{
	WINDOW		*win;
	int			w;
	int			h;
};

struct			s_curses_player
{
	char		name[PROG_NAME_LENGTH];
	char		comment[COMMENT_LENGTH];
	char		code[CHAMP_MAX_SIZE];
	int32_t		id;
	uint32_t	total_live_calls;
	uint16_t	live_calls;
	uint16_t	weight;
	uint16_t	num_processes;
};

struct			s_curses_process
{
	int32_t					owner_id;
	int32_t					id;
	uint16_t				position;
};

struct			s_cell
{
	uint8_t		player_num;
	uint16_t	rewritten;
};

struct			s_curses
{
	double					previous_livebreakdown[MAX_PLAYERS];
	double					livebreakdown[MAX_PLAYERS];
	struct s_curses_player	players[MAX_PLAYERS];
	struct s_cell			cells[MEM_SIZE];
	uint8_t					mem_pool[MEM_SIZE];
	struct s_win			main;
	struct s_win			info;
	struct s_dlist			processes;
	t_timer					timer;
	uint8_t					num_players;
	uint32_t				current_cycle;
	int32_t					last_alive_player;
	uint16_t				num_live_calls;
	uint16_t				live_calls;
	uint16_t				cycles_to_die;
	uint16_t				cycles_per_sec;
	uint8_t					num_checkups_wo_decrease;
	bool					paused;

};

typedef enum	e_curses_key
{
	kCursesKeyNone = -1
}				t_curses_key;

bool			curses_init(struct s_curses *curses);
void			curses_deinit(struct s_curses *curses);
int				curses_get_event_key(void);

#endif
