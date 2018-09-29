/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 20:11:48 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 12:47:00 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TERMINAL_OBSERVER_IMPLEMENTATION
#include "terminal_observer_private.h"
#include "ft_printf.h"
#include "cor_file.h"
#include "event.h"
#include "dlist.h"

void	termobs_proc_move(struct s_event *event, struct s_termobs_desc *desc)
{
	if (desc->verbose)
	{
		ft_printf("Process #%d moved to %hd\n",
				event->info.mv.proc_id, event->info.mv.position);
	}
}

void	termobs_proc_create(struct s_event *event, struct s_termobs_desc *desc)
{
	if (desc->verbose)
	{
		ft_printf("Player %d new process created process %d at %hd\n",
					event->info.pc.player_id, event->info.pc.proc_id,
					event->info.pc.position);
	}
}

void	termobs_proc_death(struct s_event *event, struct s_termobs_desc *desc)
{
	if (desc->verbose)
	{
		ft_printf("Process #%d passed away\n", event->info.pd.proc_id);
	}
}

void	termobs_proc_write(struct s_event *event, struct s_termobs_desc *desc)
{
	if (desc->verbose)
	{
		ft_printf("Process of player #%d wrote %#.8x at %hd\n",
			event->info.wr.master_id, event->info.wr.value,
			event->info.wr.position);
	}
}

void	termobs_aff(struct s_event *event, struct s_termobs_desc *desc)
{
	if (desc->verbose)
		ft_printf("Aff: %c\n", event->info.af.c);
}
