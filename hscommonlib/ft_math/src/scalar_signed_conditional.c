/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_signed_conditional.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 01:50:39 by admin             #+#    #+#             */
/*   Updated: 2018/08/31 21:12:13 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>

int32_t	min_32(int32_t rhs, int32_t lhs)
{
	return (rhs < lhs ? rhs : lhs);
}

int16_t	min_16(int16_t rhs, int16_t lhs)
{
	return (rhs < lhs ? rhs : lhs);
}

int32_t	max_32(int32_t rhs, int32_t lhs)
{
	return (rhs > lhs ? rhs : lhs);
}

int16_t	max_16(int16_t rhs, int16_t lhs)
{
	return (rhs > lhs ? rhs : lhs);
}
