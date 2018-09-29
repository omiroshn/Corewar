/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:53:32 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "casts/casts.h"
#include "specifier.h"
#include "buffer_manager.h"
#include "libft.h"

void	print_hexa(struct s_specifier *spec, va_list ap, bool upper_case)
{
	const uintmax_t	value = g_unsigned_cast[spec->length_type](ap);
	char			*res;
	int				size;

	res = ft_uitoa_base(value, 16, &size);
	if (spec->precision != PRECISION_NOT_SET)
		size = handle_integer_precision(spec, &res, size, value == 0);
	if (value != 0 && spec->flags.special)
	{
		if (spec->flags.padding_with_zeros)
		{
			if (upper_case)
				print_to_buffer("0X", 2);
			else
				print_to_buffer("0x", 2);
			spec->min_width -= 2;
		}
		else
		{
			res = ft_strjoin_back("0x", res);
			size += 2;
		}
	}
	upper_case ? ft_strtoupper(res) : 0;
	print(spec, res, size, true);
}

void	print_octa(struct s_specifier *spec, va_list ap, bool upper_case)
{
	const uintmax_t	value = g_unsigned_cast[spec->length_type](ap);
	char			*res;
	int				size;

	res = ft_uitoa_base(value, 8, &size);
	if (spec->precision != PRECISION_NOT_SET)
		size = handle_integer_precision(spec, &res, size, value == 0);
	if (spec->flags.special && *res != '0')
	{
		res = ft_strjoin_back("0", res);
		++size;
	}
	if (upper_case)
		ft_strtoupper(res);
	print(spec, res, size, true);
}

void	print_binary(struct s_specifier *spec, va_list ap, bool upper_case)
{
	const uintmax_t	value = g_unsigned_cast[spec->length_type](ap);
	char			*res;
	int				size;

	res = ft_uitoa_base(value, 2, &size);
	if (spec->precision != PRECISION_NOT_SET)
		size = handle_integer_precision(spec, &res, size, value == 0);
	if (value != 0 && spec->flags.special)
	{
		res = ft_strjoin_back("0b", res);
		size += 2;
	}
	if (upper_case)
		ft_strtoupper(res);
	print(spec, res, size, true);
}
