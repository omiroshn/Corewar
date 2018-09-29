/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 15:08:17 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casts.h"

t_signed_cast g_signed_cast[length_types_total] = {
	int_cast,
	char_cast, short_int_cast,
	long_int_cast, ll_int_cast,
	intmax_cast, size_t_cast
};

t_unsigned_cast g_unsigned_cast[length_types_total] = {
	uint_cast,
	uchar_cast, ushort_int_cast,
	ulong_int_cast, ull_int_cast,
	uintmax_cast, usize_t_cast
};

intmax_t	intmax_cast(va_list ap)
{
	return (va_arg(ap, intmax_t));
}

uintmax_t	uintmax_cast(va_list ap)
{
	return (va_arg(ap, uintmax_t));
}

uintmax_t	usize_t_cast(va_list ap)
{
	return (va_arg(ap, size_t));
}

intmax_t	size_t_cast(va_list ap)
{
	return (va_arg(ap, size_t));
}
