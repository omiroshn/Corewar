/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sockaddr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:51:32 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/12 20:35:34 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket_private.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

bool	hs_sockaddr(
		void *sockaddr_ptr,
		uint32_t address,
		uint16_t port)
{
	struct sockaddr_in *sockaddr;

	sockaddr = sockaddr_ptr;
	ft_memset(sockaddr, 0, sizeof(struct sockaddr_in));
	sockaddr->sin_addr.s_addr = htonl(address);
	sockaddr->sin_port = htons(port);
	sockaddr->sin_family = AF_INET;
	return (true);
}

bool	hs_sockaddr_str(
			void *sockaddr_ptr,
			const char *address,
			uint16_t port)
{
	struct sockaddr_in	*sockaddr;
	int					err;

	if (!address)
		return (false);
	sockaddr = sockaddr_ptr;
	ft_memset(sockaddr, 0, sizeof(struct sockaddr_in));
	err = inet_pton(AF_INET, address, &sockaddr->sin_addr);
	sockaddr->sin_port = htons(port);
	sockaddr->sin_family = AF_INET;
	if (err <= 0)
	{
		if (err == 0)
		{
			ft_dprintf(2, "%s: Address is not in presentation format: '%s'\n",
				__FUNCTION__, address);
		}
		else
			perror(__FUNCTION__);
	}
	return (err == 1);
}

bool	hs_sockaddr_fstr(
			void *sockaddr_ptr,
			const char *address_port)
{
	char		addr_buf[3 * 4 + 3 + 1];
	const char	*port_str = ft_strchr(address_port, ':');
	int			port;
	size_t		addr_len;

	port = ft_atoi(port_str ? port_str : "");
	if (port_str == NULL || port <= 0 || port >= UINT16_MAX)
	{
		ft_dprintf(2, "%s: Invalid format: '%s'\n", __FUNCTION__, address_port);
		return (false);
	}
	addr_len = port_str - address_port;
	ft_strncpy(addr_buf, address_port, addr_len);
	addr_buf[addr_len] = '\0';
	return (hs_sockaddr_str(sockaddr_ptr, addr_buf, (uint16_t)port));
}

char	*hsnet_sockaddr_to_str(void *sockaddr)
{
	char	host[NI_MAXHOST];
	char	port[NI_MAXSERV];
	int		ret;
	char	*str;
	size_t	len;

	ret = getnameinfo(
		sockaddr, sizeof(struct sockaddr),
		host, NI_MAXHOST,
		port, NI_MAXSERV,
		NI_NUMERICHOST | NI_NUMERICSERV);
	if (ret != 0)
		str = ft_strdup("unknown");
	else
	{
		str = malloc(kIpv4StrMaxSize + 1 + 5 + 1);
		len = ft_strlen(host);
		ft_strncpy(str, host, len);
		str[len++] = ':';
		ft_strcpy(&str[len], port);
	}
	return (str);
}
