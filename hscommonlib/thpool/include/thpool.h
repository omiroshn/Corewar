/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:38:11 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 14:09:21 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THPOOL_H
# define THPOOL_H

typedef enum			e_thpool_error_codes
{
	thpool_none = 0,
	thpool_unknown,
	thpool_invalid_operation,
	thpool_lock_failure,
	thpool_full_queue,
	thpool_shutdown,
	thpool_cond_signal_error,
	thpool_already_shuting_down,
	thpool_thread_joining_error,
	thpool_,
}						t_thpool_error_codes;

typedef void *(*t_thread_func)(void *);
typedef struct s_thpool	*t_thpool;

t_thpool				thpool_init(unsigned threads_amount,
										unsigned queue_size);
t_thpool_error_codes	thpool_add_job(t_thpool pool,
										t_thread_func thread_function,
										void *data);
t_thpool_error_codes	thpool_wait(t_thpool pool);
t_thpool_error_codes	thpool_destroy(t_thpool pool);

#endif
