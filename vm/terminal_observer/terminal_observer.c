/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_observer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:40:36 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 12:46:12 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TERMINAL_OBSERVER_IMPLEMENTATION
#include "terminal_observer_private.h"
#include "event.h"
#include "op.h"

static struct s_event_observer	g_obs;
extern char	g_player_num_to_name[MAX_PLAYERS][PROG_NAME_LENGTH];

void		register_terminal_observer(bool verbose)
{
	static struct s_termobs_desc	desc;

	desc.verbose = verbose;
	g_obs.ctx = &desc;
	ft_memset(g_player_num_to_name, 0, sizeof(g_player_num_to_name));
	ft_memset(&g_obs.handlers, 0, sizeof(g_obs.handlers));
	g_obs.handlers[kEventEndOfGame] = (t_event_handler)termobs_end_of_game;
	g_obs.handlers[kEventProcessWrite] = (t_event_handler)termobs_proc_write;
	g_obs.handlers[kEventProcessMove] = (t_event_handler)termobs_proc_move;
	g_obs.handlers[kEventProcessCreate] = (t_event_handler)termobs_proc_create;
	g_obs.handlers[kEventProcessDeath] = (t_event_handler)termobs_proc_death;
	g_obs.handlers[kEventNewCycle] = (t_event_handler)termobs_new_cycle;
	g_obs.handlers[kEventLive] = (t_event_handler)termobs_proc_live;
	g_obs.handlers[kEventAff] = (t_event_handler)termobs_aff;
	g_obs.handlers[kEventPlayerCreate] = (t_event_handler)termobs_player_create;
	register_observer(&g_obs);
}

void		unregister_terminal_observer(void)
{
	unregister_observer(&g_obs);
}
