/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_mempool_io.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 23:00:56 by Admin             #+#    #+#             */
/*   Updated: 2018/08/31 23:20:40 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mempool_io.h"
#include "shift.h"

void	*mempool_read(
	void *dst,
	void *mempool,
	int num_bytes,
	void *ground_ptr)
{
	int i;

	i = -1;
	while (++i < num_bytes)
	{
		((char*)dst)[i] = *((char*)mempool);
		mempool = mempool_shift(mempool, ground_ptr, 1);
	}
	return (mempool);
}

void	mempool_write(
	void *mempool,
	void *src,
	int num_bytes,
	void *ground_ptr)
{
	int i;

	i = -1;
	while (++i < num_bytes)
	{
		*((char*)mempool) = ((char*)src)[i];
		mempool = mempool_shift(mempool, ground_ptr, 1);
	}
}
