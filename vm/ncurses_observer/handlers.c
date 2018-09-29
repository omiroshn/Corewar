/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:54:35 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 13:00:42 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NCURSES_OBSERVER_IMPLEMENTATION
#include "ncurses_observer_private.h"
#include "ft_printf.h"

#include <unistd.h>

void	ncurses_end_of_game(struct s_event *event, struct s_curses *curses)
{
	int ch;

	render_last_screen(curses);
	timeout(-1);
	while (1)
	{
		ch = getch();
		if (ch != ERR)
			break ;
	}
	resetterm();
	refresh();
}

void	ncurses_check_up(struct s_event *event, struct s_curses *curses)
{
	int i;

	curses->cycles_to_die = event->info.cu.cycles_to_die;
	curses->num_checkups_wo_decrease = event->info.cu.num_checkups_wo_decrease;
	ft_memcpy(curses->previous_livebreakdown, curses->livebreakdown,
			sizeof(curses->previous_livebreakdown));
	i = -1;
	while (++i < curses->num_players)
	{
		curses->players[i].live_calls = 0;
		curses->livebreakdown[i] = 1.0 / curses->num_players;
	}
	curses->live_calls = 0;
}

void	ncurses_ui_update(struct s_event *event, struct s_curses *curses)
{
	curses->cycles_per_sec = event->info.uu.update_speed;
	curses->paused = event->info.uu.paused;
	render_info_panel(&curses->info, curses);
	wrefresh(curses->info.win);
}

void	ncurses_new_cycle(struct s_event *event, struct s_curses *curses)
{
	curses->current_cycle = event->info.nc.cycle_num;
	curses->last_alive_player = event->info.nc.last_alive_player;
	curses->num_live_calls = event->info.nc.num_live_calls;
	if (curses->current_cycle == 0)
	{
		ncurses_setup_mempool(curses);
		reset_timer(&curses->timer);
	}
	render(curses);
}

void	ncurses_proc_live(struct s_event *event, struct s_curses *curses)
{
	const struct s_event_live	*live_call = &event->info.lc;
	int							i;

	if (live_call->player_num == INVALID_PLAYER_NUM)
		return ;
	++curses->live_calls;
	++curses->players[live_call->player_num].live_calls;
	++curses->players[live_call->player_num].total_live_calls;
	i = -1;
	while (++i < curses->num_players)
	{
		curses->livebreakdown[i] =
			(double)curses->players[i].live_calls / curses->live_calls;
	}
}
