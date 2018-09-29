/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:52:36 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:52:33 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "label_map.h"
#include "dlist.h"
#include "op_line.h"
#include "op_list.h"
#include "error_logger.h"

static void			label_map_fill_hashmap(
						struct s_label_map *ret,
						struct s_dlist_iter iter,
						size_t *total_offset,
						const char *filename)
{
	struct s_op_line	*line;

	while (iter.node && ret->valid)
	{
		line = dlist_iter_data(&iter);
		if (line->type <= kOpLineTypeCmd)
		{
			dlist_next(&iter);
			continue;
		}
		if ((line->type & kOpLineTypeLabel) != 0)
		{
			if (hashmap_get(ret->map, line->c.lop.l.str) != NULL)
			{
				log_error(line->num, STACK_ERR_PAIR("label must be unique"));
				ret->valid = false;
			}
			line->c.lop.l.offset = *total_offset;
			hashmap_put(ret->map, line->c.lop.l.str, &line->c.lop.l.offset);
		}
		line->offset = *total_offset;
		*total_offset += line->size;
		dlist_next(&iter);
	}
}

struct s_label_map	*label_map_init(
						struct s_op_list *list,
						const char *filename)
{
	struct s_label_map	*ret;
	size_t				total_offset;

	ret = malloc(sizeof(struct s_label_map));
	ret->valid = true;
	ret->map = hashmap_init(list->op_lines.size, kHashmapKeyTypeStackString);
	total_offset = 0;
	label_map_fill_hashmap(ret, dlist_iter_init(&list->op_lines),
							&total_offset, filename);
	list->program_size = total_offset;
	return (ret);
}

void				label_map_release(struct s_label_map *map)
{
	if (map == NULL)
		return ;
	hashmap_destroy(map->map, NULL);
	free(map);
}

int					label_offset(struct s_label_map *map, char *label)
{
	int				ret;
	const size_t	*label_offset_ptr = hashmap_get(map->map, label);

	ret = -1;
	if (label_offset_ptr)
		ret = (int)(*label_offset_ptr);
	return (ret);
}

bool				label_resolve(
						struct s_label_map *label_map,
						t_op_arg *arg,
						size_t line_offset)
{
	const int	offset = label_offset(label_map, arg->label_str + 1);

	if (offset == -1)
		return (false);
	arg->value = offset - (int)line_offset;
	return (true);
}
