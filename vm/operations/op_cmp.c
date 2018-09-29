/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:43:40 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/13 23:10:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "param_reader.h"
#include <operand_input.h>
#include <process.h>
#include <ft_printf.h>
#include "vm.h"

void	op_cmp(struct s_arena *ar, struct s_process *proc)
{
	t_operand_input	input;
	int32_t			value1;
	int32_t			value2;

	input = parse_operand_input(&proc->pc, proc->current_op, ar->memory_pool);
	if (!input.valid)
		return ;
	value1 = read_param(&input.params[0], ar, proc);
	value2 = read_param(&input.params[1], ar, proc);
	proc->carry = value1 - value2;
}
