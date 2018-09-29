/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vector_write_arg.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:26:50 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:28:20 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_VECTOR_WRITE_ARG_H
# define OP_VECTOR_WRITE_ARG_H

# include "token_parser_args.h"

struct s_op_vector;

typedef bool	(*t_op_vector_arg_writer)(
				struct s_op_vector *vector,
				t_op_arg *arg,
				const t_op *op);

bool	op_vector_write_arg(
			struct s_op_vector *vector,
			t_op_arg *arg,
			t_operation_type op_type);

#endif
