/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_observer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:54:00 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 12:59:41 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NCURSES_OBSERVER_IMPLEMENTATION
#include "ncurses_observer_private.h"
#include "event.h"
#include "libft.h"
#include "curses.h"

static struct s_event_observer	g_obs;
static struct s_curses			g_curses;

void		register_ncurses_observer(void)
{
	if (!curses_init(&g_curses))
		return ;
	g_obs.ctx = &g_curses;
	ft_memset(&g_obs.handlers, 0, sizeof(g_obs.handlers));
	g_obs.handlers[kEventEndOfGame] = (t_event_handler)ncurses_end_of_game;
	g_obs.handlers[kEventPlayerCreate] = (t_event_handler)ncurses_player_create;
	g_obs.handlers[kEventLive] = (t_event_handler)ncurses_proc_live;
	g_obs.handlers[kEventProcessDeath] = (t_event_handler)ncurses_proc_death;
	g_obs.handlers[kEventProcessCreate] = (t_event_handler)ncurses_proc_create;
	g_obs.handlers[kEventProcessMove] = (t_event_handler)ncurses_proc_move;
	g_obs.handlers[kEventProcessWrite] = (t_event_handler)ncurses_proc_write;
	g_obs.handlers[kEventNewCycle] = (t_event_handler)ncurses_new_cycle;
	g_obs.handlers[kEventCheckUp] = (t_event_handler)ncurses_check_up;
	g_obs.handlers[kEventUiUpdate] = (t_event_handler)ncurses_ui_update;
	register_observer(&g_obs);
}

void		unregister_ncurses_observer(void)
{
	unregister_observer(&g_obs);
	curses_deinit(&g_curses);
}
