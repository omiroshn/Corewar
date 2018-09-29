/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:12:26 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/14 16:12:33 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsnet.h"
#include <stdio.h>

bool	hs_tcp_write(int fd, void *buf, size_t size)
{
	ssize_t	ret;
	size_t	total_ret;

	total_ret = 0;
	while (total_ret != size)
	{
		ret = send(fd, buf + total_ret, size - total_ret, 0);
		if (ret <= 0)
		{
			perror(__FUNCTION__);
			return (false);
		}
		total_ret += ret;
	}
	return (true);
}
