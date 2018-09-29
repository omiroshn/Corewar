/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:43:40 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/13 23:46:27 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "mempool_io.h"
#include "swap.h"

void	op_fork(struct s_arena *arena, struct s_process *process)
{
	int16_t				offset;
	struct s_process	*copy;

	process->pc = mempool_read(&offset, process->pc, sizeof(offset),
								arena->memory_pool);
	copy = process_copy(process, ((int16_t)swap16(offset)) % IDX_MOD, arena);
	dlist_push_front_data(&arena->processes, copy);
}
