/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:30:50 by hshakula          #+#    #+#             */
/*   Updated: 2018/06/21 00:00:51 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist_private.h"

void					dlist_merge(struct s_dlist *dst, struct s_dlist *src)
{
	dst->end->next = src->begin;
	src->begin->previous = dst->end;
}

void					dlist_remove_if(struct s_dlist *list,
										t_dlist_predicate predicate,
										void (*del)(void *data),
										void *context)
{
	struct s_dlist_node *begin;
	struct s_dlist_node *node_to_free;

	begin = list->begin;
	while (begin)
	{
		if (predicate(begin->data, context))
		{
			node_to_free = begin;
			begin = remove_node(node_to_free, del, list);
			--list->size;
		}
		else
			begin = begin->next;
	}
	if (list->size == 0)
	{
		list->begin = NULL;
		list->end = NULL;
	}
}
