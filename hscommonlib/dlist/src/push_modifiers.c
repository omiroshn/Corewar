/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:29:01 by Admin             #+#    #+#             */
/*   Updated: 2018/07/27 23:23:11 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist_private.h"

void					dlist_push_back_data(struct s_dlist *lst, void *data)
{
	dlist_push_back_node(lst, dlist_node_new(data));
}

void					dlist_push_front_data(struct s_dlist *lst, void *data)
{
	dlist_push_front_node(lst, dlist_node_new(data));
}

void					dlist_push_back_node(struct s_dlist *list,
											struct s_dlist_node *new_node)
{
	if (list->size == 0)
	{
		list->begin = new_node;
		list->end = new_node;
	}
	else
	{
		new_node->previous = list->end;
		new_node->next = NULL;
		list->end->next = new_node;
		list->end = new_node;
	}
	++list->size;
}

void					dlist_push_front_node(struct s_dlist *list,
											struct s_dlist_node *new_node)
{
	if (list->size == 0)
	{
		list->begin = new_node;
		list->end = new_node;
	}
	else
	{
		new_node->previous = NULL;
		new_node->next = list->begin;
		list->begin->previous = new_node;
		list->begin = new_node;
	}
	++list->size;
}

void					dlist_insert_data(struct s_dlist_iter *iter,
											void *data)
{
	struct s_dlist_node *new_node;

	new_node = dlist_node_new(data);
	new_node->previous = iter->node->previous;
	new_node->next = iter->node;
	if (iter->node->previous)
		iter->node->previous->next = new_node;
	iter->node->previous = new_node;
	++iter->list->size;
}
