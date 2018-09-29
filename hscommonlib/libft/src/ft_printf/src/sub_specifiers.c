/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_specifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 15:06:54 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include "print.h"
#include "libft.h"

const char *g_length_sub_specifiers = "hljzLt";

t_length_type	str_to_length_type(char *s, int *size)
{
	t_length_type type;

	*size = 0;
	type = length_types_total;
	if (ft_strchr(g_length_sub_specifiers, *s) != NULL)
		(*size)++;
	if (*s == 'h')
	{
		type = h_length;
		if (*(s + 1) == 'h' && (*size)++)
			type = hh_length;
	}
	else if (*s == 'l' || *s == 't')
	{
		type = l_length;
		if (*(s + 1) == 'l' && (*size)++)
			type = ll_length;
	}
	else if (*s == 'j')
		type = j_length;
	else if (*s == 'z')
		type = z_length;
	else if (*s == 'L')
		type = L_length;
	return (type);
}

char			*parse_precision(char *s, struct s_specifier *spec, va_list ap)
{
	spec->precision = PRECISION_NOT_SET;
	while (*s == '.')
	{
		++s;
		if (*s == '*')
		{
			spec->precision = va_arg(ap, int);
			if (spec->precision < 0)
				spec->precision = PRECISION_NOT_SET;
			++s;
		}
		else
		{
			spec->precision = ft_atoi_end(s, &s);
			if (spec->precision < 0)
			{
				spec->min_width = -spec->precision;
				spec->flags.left_justification = true;
				spec->precision = 0;
			}
		}
	}
	return (s);
}

char			*parse_length_type(char *s, t_length_type *type)
{
	int				size;
	t_length_type	candidate;

	while ((candidate = str_to_length_type(s, &size)) != length_types_total)
	{
		if (*type < candidate)
			*type = candidate;
		s += size;
	}
	return (s);
}

char			*parse_min_width(char *s, struct s_specifier *spec, va_list ap)
{
	while (*s == '*' || ft_isdigit(*s))
	{
		if (*s == '*')
		{
			spec->min_width = va_arg(ap, int);
			++s;
		}
		else
			spec->min_width = ft_atoi_end(s, &s);
		if (spec->min_width < 0)
			spec->flags.left_justification = true;
		spec->min_width = ABS(spec->min_width);
	}
	return (s);
}
