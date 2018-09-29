/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool_bsem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 20:41:01 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 14:11:41 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thpool_private.h"
#include <stdlib.h>
#include <assert.h>

void	thpool_bsem_init(t_bsem *bsem, int value)
{
	assert(value == 0 || value == 1);
	pthread_mutex_init(&bsem->mutex, NULL);
	pthread_cond_init(&bsem->cond, NULL);
	bsem->value = value;
}

void	thpool_bsem_destroy(t_bsem *bsem)
{
	pthread_mutex_destroy(&bsem->mutex);
	pthread_cond_destroy(&bsem->cond);
}

void	thpool_bsem_reset(t_bsem *bsem)
{
	thpool_bsem_destroy(bsem);
	thpool_bsem_init(bsem, 0);
}

void	thpool_bsem_post(t_bsem *bsem)
{
	pthread_mutex_lock(&bsem->mutex);
	bsem->value = 1;
	pthread_cond_signal(&bsem->cond);
	pthread_mutex_unlock(&bsem->mutex);
}

void	thpool_bsem_post_all(t_bsem *bsem)
{
	pthread_mutex_lock(&bsem->mutex);
	bsem->value = 1;
	pthread_cond_broadcast(&bsem->cond);
	pthread_mutex_unlock(&bsem->mutex);
}
