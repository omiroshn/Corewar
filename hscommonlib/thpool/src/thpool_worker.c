/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool_worker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 21:03:26 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 14:11:17 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thpool_private.h"
#include <stdlib.h>
#include <stdio.h>

void				thpool_loop_body(t_thread *thread, t_thpool pool)
{
	t_job	*job;

	pthread_mutex_lock(&pool->jobqueue.has_jobs.mutex);
	while (pool->jobqueue.has_jobs.value != 1 && pool->jobqueue.jobs.size == 0)
		pthread_cond_wait(&pool->jobqueue.has_jobs.cond,
							&pool->jobqueue.has_jobs.mutex);
	pool->jobqueue.has_jobs.value = 0;
	pthread_mutex_unlock(&pool->jobqueue.has_jobs.mutex);
	if (!pool->shutdown)
	{
		pthread_mutex_lock(&pool->thcount_mutex);
		++pool->num_working_threads;
		pthread_mutex_unlock(&pool->thcount_mutex);
		job = thpool_jobqueue_pop(&pool->jobqueue);
		if (job != NULL)
		{
			job->func(job->data);
			free(job);
		}
		pthread_mutex_lock(&pool->thcount_mutex);
		if (--pool->num_working_threads == 0)
			pthread_cond_signal(&pool->threads_idle);
		pthread_mutex_unlock(&pool->thcount_mutex);
	}
}

void				*thpool_worker(t_thread *thread)
{
	t_thpool	pool;
	char		thread_name[256];

	sprintf(thread_name, "Worker thread #%d", thread->id);
	pthread_setname_np(thread_name);
	pool = thread->pool;
	pthread_mutex_lock(&pool->thcount_mutex);
	++pool->num_alive_threads;
	pthread_mutex_unlock(&pool->thcount_mutex);
	while (!pool->shutdown)
		thpool_loop_body(thread, pool);
	pthread_mutex_lock(&pool->thcount_mutex);
	--pool->num_alive_threads;
	pthread_mutex_unlock(&pool->thcount_mutex);
	return (NULL);
}
