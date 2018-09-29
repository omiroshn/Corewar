/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_line_size.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:30:26 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:28:59 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_LINE_SIZE_H
# define OP_LINE_SIZE_H

# include <stddef.h>

struct s_op_line;

size_t	op_line_size(struct s_op_line *op_line);

#endif
