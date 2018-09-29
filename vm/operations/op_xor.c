/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:43:40 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/13 23:11:15 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "operand_input.h"
#include "param_writer.h"
#include "param_reader.h"

void	op_xor(struct s_arena *ar, struct s_process *proc)
{
	t_operand_input	input;
	int32_t			value;

	input = parse_operand_input(&proc->pc, proc->current_op, ar->memory_pool);
	if (!input.valid)
		return ;
	value = read_param(&input.params[0], ar, proc);
	value ^= read_param(&input.params[1], ar, proc);
	write_param(value, &input.params[2], ar, proc);
	proc->carry = value == 0;
}
