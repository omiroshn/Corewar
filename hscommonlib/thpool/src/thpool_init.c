/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:12:20 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 14:13:23 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thpool_private.h"
#include <stdlib.h>

bool					thpool_init_threads(t_thread **th, t_thpool pool)
{
	int i;

	i = -1;
	while (++i < pool->num_threads)
	{
		th[i]->id = i;
		th[i]->pool = pool;
		if (pthread_create(&th[i]->pthread, NULL, (void*)thpool_worker, th[i]))
			return (false);
		pthread_detach(th[i]->pthread);
	}
	return (true);
}

t_thpool				thpool_init(unsigned num_threads, unsigned queue_size)
{
	int			i;
	t_thpool	pool;

	if (num_threads > 32 || num_threads == 0 ||
		queue_size == 0 || queue_size > 999)
		return (NULL);
	pool = malloc(sizeof(struct s_thpool));
	*pool = (struct s_thpool){};
	pool->threads = malloc(sizeof(t_thread*) * num_threads);
	i = -1;
	while (++i < num_threads)
		pool->threads[i] = malloc(sizeof(t_thread));
	pool->num_threads = num_threads;
	pthread_mutex_init(&pool->thcount_mutex, NULL);
	pthread_cond_init(&pool->threads_idle, NULL);
	if (!thpool_init_job_queue(&pool->jobqueue) ||
		!thpool_init_threads(pool->threads, pool))
		thpool_destroy(pool);
	return (pool);
}

t_thpool_error_codes	thpool_wait(t_thpool pool)
{
	if (pthread_mutex_lock(&pool->thcount_mutex))
		return (thpool_lock_failure);
	while (pool->jobqueue.jobs.size || pool->num_working_threads)
		pthread_cond_wait(&pool->threads_idle, &pool->thcount_mutex);
	if (pthread_mutex_unlock(&pool->thcount_mutex))
		return (thpool_lock_failure);
	return (thpool_none);
}
