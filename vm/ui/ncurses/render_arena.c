/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:45:54 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/20 17:48:10 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses_observer.h"
#include "render_arena.h"
#include "ft_printf.h"
#include "render.h"
#include "curses.h"
#include <assert.h>

static void	draw_cell(struct s_curses *curses, int i, int j)
{
	const int		x = (j * 3) + kOffsetX;
	const int		y = (i / kRowSize) + kOffsetY;
	const int		cell_id = i + j;
	struct s_cell	*cell;

	assert(cell_id < MEM_SIZE);
	cell = curses->cells + cell_id;
	if (cell->player_num != INVALID_PLAYER_NUM)
		wattron(curses->main.win, COLOR_PAIR(kPlayer1Color + cell->player_num));
	else
		wattron(curses->main.win, COLOR_PAIR(kNoMansLand));
	if (cell->rewritten)
		wattron(curses->main.win, A_BOLD);
	mvwprintw(curses->main.win, y, x, "%.2x", curses->mem_pool[i + j]);
	if (cell->rewritten)
	{
		wattroff(curses->main.win, A_BOLD);
		--cell->rewritten;
	}
	if (cell->player_num != INVALID_PLAYER_NUM)
		wattroff(curses->main.win,
			COLOR_PAIR(kPlayer1Color + cell->player_num));
	else
		wattroff(curses->main.win, COLOR_PAIR(kNoMansLand));
}

static void	render_process_pc(void *data, void *ctx)
{
	const struct s_curses			*cc = ctx;
	const struct s_curses_process	*process = data;
	const int						y = process->position / kRowSize;
	const int						x = (process->position - y * kRowSize) * 3;
	uint8_t							player_num;

	player_num = 0;
	ncurses_find_player((struct s_curses*)cc, process->owner_id, &player_num);
	wattron(cc->main.win, COLOR_PAIR(kProgram1CounterColor + player_num));
	mvwprintw(cc->main.win, y + kOffsetY, x + kOffsetX,
				"%.2x", cc->mem_pool[process->position]);
	wattroff(cc->main.win, COLOR_PAIR(kProgram1CounterColor + player_num));
}

void		render_arena(struct s_curses *curses)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		j = -1;
		while (++j < kRowSize)
		{
			draw_cell(curses, i, j);
		}
		i += kRowSize;
	}
	dlist_iterate(&curses->processes, render_process_pc, curses);
}
