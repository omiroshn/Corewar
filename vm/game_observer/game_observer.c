/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_observer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 17:01:08 by admin             #+#    #+#             */
/*   Updated: 2018/09/16 17:01:13 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_observer.h"
#include "vm.h"

static void	gameobs_proc_live(struct s_event *event, struct s_vm *vm)
{
	if (event->info.lc.player_num != INVALID_PLAYER_NUM)
		vm->arena.life_cycle.last_alive_player = event->info.lc.player_id;
}

void		register_game_observer(struct s_vm *vm)
{
	static struct s_event_observer	obs;

	obs.ctx = vm;
	ft_memset(&obs.handlers, 0, sizeof(obs.handlers));
	obs.handlers[kEventLive] = (t_event_handler)gameobs_proc_live;
	register_observer(&obs);
}
