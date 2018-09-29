/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_clamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 20:48:42 by Admin             #+#    #+#             */
/*   Updated: 2018/08/31 21:14:14 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.h"

uint32_t	clamp_u32(uint32_t value, uint32_t edge0, uint32_t edge1)
{
	return (max_u32(edge0, min_u32(value, edge1)));
}

uint16_t	clamp_u16(uint16_t value, uint16_t edge0, uint16_t edge1)
{
	return (max_u16(edge0, min_u16(value, edge1)));
}

int32_t		clamp_32(int32_t value, int32_t edge0, int32_t edge1)
{
	return (max_32(edge0, min_32(value, edge1)));
}

int16_t		clamp_16(int16_t value, int16_t edge0, int16_t edge1)
{
	return (max_16(edge0, min_16(value, edge1)));
}
