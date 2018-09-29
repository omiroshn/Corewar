/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:24:21 by Admin             #+#    #+#             */
/*   Updated: 2018/06/21 00:00:31 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist_private.h"

void				dlist_iterate(struct s_dlist *list,
									void (*iter)(void *data, void *context),
									void *context)
{
	struct s_dlist_node *begin;

	if (!list->size)
		return ;
	begin = list->begin;
	while (begin)
	{
		iter(begin->data, context);
		begin = begin->next;
	}
}

struct s_dlist_iter	dlist_iter_init(struct s_dlist *list)
{
	struct s_dlist_iter iter;

	iter.list = list;
	iter.node = list->begin;
	return (iter);
}

inline void			dlist_next(struct s_dlist_iter *iter)
{
	iter->node = iter->node->next;
}

inline void			dlist_prev(struct s_dlist_iter *iter)
{
	iter->node = iter->node->previous;
}

inline void			*dlist_iter_data(struct s_dlist_iter *iter)
{
	if (iter->node == NULL)
		return (NULL);
	return (iter->node->data);
}
