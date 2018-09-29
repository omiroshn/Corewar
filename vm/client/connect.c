/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:41:05 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/14 17:41:13 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"
#include "ft_printf.h"
#include "cor_file.h"
#include "swap.h"
#include <stdio.h>
#include <stdlib.h>

static void		print_hello_msg(struct s_hello_msg *msg, const char *username)
{
	ft_printf("\tbinary length: %hd\n\tname length: %hhd\n",
			msg->bin_len, msg->name_len);
	ft_printf("\tname: %s\n", username);
}

static bool		send_hello(struct s_client *client)
{
	struct s_hello_msg	hello_msg;
	const size_t		hello_size = sizeof(hello_msg);
	const char			*user_name = getenv("USER");
	size_t				user_name_len;
	struct s_header		*cor_header;

	hello_msg.bin_len = client->cor_file->size;
	if (!user_name)
		user_name = "mamkin_hacker";
	user_name_len = ft_strlen(user_name);
	hello_msg.name_len = user_name_len;
	if (send(client->socket->fd, &hello_msg, hello_size, 0) != hello_size)
	{
		perror("Failed to send hello packet");
		close(client->socket->fd);
		return (false);
	}
	send(client->socket->fd, user_name, user_name_len, 0);
	cor_header = client->cor_file->header;
	cor_header->prog_size = swap32(cor_header->prog_size);
	if (client->verbose)
		print_hello_msg(&hello_msg, user_name);
	return (hs_tcp_write(client->socket->fd, client->cor_file->content,
						client->cor_file->size));
}

bool			connect_to_server(
				struct s_client *client,
				struct s_multicast_msg *multicast_msg)
{
	struct sockaddr	addr;

	if (!hs_sockaddr_str(&addr, multicast_msg->ip, multicast_msg->port))
		return (false);
	if (connect(client->socket->fd, &addr, sizeof(struct sockaddr)) == -1)
	{
		perror("Connection failed");
		return (false);
	}
	if (client->verbose)
		ft_printf("Succesfully connected\nSending hello packet:\n");
	return (send_hello(client));
}
