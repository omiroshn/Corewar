/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 18:32:00 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/15 19:18:40 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "player.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static struct s_event_observer	g_server_observer;

static void	send_event(struct s_event *event, struct s_server *server)
{
	const size_t	size = g_event_type_to_packet_size[event->header.type];
	size_t			arb_string_len;

	send_to_clients(server, event, size);
	arb_string_len = event->header.arb_str_len;
	if (arb_string_len)
	{
		send_to_clients(server, event->arbitrary_string, arb_string_len);
	}
	arb_string_len = event->header.arb2_str_len;
	if (arb_string_len)
	{
		send_to_clients(server, event->arbitrary_string2, arb_string_len);
	}
}

void		register_server_observer(struct s_server *server)
{
	t_event_type					type;

	g_server_observer.ctx = server;
	type = kEventsBegin;
	while (type < kEventsTotal)
	{
		g_server_observer.handlers[type] = (t_event_handler)send_event;
		++type;
	}
	register_observer(&g_server_observer);
}

void		unregister_server_observer(void)
{
	unregister_observer(&g_server_observer);
}
