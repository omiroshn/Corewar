/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcp_event_wrapper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:42:05 by admin             #+#    #+#             */
/*   Updated: 2018/09/16 10:44:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcp_event_wrapper.h"
#include "event_queue.h"
#include "event.h"
#include "hsnet.h"
#include "libft.h"
#include "ft_printf.h"

#include <errno.h>
#include <stdio.h>
#include <pthread.h>

static pthread_t	g_collector_thread;
static bool			g_collecting_events = true;

static int	recv_event(struct s_hs_socket *sock, struct s_event *event)
{
	int				ret;
	size_t			size;

	size = g_event_type_to_packet_size[event->header.type]
											- sizeof(struct s_event_header);
	ret = recv(sock->fd, &event->info, size, 0);
	if (ret != -1)
	{
		if (event->header.arb_str_len)
		{
			event->arbitrary_string =
								ft_memalloc(event->header.arb_str_len + 1);
			ret = recv(sock->fd, event->arbitrary_string,
											event->header.arb_str_len, 0);
		}
		if (event->header.arb2_str_len)
		{
			event->arbitrary_string2 =
								ft_memalloc(event->header.arb2_str_len + 1);
			ret = hs_tcp_read(sock->fd, event->arbitrary_string2,
												event->header.arb2_str_len);
		}
	}
	return (ret);
}

void		*tcp_event_collector(void *server_socket)
{
	struct s_hs_socket	*sock;
	struct s_event		event;
	int					ret;

	sock = server_socket;
	while (g_collecting_events)
	{
		ret = recv(sock->fd, &event.header, sizeof(event.header), 0);
		if (ret != sizeof(event.header) || recv_event(sock, &event) <= 0)
		{
			if (ret == -1)
				perror("Server lost");
			else if (ret == 0)
				ft_printf("Server closed connection.\n");
			g_collecting_events = false;
			break ;
		}
		event_queue_push(&event);
		if (event.header.type == kEventEndOfGame)
			g_collecting_events = false;
	}
	return (NULL);
}

bool		tcp_event_collector_run(struct s_hs_socket *server_socket)
{
	int err;

	if ((err = pthread_create(&g_collector_thread, NULL,
							tcp_event_collector, server_socket)))
	{
		errno = err;
		perror(__FUNCTION__);
		return (false);
	}
	pthread_detach(g_collector_thread);
	return (true);
}

bool		tcp_event_collector_running(void)
{
	return (g_collecting_events);
}

void		tcp_event_collector_stop(void)
{
	g_collecting_events = false;
}
