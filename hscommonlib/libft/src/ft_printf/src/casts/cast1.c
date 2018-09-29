/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/15 01:07:58 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casts.h"

intmax_t	int_cast(va_list ap)
{
	return (va_arg(ap, int));
}

intmax_t	short_int_cast(va_list ap)
{
	return ((short int)va_arg(ap, int));
}

intmax_t	long_int_cast(va_list ap)
{
	return (va_arg(ap, long int));
}

intmax_t	ll_int_cast(va_list ap)
{
	return ((intmax_t)va_arg(ap, long long int));
}

intmax_t	char_cast(va_list ap)
{
	return ((char)va_arg(ap, int));
}
