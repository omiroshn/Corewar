/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:24:14 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/14 15:24:21 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

bool					send_to_clients(
							struct s_server *server,
							void *buf,
							size_t size)
{
	struct s_dlist_iter		iter;
	struct s_client_info	*client;
	int						ret;

	iter = dlist_iter_init(&server->clients);
	while (iter.node)
	{
		client = dlist_iter_data(&iter);
		if ((ret = send(client->fd, buf, size, 0)) != size)
		{
			if (ret == -1)
				perror(__FUNCTION__);
			return (false);
		}
		dlist_next(&iter);
	}
	return (true);
}

static bool				recv_player_info(
							struct s_server *server,
							struct s_client_info *client)
{
	struct s_hello_msg	*hello_msg;
	int					name_len;
	int					ret;
	char				*host;

	ret = recv(client->fd, client->buf, sizeof(struct s_hello_msg), 0);
	if (ret != sizeof(struct s_hello_msg))
		return (false);
	hello_msg = client->buf;
	name_len = hello_msg->name_len;
	if (name_len >= kPlayerNameMaxSize || hello_msg->bin_len >= kBinaryMaxSize)
		return (false);
	client->name = malloc(name_len + 1);
	ret = recv(client->fd, client->name, name_len, 0);
	if (ret != name_len)
		return (false);
	client->name[name_len] = '\0';
	host = hsnet_sockaddr_to_str(&client->sockaddr);
	ft_printf("Welcome, %s (%s)\n", client->name, host);
	free(host);
	client->binary_size = hello_msg->bin_len;
	client->binary = malloc(client->binary_size);
	return (hs_tcp_read(client->fd, client->binary, client->binary_size));
}

struct s_client_info	*accept_client(struct s_server *server)
{
	struct sockaddr			addr;
	socklen_t				len;
	int						client_socket;
	struct s_client_info	*ret;

	len = sizeof(addr);
	ft_memset(&addr, 0, sizeof(struct sockaddr));
	client_socket = accept(server->socket->fd, &addr, &len);
	if (client_socket == -1)
	{
		perror(__FUNCTION__);
		return (NULL);
	}
	ret = client_info(client_socket, &addr);
	pthread_mutex_lock(&server->client_insert_mutex);
	if (!server->collecting_players || !recv_player_info(server, ret))
	{
		client_info_release(ret);
		ret = NULL;
	}
	else
		dlist_push_back_data(&server->clients, ret);
	pthread_mutex_unlock(&server->client_insert_mutex);
	return (ret);
}
