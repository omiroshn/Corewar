/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 20:57:14 by admin             #+#    #+#             */
/*   Updated: 2018/09/11 21:00:13 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket_private.h"
#include <stdlib.h>
#include <unistd.h>

void	hs_socket_release(struct s_hs_socket *sock)
{
	if (sock->fd != -1)
	{
		shutdown(sock->fd, SHUT_RDWR);
		close(sock->fd);
	}
	free(sock);
}
