/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser_args.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:53:59 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/04 17:55:20 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_PARSER_ARGS_H
# define TOKEN_PARSER_ARGS_H

# include "op.h"
# include "param.h"

typedef struct		s_op_arg
{
	bool			valid;
	t_param_type	type;
	bool			label;
	char			*label_str;
	int32_t			value;
}					t_op_arg;

typedef struct		s_op_args
{
	t_op_arg		args[MAX_ARGS_NUMBER];
	int				num_args;
	bool			valid;
}					t_op_args;

/*
**	err is non heap string only
*/

t_op_args			token_parse_op_args(
						char *token,
						t_operation_type op_type,
						char **err);

uint8_t				codage_byte(t_op_args *args);

#endif
