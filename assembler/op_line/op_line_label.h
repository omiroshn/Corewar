/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_line_label.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:23:35 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:29:12 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_LINE_LABEL_H
# define OP_LINE_LABEL_H

# include <stddef.h>

struct s_op_line;

struct	s_op_line_label
{
	char	*str;
	size_t	offset;
};

char	*op_line_parse_label(struct s_op_line *op_line);

#endif
