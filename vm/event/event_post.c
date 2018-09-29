/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_post.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 18:05:50 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/16 14:43:36 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "libft.h"
#include <stdlib.h>

void	post_end_of_game(
			uint8_t winner_num)
{
	EVENT_DECL(kEventEndOfGame);
	event.info.ge.winner_num = winner_num;
	post_event(&event);
}

void	post_new_cycle(
			uint32_t new_cycle,
			int32_t last_alive_player,
			uint16_t num_live_calls)
{
	EVENT_DECL(kEventNewCycle);
	event.info.nc.cycle_num = new_cycle;
	event.info.nc.last_alive_player = last_alive_player;
	event.info.nc.num_live_calls = num_live_calls;
	post_event(&event);
}

void	post_live(
			int32_t caller_id,
			int32_t player_id,
			uint8_t player_num)
{
	EVENT_DECL(kEventLive);
	event.info.lc.caller_id = caller_id;
	event.info.lc.player_id = player_id;
	event.info.lc.player_num = player_num;
	post_event(&event);
}

void	post_aff(
			int32_t caller_id,
			char c)
{
	EVENT_DECL(kEventAff);
	event.info.af.caller_id = caller_id;
	event.info.af.c = c;
	post_event(&event);
}

void	post_player_create(
			int32_t player_id,
			uint16_t player_weight,
			uint8_t player_num,
			t_tuple name_comment_code_tuple)
{
	const size_t comment_len = ft_strlen(name_comment_code_tuple.second);

	EVENT_DECL(kEventPlayerCreate);
	event.info.plc.id = player_id;
	event.info.plc.weight = player_weight;
	event.info.plc.num = player_num;
	event.header.arb_str_len = ft_strlen(name_comment_code_tuple.first);
	event.arbitrary_string = name_comment_code_tuple.first;
	event.header.arb2_str_len = comment_len + player_weight + 1;
	event.arbitrary_string2 = malloc(event.header.arb2_str_len);
	ft_strcpy(event.arbitrary_string2, name_comment_code_tuple.second);
	event.arbitrary_string2[comment_len] = '\0';
	ft_memcpy(&event.arbitrary_string2[comment_len + 1],
			name_comment_code_tuple.third, player_weight);
	post_event(&event);
	free(event.arbitrary_string2);
}
