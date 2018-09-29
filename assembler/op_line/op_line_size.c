/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_line_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:30:25 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/05 16:31:40 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_line_size.h"
#include "op_line.h"

static const size_t	g_param_size[kParamTypesTotal] =
{
	0, 1, 0, 2
};

size_t	op_line_size(struct s_op_line *op_line)
{
	size_t		ret;
	int			arg_n;
	t_op_arg	*arg;
	const t_op	*op;

	ret = 0;
	if ((op_line->type & kOpLineTypeOperation) != 0)
	{
		ret = 1;
		op = g_op_tab + op_line->c.lop.o.type;
		if (op->encoded_input)
			ret += 1;
		arg_n = -1;
		while (++arg_n < op_line->c.lop.o.args.num_args)
		{
			arg = op_line->c.lop.o.args.args + arg_n;
			if (arg->type == kParamTypeDirect)
				ret += op->dir_size;
			else
				ret += g_param_size[arg->type];
		}
	}
	return (ret);
}
