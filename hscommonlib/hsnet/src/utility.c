/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 23:20:23 by Admin             #+#    #+#             */
/*   Updated: 2018/09/14 23:20:58 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsnet.h"
#include "libft.h"
#include <stdio.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <stdlib.h>

char	*hsnet_get_ip(int family, const char *interface)
{
	struct ifaddrs		*ifaddr;
	struct ifaddrs		*ifa;
	char				host[NI_MAXHOST];
	char				*ret;

	ret = NULL;
	if (getifaddrs(&ifaddr) == -1)
		return (NULL);
	ifa = ifaddr;
	while (ifa != NULL)
	{
		if (ifa->ifa_addr && ft_strequ(ifa->ifa_name, interface) &&
			ifa->ifa_addr->sa_family == family)
		{
			if (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host,
							NI_MAXHOST, NULL, 0, NI_NUMERICHOST) != 0)
				return (NULL);
			ret = ft_strdup(host);
			break ;
		}
		ifa = ifa->ifa_next;
	}
	freeifaddrs(ifaddr);
	return (ret);
}

char	*hsnet_get_broadcast_ip(int sock)
{
	struct ifreq	ifr;
	struct in_addr	bcast;
	char			*ret;

	ft_memset(&ifr, 0, sizeof(ifr));
	ft_strcpy(ifr.ifr_name, "en0");
	if ((ioctl(sock, SIOCGIFBRDADDR, &ifr)) == -1)
	{
		perror("ioctl");
		return (NULL);
	}
	ret = ft_memalloc(kIpv4StrMaxSize + 1);
	ret[kIpv4StrMaxSize] = '\0';
	ft_memcpy(&bcast, &(*(struct sockaddr_in*)&ifr.ifr_broadaddr).sin_addr, 4);
	if (inet_ntop(AF_INET, &bcast, ret, kIpv4StrMaxSize) == NULL)
	{
		free(ret);
		ret = NULL;
	}
	return (ret);
}
