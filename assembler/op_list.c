/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:36:04 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/04 11:47:58 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_list.h"
#include "op_line.h"
#include "libft.h"
#include "label_map.h"
#include "error_logger.h"
#include "error_logger_print.h"
#include <stdlib.h>

static bool			op_list_init_lines(
						char *file_content,
						size_t file_size,
						const char *filename,
						struct s_dlist *lines)
{
	bool				valid;
	struct s_op_line	*op_line;
	size_t				line_offset;
	size_t				line_size;
	int					line_num;

	valid = true;
	*lines = DLIST_INITIALIZER;
	line_offset = 0;
	line_num = 1;
	while (line_offset < file_size)
	{
		line_size = ft_strclen(file_content + line_offset, '\n');
		op_line = op_line_init(file_content + line_offset, line_num, filename);
		if (op_line == NULL)
			valid = false;
		else if (op_line->str != NULL)
			dlist_push_back_data(lines, op_line);
		line_offset += line_size + 1;
		line_num++;
	}
	return (valid);
}

struct s_op_list	*op_list_init(
						char *filecontent,
						size_t filesize,
						const char *filename)
{
	struct s_op_list *ret;

	ret = malloc(sizeof(struct s_op_list));
	ft_memset(ret, 0, sizeof(struct s_op_list));
	if (!op_list_init_lines(filecontent, filesize, filename, &ret->op_lines) ||
		(ret->label_map = label_map_init(ret, filename)) == NULL ||
		ret->label_map->valid == false)
	{
		op_list_release(ret);
		ret = NULL;
	}
	return (ret);
}

void				op_list_release(struct s_op_list *op_list)
{
	label_map_release(op_list->label_map);
	dlist_release(&op_list->op_lines, op_line_release, true);
	free(op_list);
}
