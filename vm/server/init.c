/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:50:03 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/18 23:35:43 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include "op.h"
#include "dlist.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct s_client_info	*client_info(int fd, struct sockaddr *sockaddr)
{
	struct s_client_info	*ret;

	ret = ft_memalloc(sizeof(struct s_client_info));
	ret->sockaddr = *sockaddr;
	ret->fd = fd;
	ret->buf = malloc(kRecvBufSize);
	return (ret);
}

void					client_info_release(void *client_ptr)
{
	struct s_client_info *client;

	client = client_ptr;
	close(client->fd);
	free(client->buf);
	free(client->name);
	free(client_ptr);
}

static bool				init_server_info(struct s_server *server)
{
	struct sockaddr_in	sin;
	socklen_t			len;
	char				*ip;

	len = sizeof(sin);
	ip = hsnet_get_ip(AF_INET, "en0");
	if (ip == NULL ||
		getsockname(server->socket->fd, (struct sockaddr*)&sin, &len) == -1)
	{
		perror(__FUNCTION__);
		return (false);
	}
	ft_memset(server->multicast_msg.ip, 0, sizeof(server->multicast_msg.ip));
	ft_strcpy(server->multicast_msg.ip, ip);
	server->multicast_msg.port = ntohs(sin.sin_port);
	free(ip);
	return (true);
}

struct s_server			*server_init(void)
{
	struct s_server		*ret;

	ret = ft_memalloc(sizeof(struct s_server));
	ret->socket = hs_socket(INADDR_ANY, 0, SOCK_STREAM);
	if (!ret->socket ||
		bind(ret->socket->fd, &ret->socket->addr, sizeof(ret->socket->addr)) ||
		listen(ret->socket->fd, MAX_PLAYERS) ||
		!init_server_info(ret) || !multicast_start(ret))
	{
		if (ret->socket)
			perror(__FUNCTION__);
		server_release(ret);
		ret = NULL;
	}
	ret->collecting_players = true;
	ret->clients = DLIST_INITIALIZER;
	register_server_observer(ret);
	return (ret);
}

void					server_release(struct s_server *server)
{
	if (server->socket)
		hs_socket_release(server->socket);
	dlist_release(&server->clients, client_info_release, true);
	unregister_server_observer();
	free(server);
}
