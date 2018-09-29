/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:28:17 by hshakula          #+#    #+#             */
/*   Updated: 2018/07/29 15:37:42 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist_private.h"
#include <pthread.h>

struct s_dlist_node		*dlist_node_new(void *data)
{
	struct s_dlist_node *new_node;

	new_node = malloc(sizeof(struct s_dlist_node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

struct s_dlist			*dlist_new(void)
{
	struct s_dlist *list;

	list = malloc(sizeof(struct s_dlist));
	list->begin = NULL;
	list->end = NULL;
	list->size = 0;
	return (list);
}

bool					true_predicate(void *data, void *context)
{
	(void)data;
	(void)context;
	return (true);
}

void					dlist_release(struct s_dlist *dlist,
										void (*del)(void *data),
										bool dlist_stack_ptr)
{
	if (dlist->size)
		dlist_remove_if(dlist, true_predicate, del, NULL);
	if (dlist_stack_ptr == false)
		free(dlist);
}
