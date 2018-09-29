/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 20:46:34 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 12:52:41 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TERMINAL_OBSERVER_IMPLEMENTATION
#include "terminal_observer_private.h"
#include "ft_printf.h"
#include "event.h"
#include "libft.h"
#include "op.h"

char	g_player_num_to_name[MAX_PLAYERS][PROG_NAME_LENGTH];

void	termobs_new_cycle(
			struct s_event *event,
			struct s_termobs_desc *desc)
{
	if (desc->verbose)
		ft_printf("Cycle #%u begins\n", event->info.nc.cycle_num);
}

void	termobs_end_of_game(
			struct s_event *event,
			struct s_termobs_desc *desc)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
				event->info.ge.winner_num + 1,
				g_player_num_to_name[event->info.ge.winner_num]);
}

void	termobs_player_create(
			struct s_event *event,
			struct s_termobs_desc *desc)
{
	const struct s_event_player_create	*player = &event->info.plc;
	static int							num_introduced_players = 0;

	if (num_introduced_players++ == 0)
		ft_printf("Introducing contestants...\n");
	ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
		player->num + 1, player->weight,
		event->arbitrary_string,
		event->arbitrary_string2);
	ft_strcpy(g_player_num_to_name[player->num], event->arbitrary_string);
}

void	termobs_proc_live(
			struct s_event *event,
			struct s_termobs_desc *desc)
{
	if (event->info.lc.player_num != INVALID_PLAYER_NUM)
	{
		ft_printf("A process shows that player %d (%s) is alive\n",
			event->info.lc.player_num,
			g_player_num_to_name[event->info.lc.player_num]);
	}
}
