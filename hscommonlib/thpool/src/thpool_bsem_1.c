/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool_bsem_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:11:37 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 14:11:56 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thpool_private.h"

void	thpool_bsem_wait(t_bsem *bsem)
{
	pthread_mutex_lock(&bsem->mutex);
	while (bsem->value != 1)
		pthread_cond_wait(&bsem->cond, &bsem->mutex);
	bsem->value = 0;
	pthread_mutex_unlock(&bsem->mutex);
}
