/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 17:49:41 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/13 23:12:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mempool_io.h"
#include "shift.h"
#include "param_reader.h"
#include "process.h"
#include "swap.h"
#include "vm.h"
#include <stdlib.h>

static int32_t	read_unknown_param(
					t_op_param *param,
					struct s_arena *arena,
					struct s_process *process)
{
	return (0);
}

static int32_t	read_register_param(
					t_op_param *param,
					struct s_arena *arena,
					struct s_process *process)
{
	return (process->registers[param->value]);
}

static int32_t	read_direct_param(
					t_op_param *param,
					struct s_arena *arena,
					struct s_process *process)
{
	return (param->value);
}

static int32_t	read_indirect_param(
					t_op_param *param,
					struct s_arena *ar,
					struct s_process *process)
{
	int32_t	ret;
	int32_t	mem_offset;
	int32_t	*mem;

	if (process->current_op == kOperationLld ||
		process->current_op == kOperationLldi ||
		process->current_op == kOperationLfork)
	{
		mem = mempool_shift(ar->memory_pool, ar->memory_pool, param->value);
	}
	else
	{
		mem_offset = param->value % IDX_MOD;
		mem = mempool_shift(process->operand_pc, ar->memory_pool, mem_offset);
	}
	mempool_read(&ret, mem, sizeof(ret), ar);
	return (swap32(ret));
}

static const t_param_reader	g_param_readers[kParamTypesTotal] =
{
	read_unknown_param,
	read_register_param,
	read_direct_param,
	read_indirect_param
};

int32_t			read_param(
					t_op_param *param,
					struct s_arena *arena,
					struct s_process *process)
{
	return (g_param_readers[param->type](param, arena, process));
}
