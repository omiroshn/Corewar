/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 00:01:02 by Admin             #+#    #+#             */
/*   Updated: 2018/06/21 00:01:20 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist_private.h"

void				*dlist_pop_back(struct s_dlist *list)
{
	struct s_dlist_node	*pop_node;
	void				*data;

	data = NULL;
	if (list->size)
	{
		data = list->end->data;
		pop_node = list->end;
		if (list->end->previous)
		{
			list->end = list->end->previous;
			list->end->next = NULL;
		}
		free(pop_node);
		--list->size;
		if (list->size == 0)
		{
			list->begin = NULL;
			list->end = NULL;
		}
	}
	return (data);
}

void				*dlist_pop_front(struct s_dlist *list)
{
	struct s_dlist_node	*pop_node;
	void				*data;

	data = NULL;
	if (list->size)
	{
		data = list->begin->data;
		pop_node = list->begin;
		if (list->begin->next)
		{
			list->begin = list->begin->next;
			list->begin->previous = NULL;
		}
		free(pop_node);
		--list->size;
	}
	return (data);
}

struct s_dlist_node	*remove_node(
						struct s_dlist_node *node,
						void (*del)(void *data),
						struct s_dlist *list)
{
	struct s_dlist_node *ret;

	ret = NULL;
	if (node->previous)
	{
		node->previous->next = node->next;
		ret = node->previous;
	}
	else
		list->begin = node->next;
	if (node->next)
	{
		ret = node->next;
		node->next->previous = node->previous;
	}
	else
		list->end = node->previous;
	if (del != NULL)
		del(node->data);
	free(node);
	return (ret);
}

void				*dlist_pop(struct s_dlist_iter *iter)
{
	void *data;

	if (iter->node == NULL)
		return (NULL);
	data = iter->node->data;
	iter->node = remove_node(iter->node, NULL, iter->list);
	iter->list->size--;
	return (data);
}
