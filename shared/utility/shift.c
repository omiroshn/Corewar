/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_shift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:35:29 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:55:50 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shift.h"
#include "op.h"

inline size_t	cyclic_shift_mem(size_t offset, size_t period, int side)
{
	return (((offset + period) + side) % period);
}

inline uint32_t	cyclic_shift_u32(uint32_t offset, uint32_t period, int side)
{
	return (((offset + period) + side) % period);
}

inline int32_t	cyclic_shift_32(int32_t offset, int32_t period, int side)
{
	return (((offset + period) + side) % period);
}

inline void		*mempool_shift(void *pc, void *ground_ptr, int side)
{
	const size_t mem_offset = pc - ground_ptr;

	return (ground_ptr + cyclic_shift_mem(mem_offset, MEM_SIZE, side));
}
