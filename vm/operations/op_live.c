/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:43:40 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/13 23:06:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <process.h>
#include <dlist.h>
#include "vm.h"
#include "swap.h"
#include "cor_file.h"
#include "ft_printf.h"
#include "mempool_io.h"

void	op_live(struct s_arena *arena, struct s_process *process)
{
	int32_t				player_id;
	struct s_player		*pl;

	arena->life_cycle.num_live_calls++;
	process->is_alive = true;
	process->pc = mempool_read(&player_id, process->pc, sizeof(player_id),
							arena->memory_pool);
	player_id = swap32(player_id);
	pl = hashmap_get(arena->player_map, &player_id);
	post_live(process->id, player_id, pl ? pl->num : INVALID_PLAYER_NUM);
}
