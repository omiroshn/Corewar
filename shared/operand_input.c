/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:54:56 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:55:28 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operand_input.h"
#include "param_parser.h"
#include "op.h"
#include "scalar.h"
#include "libft.h"
#include <assert.h>

#define PARAM_MASK 0x3

static void		validate_operand_input(t_operand_input *in,
										t_operation_type op_type)
{
	const t_op	*op = g_op_tab + op_type;
	int			i;

	i = -1;
	while (++i < MAX_ARGS_NUMBER && in->valid)
	{
		if (in->params[i].valid == false)
			in->valid = false;
		if (i < op->nb_arg && valid_param_type(in->params[i].type, op->type[i]))
		{
			if (in->params[i].type == kParamTypeRegister &&
				(in->params[i].value < 0 || in->params[i].value >= REG_NUMBER))
				in->valid = false;
		}
		else if (i >= op->nb_arg)
		{
			if (in->params[i].type != kParamTypeUnknown)
				in->valid = false;
		}
		else
			in->valid = false;
	}
}

t_operand_input	parse_operand_input(
					uint8_t **mem,
					t_operation_type op_type,
					void *ground_memory)
{
	struct s_op_param	*param;
	t_operand_input		input;
	const uint8_t		param_flag = **mem;
	uint8_t				arg_code;
	int					i;

	input.valid = true;
	assert(operation_is_valid(op_type));
	++(*mem);
	i = MAX_ARGS_NUMBER;
	while (i--)
	{
		arg_code = (param_flag >> (i << 1)) & PARAM_MASK;
		param = &input.params[MAX_ARGS_NUMBER - i - 1];
		param->valid = true;
		*mem = parse_param(arg_code, make_pair(*mem, ground_memory),
								param, g_op_tab[op_type].dir_size);
	}
	validate_operand_input(&input, op_type);
	return (input);
}
