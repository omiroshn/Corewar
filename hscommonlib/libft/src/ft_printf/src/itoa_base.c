/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:33:16 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"
#include <stdlib.h>

static const char *g_base = "0123456789abcdef";

static void	convert_signed_to_string(char *buff,
									intmax_t number,
									int base,
									int *i)
{
	if (number >= base || number <= -base)
		convert_signed_to_string(buff, number / base, base, i);
	buff[(*i)++] = g_base[ABS(number % base)];
}

static void	convert_unsigned_to_string(char *buff,
										uintmax_t number,
										int base,
										int *i)
{
	if (number >= (uintmax_t)base)
		convert_unsigned_to_string(buff, number / base, base, i);
	buff[(*i)++] = g_base[number % base];
}

char		*ft_itoa_base(intmax_t number, int base, int *size)
{
	char	buff[128];
	char	*res;

	*size = 0;
	if (base == 10 && number < 0)
		buff[(*size)++] = '-';
	convert_signed_to_string(buff, number, base, size);
	res = malloc(*size + 1);
	ft_strncpy(res, buff, *size);
	res[*size] = '\0';
	return (res);
}

char		*ft_uitoa_base(uintmax_t number, int base, int *size)
{
	char	buff[128];
	char	*res;

	*size = 0;
	convert_unsigned_to_string(buff, number, base, size);
	res = malloc(*size + 1);
	ft_strncpy(res, buff, *size);
	res[*size] = '\0';
	return (res);
}
