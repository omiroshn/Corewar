/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:43:40 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/13 23:10:46 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "param_reader.h"
#include <operand_input.h>
#include <process.h>
#include <ft_printf.h>
#include "vm.h"

void	op_aff(struct s_arena *ar, struct s_process *proc)
{
	t_operand_input	input;
	char			c;

	input = parse_operand_input(&proc->pc, proc->current_op, ar->memory_pool);
	if (!input.valid)
		return ;
	c = read_param(&input.params[0], ar, proc) % 256;
	post_aff(proc->id, c);
}
