/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:51:06 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "specifier.h"
#include "ftoa.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_printf_float(struct s_specifier *spec,
						const double value,
						char *(*ftoa)(double, int, int*, bool),
						int *size)
{
	char *res;

	if (spec->precision == PRECISION_NOT_SET)
		spec->precision = 6;
	else
		spec->precision = MIN(g_max_ftoa_precision, spec->precision);
	res = ftoa(value, spec->precision, size, spec->flags.special);
	if ((spec->flags.force_sign_preceding ||
		spec->flags.put_space_instead_of_sign) && value >= 0.0f)
	{
		res = ft_emplace_string(res,
			spec->flags.force_sign_preceding ? "+" : " ", 0);
		++(*size);
	}
	return (res);
}

void	print_float(struct s_specifier *spec, va_list ap, bool upper_case)
{
	double	value;
	char	*res;
	int		size;

	if (spec->length_type == L_length)
		value = (double)va_arg(ap, long double);
	else
		value = va_arg(ap, double);
	(void)upper_case;
	res = ft_printf_float(spec, value, ft_ftoa, &size);
	print(spec, res, size, true);
}

void	print_scientific(struct s_specifier *spec, va_list ap, bool upper_case)
{
	double	value;
	char	*res;
	int		size;

	if (spec->length_type == L_length)
		value = (double)va_arg(ap, long double);
	else
		value = va_arg(ap, double);
	res = ft_printf_float(spec, value, ft_float_to_scientific, &size);
	if (upper_case)
		ft_strtoupper(res);
	print(spec, res, size, true);
}

int		remove_trailing_zeros(char *s)
{
	char	*end;
	int		ret;

	ret = 0;
	end = s;
	while (*end && *end != 'e')
		end++;
	if (*end == '\0')
		--end;
	while ((*end == '0' || *end == '.') && end > s + 1)
	{
		*end = '\0';
		++ret;
		--end;
	}
	return (ret);
}

void	print_shortest_float(struct s_specifier *spec,
							va_list ap,
							bool upper_case)
{
	double	value;
	char	*res[2];
	int		size[2];

	if (spec->length_type == L_length)
		value = (double)va_arg(ap, long double);
	else
		value = va_arg(ap, double);
	res[0] = ft_printf_float(spec, value, ft_ftoa, &(size[0]));
	size[0] -= remove_trailing_zeros(res[0]);
	res[1] = ft_printf_float(spec, value, ft_float_to_scientific, &(size[1]));
	size[1] -= remove_trailing_zeros(res[1]);
	if (size[0] < size[1])
		free(res[1]);
	else
	{
		size[0] = size[1];
		free(res[0]);
		res[0] = res[1];
	}
	if (upper_case)
		ft_strtoupper(res[0]);
	print(spec, res[0], size[0], true);
}
