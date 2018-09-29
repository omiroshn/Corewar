/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 23:49:34 by admin             #+#    #+#             */
/*   Updated: 2018/09/18 23:50:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "player.h"
#include "client.h"
#include "cor_file.h"
#include "ft_printf.h"
#include "event_queue.h"
#include "tcp_event_wrapper.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static bool	recv_multicast(
				struct s_client *client,
				struct s_hs_socket *sock,
				struct sockaddr *discovery_addr,
				socklen_t *socklen)
{
	struct s_multicast_msg	br;
	int						ret;

	ret = recvfrom(sock->fd, &br, sizeof(struct s_multicast_msg), 0,
					discovery_addr, socklen);
	if (ret == sizeof(struct s_multicast_msg) &&
		br.ip[kIpv4StrMaxSize] == '\0')
	{
		if (client->verbose)
			ft_printf("Found corewar server at %s:%d\nConnecting...\n",
				br.ip, ntohs(br.port));
		return (connect_to_server(client, &br));
	}
	else
		perror(__FUNCTION__);
	return (false);
}

static const struct ip_mreq	g_mreq =
{
	.imr_multiaddr =
	{
		.s_addr = MULTICAST_ADDR
	},
	.imr_interface =
	{
		.s_addr = htonl(INADDR_ANY)
	}
};

static bool	find_server(struct s_client *client)
{
	struct sockaddr		discovery_addr;
	socklen_t			socklen;
	struct s_hs_socket	*udp_sock;

	socklen = sizeof(struct sockaddr);
	udp_sock = hs_socket(INADDR_ANY, 0, SOCK_DGRAM);
	if (!hs_sockaddr_str(&discovery_addr, MULTICAST_IP, MULTICAST_PORT))
		return (false);
	if (setsockopt(udp_sock->fd, SOL_SOCKET, SO_REUSEADDR,
							&(int){1}, sizeof(int)) < 0 ||
		bind(udp_sock->fd, &discovery_addr, socklen) < 0 ||
		setsockopt(udp_sock->fd, IPPROTO_IP, IP_ADD_MEMBERSHIP,
							&g_mreq, sizeof(g_mreq)) < 0)
	{
		perror(__FUNCTION__);
		return (false);
	}
	while (true)
	{
		if (recv_multicast(client, udp_sock, &discovery_addr, &socklen))
			break ;
	}
	hs_socket_release(udp_sock);
	return (true);
}

static void	poll_events(void)
{
	struct s_event *event;

	event = event_queue_pop();
	while (event)
	{
		post_event(event);
		if (event->header.arb_str_len)
			free(event->arbitrary_string);
		if (event->header.arb2_str_len)
			free(event->arbitrary_string2);
		free(event);
		event = event_queue_pop();
	}
}

static bool	valid_vm(struct s_vm *vm, char **err)
{
	if (vm->arena.players.size != 1)
		*err = "in case of client mode only one player must be specified";
	else
		return (true);
	return (false);
}

bool		vm_execute_client(struct s_vm *vm, char **err)
{
	struct s_client client;
	struct s_player	*player;

	if (!valid_vm(vm, err))
		return (false);
	player = dlist_front(&vm->arena.players);
	client.cor_file = player->cor_file;
	client.socket = hs_socket(INADDR_ANY, 0, SOCK_STREAM);
	client.verbose = vm->cfg.ui == kUiTypeTerminal;
	if (!client.socket)
		*err = "failed to create socket";
	else
	{
		if (find_server(&client))
		{
			tcp_event_collector_run(client.socket);
			while (tcp_event_collector_running() || !event_queue_is_empty())
				poll_events();
		}
		hs_socket_release(client.socket);
		return (true);
	}
	return (false);
}
