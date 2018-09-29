/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:28:27 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/16 14:32:38 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "dlist.h"
#include "network_common.h"

size_t	g_event_type_to_packet_size[kEventsTotal] =
{
	sizeof(struct s_event_header) + sizeof(struct s_event_game_end),
	sizeof(struct s_event_header) + sizeof(struct s_event_proc_write),
	sizeof(struct s_event_header) + sizeof(struct s_event_proc_move),
	sizeof(struct s_event_header) + sizeof(struct s_event_proc_create),
	sizeof(struct s_event_header) + sizeof(struct s_event_proc_death),
	sizeof(struct s_event_header) + sizeof(struct s_event_new_cycle),
	sizeof(struct s_event_header) + sizeof(struct s_event_live),
	sizeof(struct s_event_header) + sizeof(struct s_event_aff),
	sizeof(struct s_event_header) + sizeof(struct s_event_player_create)
};

char	*g_event_type_to_string[kEventsTotal] =
{
	"EndOfGame",
	"ProcessWrite",
	"ProcessMove",
	"ProcessCreate",
	"ProcessDeath",
	"NewCycle",
	"Live",
	"Aff",
	"PlayerCreate"
};

static struct s_dlist	g_observers = DLIST_INITIALIZER;

void		register_observer(struct s_event_observer *observer)
{
	dlist_push_back_data(&g_observers, observer);
}

static bool	pointer_predicate(void *lhs, void *rhs)
{
	return (lhs == rhs);
}

void		unregister_observer(struct s_event_observer *observer)
{
	dlist_remove_if(&g_observers, pointer_predicate, NULL, observer);
}

static void	notify_observer(void *observer_ptr, void *event_ptr)
{
	struct s_event_observer	*observer;
	struct s_event			*event;

	observer = observer_ptr;
	event = event_ptr;
	if (observer->handlers[event->header.type])
		observer->handlers[event->header.type](event, observer->ctx);
}

void		post_event(struct s_event *event)
{
	dlist_iterate(&g_observers, notify_observer, event);
}
