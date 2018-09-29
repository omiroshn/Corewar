/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool_managing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:38:11 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 14:10:24 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thpool_private.h"
#include <stdlib.h>
#include <unistd.h>

t_thpool_error_codes		thpool_add_job(
	t_thpool pool,
	t_thread_func thread_function,
	void *data)
{
	t_thpool_error_codes	err;
	t_job					*job;

	err = thpool_none;
	if (pool == NULL || thread_function == NULL)
		return (thpool_invalid_operation);
	job = malloc(sizeof(t_job));
	job->func = thread_function;
	job->data = data;
	thpool_jobqueue_push(&pool->jobqueue, job);
	return (err);
}

t_thpool_error_codes		thpool_destroy(t_thpool pool)
{
	t_thpool_error_codes	err;

	err = thpool_none;
	if (pool == NULL)
		return (thpool_invalid_operation);
	pool->shutdown = 1;
	while (pool->num_alive_threads)
	{
		thpool_bsem_post_all(&pool->jobqueue.has_jobs);
		sleep(1);
	}
	thpool_jobqueue_destroy(&pool->jobqueue);
	return (err);
}

void						thpool_free(t_thpool pool)
{
	int i;

	i = -1;
	while (++i)
		free(pool->threads[i]);
	free(pool->threads);
	pthread_mutex_destroy(&pool->thcount_mutex);
	pthread_cond_destroy(&pool->threads_idle);
	free(pool);
}
