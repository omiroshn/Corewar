/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand_input.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:54:57 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/31 16:58:46 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_INPUT_H
# define OPERAND_INPUT_H

# include "op.h"
# include "param.h"
# include <stdbool.h>

typedef struct		s_operand_input
{
	t_op_param		params[MAX_ARGS_NUMBER];
	bool			valid;
}					t_operand_input;

t_operand_input		parse_operand_input(
						uint8_t **mem,
						t_operation_type op_type,
						void *ground_memory);

#endif
