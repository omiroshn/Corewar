/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:59:27 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/16 18:05:41 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "vm.h"
#include "shift.h"
#include "operations/operations.h"

bool				process_is_dead(void *process, void *arena)
{
	return (((struct s_process*)process)->is_alive == false);
}

void				process_reset(void *process, void *ctx)
{
	((struct s_process*)process)->is_alive = false;
}

void				process_cycle_update(
						struct s_process *proc,
						struct s_arena *arena)
{
	t_operation_type	operand;

	if (proc->current_op == kOperationNone)
	{
		post_proc_move(proc->id, (uint16_t)(proc->pc - arena->memory_pool));
		operand = (int8_t)(*proc->pc) - 1;
		if (operation_is_valid(operand))
		{
			proc->current_op = operand;
			proc->operand_pc = proc->pc;
			proc->num_cycles_to_execution = g_op_tab[operand].cycle_cost - 1;
		}
		else
			proc->operand_pc = proc->pc;
		proc->pc = mempool_shift(proc->pc, arena->memory_pool, 1);
	}
	else
	{
		if (--proc->num_cycles_to_execution == 0)
		{
			g_op_functions[proc->current_op](arena, proc);
			proc->current_op = kOperationNone;
		}
	}
}
