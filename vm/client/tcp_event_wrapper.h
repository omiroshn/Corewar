/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcp_event_wrapper.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:42:10 by admin             #+#    #+#             */
/*   Updated: 2018/09/16 10:43:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCP_EVENT_WRAPPER_H
# define TCP_EVENT_WRAPPER_H

# include <stdbool.h>

struct s_hs_socket;

bool	tcp_event_collector_run(struct s_hs_socket *server_socket);
bool	tcp_event_collector_running(void);
void	tcp_event_collector_stop(void);

#endif
