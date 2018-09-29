/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_writer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 21:51:00 by Admin             #+#    #+#             */
/*   Updated: 2018/09/09 12:46:33 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mempool_io.h"
#include "shift.h"
#include "param_writer.h"
#include "process.h"
#include "swap.h"
#include "vm.h"
#include <stdlib.h>

static void		write_unknown_param(
	int32_t value,
	t_op_param *param,
	struct s_arena *arena,
	struct s_process *process)
{
}

static void		write_register_param(
	int32_t value,
	t_op_param *param,
	struct s_arena *arena,
	struct s_process *process)
{
	process->registers[param->value] = value;
}

static void		write_indirect_param(
	int32_t value,
	t_op_param *param,
	struct s_arena *ar,
	struct s_process *process)
{
	void *mem;

	value = swap32(value);
	if ((process->current_op == kOperationLld ||
		process->current_op == kOperationLldi ||
		process->current_op == kOperationLfork))
	{
		mem = mempool_shift(ar->memory_pool, ar->memory_pool, param->value);
	}
	else
	{
		mem = mempool_shift(process->operand_pc,
							ar->memory_pool, param->value % IDX_MOD);
	}
	mempool_write(mem, &value, sizeof(value), ar->memory_pool);
	post_proc_write(process->owner_id, value,
					MEMPOOL_POS(mem, ar->memory_pool));
}

static const t_param_writer	g_param_writers[kParamTypesTotal] =
{
	write_unknown_param,
	write_register_param,
	write_unknown_param,
	write_indirect_param
};

void			write_param(
	int32_t value,
	t_op_param *param,
	struct s_arena *arena,
	struct s_process *process)
{
	g_param_writers[param->type](value, param, arena, process);
}
