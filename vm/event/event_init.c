/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:31:49 by admin             #+#    #+#             */
/*   Updated: 2018/09/16 14:37:10 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "libft.h"

void	event_init(
			struct s_event *event,
			t_event_type type)
{
	ft_memset(event, 0, sizeof(struct s_event));
	event->header.type = type;
}
