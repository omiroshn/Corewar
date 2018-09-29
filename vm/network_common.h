/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_common.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:36:31 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/14 15:37:09 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_COMMON_H
# define NETWORK_COMMON_H

# include "hsnet.h"
# include "op.h"

# define MULTICAST_IP "239.255.255.250"
# define MULTICAST_ADDR htonl(0xeffffffa)
# define MULTICAST_PORT 1905

enum
{
	kPlayerNameMaxSize = 128,
	kRecvBufSize = 2048,
	kBinaryMaxSize = CHAMP_MAX_SIZE + sizeof(struct s_header)
};

struct					s_hello_msg
{
	uint8_t				name_len;
	uint16_t			bin_len;
};

struct					s_multicast_msg
{
	char				ip[kIpv4StrMaxSize + 1];
	uint16_t			port;
};

#endif
