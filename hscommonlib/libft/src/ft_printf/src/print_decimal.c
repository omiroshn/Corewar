/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:46:20 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "specifier.h"
#include "casts/casts.h"
#include "padding.h"
#include "libft.h"
#include <stdlib.h>

int		handle_integer_precision(struct s_specifier *spec,
								char **res,
								int size,
								bool value_is_zero)
{
	const int	sign = **res == '-' ? 1 : 0;
	char		*padding_str;

	if (spec->precision == 0 && value_is_zero)
	{
		free(*res);
		*res = ft_strdup("");
		--size;
	}
	else if (spec->precision > size - sign)
	{
		padding_str = padding_string('0', spec->precision - size + sign);
		size = spec->precision + sign;
		*res = ft_emplace_string(*res, padding_str, sign);
		free(padding_str);
	}
	if (spec->symb == 'u' || spec->symb == 'o' || spec->symb == 'x')
		spec->flags.padding_with_zeros = false;
	return (size);
}

void	signed_padding(struct s_specifier *spec, int pos, char **res, int *size)
{
	const char	*pad_str = padding_string('0', spec->min_width - *size);

	*size = spec->min_width;
	*res = ft_emplace_string(*res, pad_str, pos);
	free((char*)pad_str);
	spec->min_width = 0;
}

void	print_signed_integer(struct s_specifier *spec, va_list ap)
{
	const intmax_t	value = g_signed_cast[spec->length_type](ap);
	int				size;
	char			*res;
	char			sign;

	sign = value < 0 ? '-' : 0;
	res = ft_itoa_base(value, 10, &size);
	if (spec->precision != PRECISION_NOT_SET)
	{
		size = handle_integer_precision(spec, &res, size, value == 0);
		spec->flags.padding_with_zeros = false;
	}
	if (value >= 0 && (spec->flags.force_sign_preceding ||
		(!spec->flags.force_sign_preceding &&
		spec->flags.put_space_instead_of_sign)))
	{
		sign = spec->flags.force_sign_preceding ? '+' : ' ';
		res = ft_emplace_string(res,
			spec->flags.force_sign_preceding ? "+" : " ", 0);
		++size;
	}
	if (spec->flags.padding_with_zeros && sign != 0 && spec->min_width > size)
		signed_padding(spec, ft_strchr(res, sign) - res + 1, &res, &size);
	print(spec, res, size, true);
}

void	print_unsigned_integer(struct s_specifier *spec, va_list ap)
{
	const uintmax_t		value = g_unsigned_cast[spec->length_type](ap);
	int					size;
	char				*res;

	res = ft_uitoa_base(value, 10, &size);
	if (spec->precision != PRECISION_NOT_SET)
		size = handle_integer_precision(spec, &res, size, value == 0);
	print(spec, res, size, true);
}
