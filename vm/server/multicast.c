/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multicast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 23:42:59 by Admin             #+#    #+#             */
/*   Updated: 2018/09/14 23:43:56 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_printf.h"
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

void	*multicast_worker(void *ctx)
{
	struct s_server	*serv;
	bool			quit;
	int				ret;
	const size_t	msg_len = sizeof(struct s_multicast_msg);

	quit = false;
	serv = ctx;
	while (!quit)
	{
		ret = sendto(serv->multicast_socket->fd, &serv->multicast_msg, msg_len,
					0, &serv->multicast_addr, sizeof(struct sockaddr));
		if (ret == -1)
			perror("Multicast send failed");
		usleep(10000);
		pthread_mutex_lock(&serv->multicast_mutex);
		quit = serv->multicast_shutdown;
		pthread_mutex_unlock(&serv->multicast_mutex);
	}
	pthread_mutex_lock(&serv->multicast_stop_mutex);
	hs_socket_release(serv->multicast_socket);
	serv->multicast_running = false;
	pthread_cond_signal(&serv->multicast_cond);
	pthread_mutex_unlock(&serv->multicast_stop_mutex);
	pthread_exit(NULL);
	return (NULL);
}

bool	multicast_start(struct s_server *server)
{
	server->multicast_socket = hs_socket(INADDR_ANY, 0, SOCK_DGRAM);
	if (!hs_sockaddr_str(&server->multicast_addr, MULTICAST_IP, MULTICAST_PORT)
		|| !server->multicast_socket)
		return (false);
	server->multicast_shutdown = false;
	server->multicast_running = true;
	if (pthread_cond_init(&server->multicast_cond, NULL) ||
		pthread_mutex_init(&server->multicast_stop_mutex, NULL) ||
		pthread_mutex_init(&server->multicast_mutex, NULL) ||
		pthread_create(&server->multicast_thread, NULL,
						multicast_worker, server))
	{
		perror(__FUNCTION__);
		return (false);
	}
	pthread_detach(server->multicast_thread);
	return (true);
}

void	multicast_stop(struct s_server *server)
{
	pthread_mutex_lock(&server->multicast_mutex);
	pthread_mutex_lock(&server->multicast_stop_mutex);
	server->multicast_shutdown = true;
	pthread_mutex_unlock(&server->multicast_mutex);
	while (server->multicast_running)
	{
		pthread_cond_wait(&server->multicast_cond,
						&server->multicast_stop_mutex);
	}
	pthread_mutex_unlock(&server->multicast_stop_mutex);
}
