/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:24:23 by hshakula          #+#    #+#             */
/*   Updated: 2018/04/20 20:54:54 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

# include <stdint.h>

typedef struct	s_timer
{
	uint64_t	start;
	uint64_t	current;
	uint64_t	current_time;
	uint64_t	numer;
	uint64_t	denom;
	double		time;
	double		old_time;
}				t_timer;

void			init_timer(t_timer *timer);
void			reset_timer(t_timer *timer);
double			delta_time_from(t_timer *timer, uint64_t time_point);
uint64_t		current_time(t_timer *timer);
double			get_delta_time(t_timer *timer);

#endif
