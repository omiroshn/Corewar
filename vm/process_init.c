/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 18:03:26 by admin             #+#    #+#             */
/*   Updated: 2018/09/16 18:05:12 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "libft.h"
#include "vm.h"
#include "shift.h"

#include <stdlib.h>

static int32_t		g_process_id = 0;

struct s_process	*process_init(
						void *pc,
						int32_t player_id,
						struct s_arena *arena)
{
	struct s_process *ret;

	if ((ret = ft_memalloc(sizeof(struct s_process))) == NULL)
		return (NULL);
	ret->registers[1] = player_id;
	ret->current_op = kOperationNone;
	ret->pc = pc;
	ret->id = g_process_id++;
	ret->owner_id = player_id;
	post_proc_create(player_id, ret->id, MEMPOOL_POS(pc, arena->memory_pool));
	return (ret);
}

struct s_process	*process_copy(
						struct s_process *src,
						size_t pc_offset,
						struct s_arena *arena)
{
	struct s_process *copy;

	copy = malloc(sizeof(struct s_process));
	*copy = *src;
	copy->pc = mempool_shift(src->operand_pc, arena->memory_pool, pc_offset);
	copy->current_op = kOperationNone;
	copy->is_alive = false;
	copy->id = g_process_id++;
	copy->owner_id = src->owner_id;
	post_proc_create(src->owner_id, copy->id,
					MEMPOOL_POS((void*)copy->pc, arena->memory_pool));
	return (copy);
}

void				process_release(void *process_ptr)
{
	struct s_process *process;

	process = process_ptr;
	post_proc_death(process->id);
	free(process);
}
