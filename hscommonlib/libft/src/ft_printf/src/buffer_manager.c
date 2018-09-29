/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/09/09 14:04:26 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_manager.h"
#include "libft.h"
#include <unistd.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct s_bufman g_bufman =
{
	.buff = {0},
	.buff_size = BUFF_SIZE,
	.curr_size = 0,
	.total_size = 0,
	.user_buff = NULL,
	.fd = 1,
	.invalid = 0
};

void	reset_buffer(int fd, char *user_buff, size_t user_buff_size)
{
	g_bufman.fd = fd;
	g_bufman.user_buff = user_buff;
	if (user_buff != NULL)
		g_bufman.buff_size = user_buff_size;
	else
		g_bufman.buff_size = BUFF_SIZE;
	g_bufman.curr_size = 0;
	g_bufman.total_size = 0;
	g_bufman.invalid = 0;
}

void	print_to_buffer(void *ptr, int size)
{
	const int available_size = g_bufman.buff_size - g_bufman.curr_size;
	const int size_to_print = MIN(available_size, size);

	if (g_bufman.user_buff)
	{
		ft_memcpy(g_bufman.user_buff + g_bufman.curr_size, ptr, size_to_print);
		g_bufman.curr_size += size_to_print;
	}
	else
	{
		ft_memcpy(g_bufman.buff + g_bufman.curr_size, ptr, size_to_print);
		g_bufman.curr_size += size_to_print;
		if (g_bufman.curr_size == g_bufman.buff_size)
			fflush_buffer();
		if (size > size_to_print)
			print_to_buffer(ptr + size_to_print, size - size_to_print);
	}
}

int		fflush_buffer(void)
{
	if (g_bufman.invalid)
	{
		g_bufman.curr_size = 0;
		return (-1);
	}
	g_bufman.total_size += g_bufman.curr_size;
	if (g_bufman.user_buff != NULL)
		g_bufman.user_buff[g_bufman.buff_size - 1] = '\0';
	else if (g_bufman.curr_size != 0)
	{
		write(g_bufman.fd, g_bufman.buff, g_bufman.curr_size);
		g_bufman.curr_size = 0;
	}
	return (g_bufman.total_size);
}

void	set_buffer_error(void)
{
	g_bufman.invalid = 1;
}

void	print_padding(char c, int amount)
{
	while (amount--)
	{
		if (g_bufman.curr_size == BUFF_SIZE)
		{
			if (g_bufman.user_buff != NULL)
				break ;
			fflush_buffer();
		}
		if (g_bufman.user_buff != NULL)
			g_bufman.user_buff[g_bufman.curr_size] = c;
		else
			g_bufman.buff[g_bufman.curr_size] = c;
		++g_bufman.curr_size;
	}
}
