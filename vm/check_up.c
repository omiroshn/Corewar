/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:22:28 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 12:40:51 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_up.h"
#include "vm.h"
#include "scalar.h"
#include "ft_printf.h"
#include <stdlib.h>

static void	check_up_processes(struct s_arena *ar)
{
	dlist_remove_if(&ar->processes, process_is_dead, process_release, NULL);
	dlist_iterate(&ar->processes, process_reset, NULL);
}

void		check_up(struct s_arena *ar)
{
	check_up_processes(ar);
	if (ar->life_cycle.num_live_calls > NBR_LIVE ||
		ar->num_checkups_wo_decrease > MAX_CHECKS)
	{
		ar->num_checkups_wo_decrease = 0;
		ar->cycles_to_die = MAX(ar->cycles_to_die - CYCLE_DELTA, 0);
	}
	else
		++ar->num_checkups_wo_decrease;
	post_check_up(ar->cycles_to_die, ar->num_checkups_wo_decrease);
	ar->life_cycle.num_live_calls = 0;
}
