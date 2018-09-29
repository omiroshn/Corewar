/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:38:11 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 14:10:58 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THPOOL_PRIVATE_H
# define THPOOL_PRIVATE_H

# include "thpool.h"
# include "pthread.h"
# include <dlist.h>

typedef struct		s_job
{
	t_thread_func	func;
	void			*data;
}					t_job;

typedef struct		s_bsem
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	int				value;
}					t_bsem;

typedef struct		s_jobqueue
{
	pthread_mutex_t	rwjob_mutex;
	t_bsem			has_jobs;
	struct s_dlist	jobs;
}					t_jobqueue;

typedef struct		s_thread
{
	int				id;
	pthread_t		pthread;
	t_thpool		pool;
}					t_thread;

struct				s_thpool
{
	t_jobqueue		jobqueue;

	t_thread		**threads;
	pthread_mutex_t	thcount_mutex;
	pthread_cond_t	threads_idle;
	unsigned		num_threads;
	unsigned		num_alive_threads;
	unsigned		num_working_threads;
	char			shutdown;
};

void				thpool_free(t_thpool pool);

/*
**		Binary sema accept only 0 or 1 value
*/

void				thpool_bsem_init(t_bsem *bsem, int value);
void				thpool_bsem_destroy(t_bsem *bsem);
void				thpool_bsem_reset(t_bsem *bsem);
void				thpool_bsem_post(t_bsem *bsem);
void				thpool_bsem_post_all(t_bsem *bsem);
void				thpool_bsem_wait(t_bsem *bsem);

bool				thpool_init_job_queue(t_jobqueue *jobqueue);
void				thpool_jobqueue_destroy(t_jobqueue *jobqueue);
void				thpool_jobqueue_push(t_jobqueue *queue, t_job *job);
t_job				*thpool_jobqueue_pop(t_jobqueue *queue);

void				*thpool_worker(t_thread *thread);

#endif
