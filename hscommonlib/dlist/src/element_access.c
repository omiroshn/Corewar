/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:28:17 by hshakula          #+#    #+#             */
/*   Updated: 2018/06/20 16:17:54 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist_private.h"
#include <stddef.h>

void	*dlist_front(struct s_dlist *list)
{
	if (list->size == 0)
		return (NULL);
	return (list->begin->data);
}

void	*dlist_back(struct s_dlist *list)
{
	return (list->end->data);
}

void	*dlist_element(struct s_dlist *list, size_t index)
{
	struct s_dlist_node	*node;

	if (list->size == 0 || index >= list->size)
		return (NULL);
	node = list->begin;
	while (index)
	{
		node = node->next;
		--index;
	}
	return (node->data);
}

void	*dlist_find_if(
			struct s_dlist *list,
			t_dlist_predicate predicate,
			void *ctx)
{
	struct s_dlist_node	*node;
	void				*ret;

	if (!list->size)
		return (NULL);
	ret = NULL;
	node = list->begin;
	while (node)
	{
		if (predicate(node->data, ctx))
		{
			ret = node->data;
			break ;
		}
		node = node->next;
	}
	return (ret);
}
