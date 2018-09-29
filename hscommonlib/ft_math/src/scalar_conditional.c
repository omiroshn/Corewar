/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_conditional.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 01:50:39 by admin             #+#    #+#             */
/*   Updated: 2018/08/31 20:45:43 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>

uint32_t	min_u32(uint32_t rhs, uint32_t lhs)
{
	return (rhs < lhs ? rhs : lhs);
}

uint16_t	min_u16(uint16_t rhs, uint16_t lhs)
{
	return (rhs < lhs ? rhs : lhs);
}

uint32_t	max_u32(uint32_t rhs, uint32_t lhs)
{
	return (rhs > lhs ? rhs : lhs);
}

uint16_t	max_u16(uint16_t rhs, uint16_t lhs)
{
	return (rhs > lhs ? rhs : lhs);
}
