/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casts.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 15:08:06 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTS_H
# define CASTS_H

# include "../flags.h"

# include <stdarg.h>
# include <inttypes.h>
# include <stddef.h>

typedef intmax_t	(*t_signed_cast)(va_list ap);
typedef uintmax_t	(*t_unsigned_cast)(va_list ap);

intmax_t	int_cast(va_list ap);
intmax_t	char_cast(va_list ap);
intmax_t	short_int_cast(va_list ap);
intmax_t	long_int_cast(va_list ap);
intmax_t	ll_int_cast(va_list ap);
intmax_t	intmax_cast(va_list ap);
intmax_t	size_t_cast(va_list ap);

uintmax_t	uint_cast(va_list ap);
uintmax_t	uchar_cast(va_list ap);
uintmax_t	ushort_int_cast(va_list ap);
uintmax_t	ulong_int_cast(va_list ap);
uintmax_t	ull_int_cast(va_list ap);
uintmax_t	uintmax_cast(va_list ap);
uintmax_t	usize_t_cast(va_list ap);

extern t_unsigned_cast g_unsigned_cast[length_types_total];
extern t_signed_cast g_signed_cast[length_types_total];

#endif
