/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:44:36 by admin             #+#    #+#             */
/*   Updated: 2018/09/16 10:54:53 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_queue.h"
#include <stdlib.h>

static struct s_event_queue	g_event_queue =
{
	.events = DLIST_INITIALIZER,
	.access_mutex = PTHREAD_MUTEX_INITIALIZER
};

bool			event_queue_is_empty(void)
{
	bool is_empty;

	pthread_mutex_lock(&g_event_queue.access_mutex);
	is_empty = g_event_queue.events.size == 0;
	pthread_mutex_unlock(&g_event_queue.access_mutex);
	return (is_empty);
}

void			event_queue_push(struct s_event *event)
{
	struct s_event	*copy;

	copy = malloc(sizeof(struct s_event));
	*copy = *event;
	pthread_mutex_lock(&g_event_queue.access_mutex);
	dlist_push_front_data(&g_event_queue.events, copy);
	pthread_mutex_unlock(&g_event_queue.access_mutex);
}

struct s_event	*event_queue_pop(void)
{
	struct s_event *ret;

	pthread_mutex_lock(&g_event_queue.access_mutex);
	ret = dlist_pop_back(&g_event_queue.events);
	pthread_mutex_unlock(&g_event_queue.access_mutex);
	return (ret);
}
