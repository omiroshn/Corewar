/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:43:40 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/13 23:10:56 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "operand_input.h"
#include "param_writer.h"
#include "param_reader.h"

void	op_sti(struct s_arena *ar, struct s_process *proc)
{
	t_operand_input	input;
	int32_t			src;
	int32_t			index;

	input = parse_operand_input(&proc->pc, proc->current_op, ar->memory_pool);
	if (!input.valid)
		return ;
	src = read_param(&input.params[0], ar, proc);
	index = read_param(&input.params[1], ar, proc);
	index += read_param(&input.params[2], ar, proc);
	index %= IDX_MOD;
	write_param(src, &(t_op_param){index, kParamTypeIndirect}, ar, proc);
}
