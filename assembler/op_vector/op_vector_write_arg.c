/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vector_write_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:26:49 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:27:21 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_vector_write_arg.h"
#include "swap.h"
#include "op_vector.h"

bool	write_arg_unknown(
			struct s_op_vector *vector,
			t_op_arg *arg,
			const t_op *op)
{
	return (false);
}

bool	write_arg_register(
			struct s_op_vector *vector,
			t_op_arg *arg,
			const t_op *op)
{
	const int8_t byte = arg->value;

	return (op_vector_write(vector, &byte, 1));
}

bool	write_arg_direct(
			struct s_op_vector *vector,
			t_op_arg *arg,
			const t_op *op)
{
	int16_t		word;
	int32_t		dword;

	if (op->dir_size == 2)
	{
		word = swap16((uint16_t)arg->value);
		op_vector_write(vector, &word, 2);
	}
	else if (op->dir_size == 4)
	{
		dword = swap32(arg->value);
		op_vector_write(vector, &dword, 4);
	}
	else
		return (false);
	return (true);
}

bool	write_arg_indirect(
			struct s_op_vector *vector,
			t_op_arg *arg,
			const t_op *op)
{
	const int16_t word = swap16((uint16_t)arg->value);

	return (op_vector_write(vector, &word, 2));
}

static const t_op_vector_arg_writer	g_op_vector_arg_writers[kParamTypesTotal] =
{
	write_arg_unknown,
	write_arg_register,
	write_arg_direct,
	write_arg_indirect
};

bool	op_vector_write_arg(
			struct s_op_vector *vector,
			t_op_arg *arg,
			t_operation_type op_type)
{
	const t_op	*op = g_op_tab + op_type;

	return (g_op_vector_arg_writers[arg->type](vector, arg, op));
}
