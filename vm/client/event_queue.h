/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_queue.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:44:37 by admin             #+#    #+#             */
/*   Updated: 2018/09/16 10:55:18 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_QUEUE_H
# define EVENT_QUEUE_H

# include "event.h"
# include "dlist.h"

# include <pthread.h>

struct			s_event_queue
{
	struct s_dlist	events;
	pthread_mutex_t	access_mutex;
};

bool			event_queue_is_empty(void);

void			event_queue_push(struct s_event *event);

/*
**	Returned pointer must be freed by caller
*/

struct s_event	*event_queue_pop(void);

#endif
