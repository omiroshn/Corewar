/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:32:23 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "print.h"
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

const double g_pow10[g_max_ftoa_precision] = {
	1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0,
	100000000.0, 1000000000.0, 10000000000.0, 100000000000.0, 1000000000000.0,
	10000000000000.0, 100000000000000.0, 1000000000000000.0,
	10000000000000000.0, 100000000000000000.0 };
const int g_ftoa_buff_size = 128;

void	ft_ftoa_get_value_info(struct s_ftoa *f, double *value)
{
	if ((f->is_negative = (*value < 0.0) ? 1 : 0))
		*value = -(*value);
	f->int_part = (intmax_t)(*value);
	f->floating_frac = ((*value) - f->int_part) * g_pow10[f->precision];
	f->frac = (uintmax_t)f->floating_frac;
	f->frac_diff = f->floating_frac - f->frac;
	if (f->frac_diff > 0.5)
	{
		++f->frac;
		if (f->frac >= g_pow10[f->precision])
		{
			f->frac = 0;
			++f->int_part;
		}
	}
	else if (f->frac_diff == 0.5 && ((f->frac == 0) || (f->frac & 1)))
		++f->frac;
}

void	ft_ftoa_write_frac_part(struct s_ftoa *f,
								double value,
								int *size,
								int count)
{
	if (f->precision == 0)
	{
		f->frac_diff = value - (double)f->int_part;
		if (f->frac_diff > 0.5)
			++f->int_part;
		else if ((f->frac_diff == 0.5) && (f->int_part & 1))
			++f->int_part;
		if (f->force_decimal_point)
			f->buf[(*size)++] = '.';
	}
	else
	{
		while (true)
		{
			--count;
			f->buf[(*size)++] = (char)('0' + (f->frac % 10));
			if ((*size) >= g_ftoa_buff_size || (f->frac /= 10) == 0)
				break ;
		}
		while (((*size) < g_ftoa_buff_size) && (count-- > 0))
			f->buf[(*size)++] = '0';
		if ((*size) < g_ftoa_buff_size)
			f->buf[(*size)++] = '.';
	}
}

int		ft_ftoa_value_exponent(double value)
{
	int exp;

	exp = 0;
	while ((value < 1.0 || value >= 10.0) && value != 0.0)
	{
		if (value < 1.0)
		{
			value *= 10.0;
			--exp;
		}
		else
		{
			value *= 0.1;
			++exp;
		}
	}
	return (exp);
}

char	*ft_float_to_scientific(double value,
							int precision,
							int *size,
							bool force_decimal_point)
{
	const int	exp = ft_ftoa_value_exponent(value < 0.0 ? -value : value);
	char		*exp_str;
	int			exp_str_len;
	char		*res;

	exp_str_len = 1;
	exp_str = ft_strdup("e");
	(exp >= 0) ? exp_str = ft_strjoin_front(exp_str, "+") : 0;
	exp_str = ft_strjoin_both(exp_str, ft_itoa_base(exp, 10, size));
	(exp < 0) ? (--(*size)) : 0;
	++exp_str_len;
	if (ABS(exp) < 10)
	{
		exp_str = ft_emplace_string(exp_str, "0", exp_str_len);
		++exp_str_len;
	}
	exp_str_len += *size;
	if (exp > 0)
		value /= ft_fpower(10.0, exp);
	else
		value *= ft_fpower(10.0, -exp);
	res = ft_ftoa(value, precision, size, force_decimal_point);
	res = ft_strjoin_both(res, exp_str);
	*size += exp_str_len;
	return (res);
}

char	*ft_ftoa(double value,
				int precision,
				int *size,
				bool force_decimal_point)
{
	struct s_ftoa f;

	*size = 0;
	if (value > (double)INTMAX_MAX)
		return (ft_strdup(""));
	f.precision = precision;
	f.force_decimal_point = force_decimal_point;
	ft_ftoa_get_value_info(&f, &value);
	ft_ftoa_write_frac_part(&f, value, size, f.precision);
	while ((*size) < g_ftoa_buff_size)
	{
		f.buf[(*size)++] = (char)('0' + (f.int_part % 10));
		if (!(f.int_part /= 10))
			break ;
	}
	if ((*size) < g_ftoa_buff_size && f.is_negative)
		f.buf[(*size)++] = '-';
	f.buf[(*size)] = '\0';
	ft_strrev(f.buf);
	return (ft_strdup(f.buf));
}
