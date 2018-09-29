/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool_jobqueue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 20:41:09 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/11 20:49:00 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thpool_private.h"
#include <stdlib.h>

bool					thpool_init_job_queue(t_jobqueue *jobqueue)
{
	jobqueue->jobs = DLIST_INITIALIZER;
	thpool_bsem_init(&jobqueue->has_jobs, 0);
	pthread_mutex_init(&jobqueue->rwjob_mutex, NULL);
	return (true);
}

void					thpool_jobqueue_destroy(t_jobqueue *jobqueue)
{
	dlist_release(&jobqueue->jobs, free, true);
	thpool_bsem_destroy(&jobqueue->has_jobs);
	pthread_mutex_destroy(&jobqueue->rwjob_mutex);
}

void					thpool_jobqueue_push(t_jobqueue *queue, t_job *job)
{
	pthread_mutex_lock(&queue->rwjob_mutex);
	dlist_push_back_data(&queue->jobs, job);
	thpool_bsem_post(&queue->has_jobs);
	pthread_mutex_unlock(&queue->rwjob_mutex);
}

t_job					*thpool_jobqueue_pop(t_jobqueue *queue)
{
	t_job *job;

	pthread_mutex_lock(&queue->rwjob_mutex);
	job = dlist_pop_front(&queue->jobs);
	pthread_mutex_unlock(&queue->rwjob_mutex);
	return (job);
}
