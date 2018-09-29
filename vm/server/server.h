/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:50:06 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/15 18:33:29 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "network_common.h"
# include "dlist.h"
# include "event.h"

# include <pthread.h>

struct					s_client_info
{
	struct sockaddr		sockaddr;
	char				*name;
	int					fd;
	void				*binary;
	size_t				binary_size;
	void				*buf;
};

struct					s_server
{
	struct s_hs_socket		*socket;

	struct s_dlist			clients;
	bool					collecting_players;
	pthread_mutex_t			client_insert_mutex;

	struct s_multicast_msg	multicast_msg;
	struct s_hs_socket		*multicast_socket;
	pthread_mutex_t			multicast_mutex;
	pthread_mutex_t			multicast_stop_mutex;
	pthread_cond_t			multicast_cond;
	struct sockaddr			multicast_addr;
	pthread_t				multicast_thread;
	bool					multicast_shutdown;
	bool					multicast_running;
};

struct s_server			*server_init(void);
void					server_release(struct s_server *server);

struct s_client_info	*client_info(int fd, struct sockaddr *sockaddr);
void					client_info_release(void *client_ptr);

void					register_server_observer(struct s_server *server);
void					unregister_server_observer(void);

struct s_client_info	*accept_client(struct s_server *server);
bool					send_to_clients(struct s_server *server, void *buf,
										size_t size);

bool					multicast_start(struct s_server *server);
void					multicast_stop(struct s_server *server);

#endif
