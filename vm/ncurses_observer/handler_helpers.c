/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:57:49 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 13:02:47 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NCURSES_OBSERVER_IMPLEMENTATION
#include "ncurses_observer_private.h"
#include "shift.h"

void					ncurses_cell_update(
							uint16_t offset,
							uint16_t size,
							uint8_t player_num,
							struct s_curses *curses)
{
	while (size--)
	{
		curses->cells[offset].player_num = player_num;
		curses->cells[offset].rewritten = kBacklightDuration;
		offset = cyclic_shift_mem(offset, MEM_SIZE, 1);
	}
}

void					ncurses_setup_mempool(struct s_curses *curses)
{
	struct s_curses_player	*player;
	const int				offset = MEM_SIZE / curses->num_players;
	int						player_offset;
	void					*pool_ptr;
	int						i;

	i = -1;
	while (++i < curses->num_players)
	{
		player = curses->players + i;
		player_offset = offset * i;
		pool_ptr = curses->mem_pool + player_offset;
		ft_memcpy(pool_ptr, player->code, player->weight);
		ncurses_cell_update(player_offset, player->weight, i, curses);
	}
	i = -1;
	while (++i < MEM_SIZE)
		curses->cells[i].rewritten = 0;
	i = -1;
	while (++i < curses->num_players)
		curses->previous_livebreakdown[i] = 1.0 / curses->num_players;
	ft_memcpy(curses->livebreakdown, curses->previous_livebreakdown,
				sizeof(curses->previous_livebreakdown));
}

struct s_curses_player	*ncurses_find_player(
							struct s_curses *curses,
							int32_t id,
							uint8_t *num)
{
	struct s_curses_player	*player;
	uint8_t					i;

	player = NULL;
	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (curses->players[i].id == id)
		{
			player = curses->players + i;
			break ;
		}
		++i;
	}
	if (player && num)
		*num = i;
	return (player);
}
