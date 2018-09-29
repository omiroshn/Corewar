/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:24:23 by hshakula          #+#    #+#             */
/*   Updated: 2018/06/02 01:57:09 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"
#include <mach/mach_time.h>

void		init_timer(t_timer *timer)
{
	mach_timebase_info_data_t coeff;

	mach_timebase_info(&coeff);
	timer->numer = coeff.numer;
	timer->denom = coeff.denom;
	timer->current_time = 0;
	timer->start = mach_absolute_time();
	timer->current = timer->start;
	timer->time = 0.0;
	timer->old_time = 0.0;
}

void		reset_timer(t_timer *timer)
{
	timer->start = mach_absolute_time();
	timer->current = timer->start;
	timer->current_time = 0;
	timer->time = 0.0;
	timer->old_time = 0.0;
}

uint64_t	current_time(t_timer *timer)
{
	uint64_t	current_time;

	current_time = mach_absolute_time() - timer->start;
	current_time = current_time * timer->numer / timer->denom;
	return (current_time);
}

double		delta_time_from(t_timer *timer, uint64_t time_point)
{
	const uint64_t	now = current_time(timer);

	return ((double)((now - time_point) / 1000) / 1000000.0);
}

double		get_delta_time(t_timer *timer)
{
	double delta_time;

	timer->current = mach_absolute_time() - timer->start;
	timer->current_time = timer->current * timer->numer / timer->denom;
	timer->time = (double)(timer->current_time / 1000) / 1000000.0;
	delta_time = timer->time - timer->old_time;
	timer->old_time = timer->time;
	return (delta_time);
}
