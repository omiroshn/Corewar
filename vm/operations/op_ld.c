/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:43:40 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/13 23:10:54 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "param_reader.h"
#include "param_writer.h"
#include "vm.h"
#include "operand_input.h"

void	op_ld(struct s_arena *ar, struct s_process *proc)
{
	t_operand_input	input;
	int32_t			src;

	input = parse_operand_input(&proc->pc, proc->current_op, ar->memory_pool);
	if (!input.valid)
		return ;
	src = read_param(&input.params[0], ar, proc);
	write_param(src, &input.params[1], ar, proc);
	proc->carry = src == 0;
}
