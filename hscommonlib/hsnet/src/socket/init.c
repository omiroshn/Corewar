/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:51:32 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/11 21:20:12 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket_private.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

struct s_hs_socket	*hs_socket_sockaddr(
						void *sockaddr,
						int type)
{
	struct s_hs_socket	*sock;

	sock = ft_memalloc(sizeof(struct s_hs_socket));
	sock->addr = *((struct sockaddr*)sockaddr);
	sock->fd = socket(sock->addr.sa_family, type, IPPROTO_IP);
	if (sock->fd == -1)
	{
		perror(__FUNCTION__);
		hs_socket_release(sock);
		return (NULL);
	}
	return (sock);
}

struct s_hs_socket	*hs_socket(
						uint32_t address,
						uint16_t port,
						int type)
{
	struct sockaddr_in sockaddr;

	hs_sockaddr(&sockaddr, address, port);
	return (hs_socket_sockaddr(&sockaddr, type));
}

struct s_hs_socket	*hs_socket_str(
						const char *address,
						uint16_t port,
						int type)
{
	struct sockaddr_in	sockaddr;

	hs_sockaddr_str(&sockaddr, address, port);
	return (hs_socket_sockaddr(&sockaddr, type));
}

struct s_hs_socket	*hs_socket_fstr(
						const char *address_port,
						int type)
{
	struct sockaddr_in	sockaddr;

	hs_sockaddr_fstr(&sockaddr, address_port);
	return (hs_socket_sockaddr(&sockaddr, type));
}
