/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:36:05 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:28:48 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_LIST_H
# define OP_LIST_H

# include "dlist.h"

struct s_op_line;
struct s_label_map;

struct				s_op_list
{
	struct s_dlist		op_lines;
	struct s_label_map	*label_map;
	size_t				program_size;
};

struct s_op_list	*op_list_init(
						char *file_content,
						size_t file_size,
						const char *filename);
void				op_list_release(struct s_op_list *op_list);

#endif
