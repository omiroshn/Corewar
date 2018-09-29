/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_line.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:26:37 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/05 16:27:34 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_LINE_H
# define OP_LINE_H

# include "op.h"
# include "param.h"
# include "op_line_cmd.h"
# include "op_line_label.h"
# include "token_parser.h"

# include <stddef.h>

typedef enum		e_op_line_type
{
	kOpLineTypeUnknown = 0,
	kOpLineTypeCmd = 1,
	kOpLineTypeOperation = 2,
	kOpLineTypeLabel = 4,
	kOpLineTypeLabeledOperation = kOpLineTypeOperation | kOpLineTypeLabel,
}					t_op_line_type;

struct				s_op_line_operation
{
	t_op_args			args;
	t_operation_type	type;
};

struct				s_op_line_labeled
{
	struct s_op_line_operation	o;
	struct s_op_line_label		l;
};

union				u_op_line_content
{
	struct s_op_line_cmd		cmd;
	struct s_op_line_operation	op;
	struct s_op_line_labeled	lop;
};

struct				s_op_line
{
	union u_op_line_content	c;
	char					*str;
	size_t					size;
	size_t					offset;
	int						num;
	t_op_line_type			type;
};

struct s_op_line	*op_line_init(
						char *file_line,
						int num,
						const char *filename);
void				op_line_release(void *op_line_ptr);

#endif
