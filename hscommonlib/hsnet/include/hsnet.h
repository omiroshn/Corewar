/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsnet.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:39:11 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/12 20:30:20 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSNET_H
# define HSNET_H

# include <inttypes.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netinet/in.h>

enum
{
	kIpv4StrMaxSize = 3 * 4 + 3
};

struct				s_hs_socket
{
	int				fd;
	struct sockaddr	addr;
};

bool				hs_sockaddr(
						void *sockaddr,
						uint32_t addr,
						uint16_t port);
bool				hs_sockaddr_str(
						void *sockaddr,
						const char *addr,
						uint16_t port);
bool				hs_sockaddr_fstr(
						void *sockaddr,
						const char *addr_port);

struct s_hs_socket	*hs_socket_sockaddr(
						void *sockaddr,
						int type);

struct s_hs_socket	*hs_socket(
						uint32_t addr,
						uint16_t port,
						int type);
struct s_hs_socket	*hs_socket_fstr(
						const char *address_port,
						int type);
struct s_hs_socket	*hs_socket_str(
						const char *addr,
						uint16_t port,
						int type);

void				hs_socket_release(struct s_hs_socket *socket);

/*
**	Typically used for big reads and writes
*/

bool				hs_tcp_read(int fd, void *buf, size_t size);
bool				hs_tcp_write(int fd, void *buf, size_t size);

bool				hs_socket_is_ipv6(struct s_hs_socket *socket);
bool				hs_socket_is_ipv4(struct s_hs_socket *socket);

char				*hsnet_get_ip(int family, const char *interface);
char				*hsnet_get_broadcast_ip(int sock);

char				*hsnet_sockaddr_to_str(void *sockaddr);

#endif
