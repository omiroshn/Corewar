/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/15 01:08:06 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casts.h"

uintmax_t	uint_cast(va_list ap)
{
	return (va_arg(ap, unsigned int));
}

uintmax_t	ushort_int_cast(va_list ap)
{
	return ((unsigned short int)va_arg(ap, int));
}

uintmax_t	ulong_int_cast(va_list ap)
{
	return (va_arg(ap, unsigned long int));
}

uintmax_t	ull_int_cast(va_list ap)
{
	return (va_arg(ap, unsigned long long int));
}

uintmax_t	uchar_cast(va_list ap)
{
	return ((unsigned char)va_arg(ap, int));
}
