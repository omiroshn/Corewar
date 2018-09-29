/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:43:40 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/13 23:06:49 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "swap.h"
#include "shift.h"
#include "mempool_io.h"

void	op_zjmp(struct s_arena *arena, struct s_process *process)
{
	int16_t				address;

	process->pc = mempool_read(&address, process->pc,
								sizeof(address), arena->memory_pool);
	if (process->carry)
	{
		process->pc = mempool_shift(process->operand_pc, arena->memory_pool,
									((int16_t)swap16(address)) % IDX_MOD);
	}
}
