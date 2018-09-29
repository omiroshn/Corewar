/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:59:04 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/18 22:50:08 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "hsnet.h"
# include "network_common.h"

struct s_cor_file;

struct	s_client
{
	struct s_cor_file	*cor_file;
	struct s_hs_socket	*socket;
	bool				verbose;
};

bool	connect_to_server(
			struct s_client *client,
			struct s_multicast_msg *multicast_msg);

#endif
