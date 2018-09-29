/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:06:30 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/20 15:02:37 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "livebreakdown.h"
#include "render_arena.h"
#include "ft_printf.h"
#include "render.h"
#include "curses.h"
#include "libft.h"
#include "dlist.h"
#include <assert.h>

void		draw_canvas(struct s_win *win)
{
	const int	h = win->h;
	const int	w = win->w;
	int			i;
	int			j;

	wattron(win->win, COLOR_PAIR(kCanvasColor));
	i = -1;
	while (++i <= h && (j = -1))
	{
		while (++j <= w)
		{
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
				mvwprintw(win->win, i, j, "%c", ' ');
		}
	}
	wattroff(win->win, COLOR_PAIR(kCanvasColor));
}

void		render_info_panel(struct s_win *panel, struct s_curses *curses)
{
	struct s_curses_player	*player;
	int						line_num;
	int						i;

	wattron(panel->win, A_BOLD);
	line_num = 0;
	mvwprintw(panel->win, line_num += 2, 3, "** %s ** ", curses->paused ? "PAUSED" : "RUNNING");
	mvwprintw(panel->win, line_num += 2, 3, "Cycles/second : %-4d", curses->cycles_per_sec);
	mvwprintw(panel->win, line_num += 2, 3, "Cycle : %d", curses->current_cycle);
	mvwprintw(panel->win, line_num += 2, 3, "Processes : %-4d", curses->processes.size);
	i = -1;
	line_num += 2;
	while (++i < curses->num_players)
	{
		player = curses->players + i;
		wattron(panel->win, COLOR_PAIR(kPlayer1Color + i));
		mvwprintw(panel->win, line_num++, 3, "Player %d : %s", player->id, player->name);
		mvwprintw(panel->win, line_num++, 5, "Last live : %d", player->total_live_calls);
		mvwprintw(panel->win, line_num++, 5, "Lives in current period : %d", player->live_calls);
		wattroff(panel->win, COLOR_PAIR(kPlayer1Color + i));
		++line_num;
	}
	wattroff(panel->win, A_BOLD);
}

void		draw_info_breakdown(struct s_win *window, struct s_curses *curses)
{
	mvwprintw(window->win, 27, 3, "Live breakdown for current period :");
	draw_live_breakdown(window, curses, 28, curses->livebreakdown);
	mvwprintw(window->win, 30, 3, "Live breakdown for last period :");
	draw_live_breakdown(window, curses, 31, curses->previous_livebreakdown);
	wattron(window->win, A_BOLD);
	mvwprintw(window->win, 35, 3, "Num live calls in check up : %d", curses->num_live_calls);
	mvwprintw(window->win, 36, 3, "Cycles to Die : %-4d", curses->cycles_to_die);
	mvwprintw(window->win, 37, 3, "Number of check ups w/o decrease : %d", curses->num_checkups_wo_decrease);
	mvwprintw(window->win, 38, 3, "Last alive player : %d", curses->last_alive_player);
	wattroff(window->win, A_BOLD);
}

void		draw_press_key(struct s_win *window, struct s_curses *curses)
{
	wattron(window->win, A_BOLD);
	mvwprintw(window->win, 69, 40, P);
	mvwprintw(window->win, 70, 40, R);
	mvwprintw(window->win, 71, 40, E);
	mvwprintw(window->win, 72, 40, S);
	mvwprintw(window->win, 73, 40, SS);
	mvwprintw(window->win, 74, 40, K);
	mvwprintw(window->win, 75, 40, EE);
	mvwprintw(window->win, 76, 40, Y);
	wattroff(window->win, A_BOLD);
}

void		render_last_screen(struct s_curses *curses)
{
	draw_canvas(&curses->main);
	draw_canvas(&curses->info);
	render_info_panel(&curses->info, curses);
	draw_info_breakdown(&curses->info, curses);
	draw_press_key(&curses->main, curses);
	render_arena(curses);
	wrefresh(curses->main.win);
	wrefresh(curses->info.win);
}

void		render(struct s_curses *curses)
{
	draw_canvas(&curses->main);
	draw_canvas(&curses->info);
	render_info_panel(&curses->info, curses);
	draw_info_breakdown(&curses->info, curses);
	render_arena(curses);
	wrefresh(curses->main.win);
	wrefresh(curses->info.win);
}
