/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 14:28:26 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/29 14:34:23 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include <libkern/OSByteOrder.h>

inline uint16_t	swap16(uint16_t value)
{
	return (OSSwapInt16(value));
}

inline uint32_t	swap32(uint32_t value)
{
	return (OSSwapInt32(value));
}

inline uint64_t	swap64(uint64_t value)
{
	return (OSSwapInt64(value));
}
