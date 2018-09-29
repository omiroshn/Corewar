/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 15:06:05 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include "print.h"
#include "buffer_manager.h"
#include "casts/casts.h"
#include "padding.h"
#include "libft.h"

extern struct s_bufman g_bufman;

const char *g_known_specifiers = "sScCpdDiuUoOxXbBfFeEgG";

const char *g_string_specifiers = "sScC";
const char *g_number_specifiers = "pdDiuUoOxXbBfFeEgG";
const char *g_decimal_specifiers = "dDiuU";
const char *g_radix_specifiers = "oOxXbB";

void	process_string_specifier(struct s_specifier *spec, va_list ap)
{
	if (ft_isupper(spec->symb))
	{
		spec->length_type = l_length;
		spec->symb = ft_tolower(spec->symb);
	}
	if (spec->symb == 'c')
		print_character(spec, ap);
	else
		print_string(spec, ap);
}

void	process_radix_specifier(struct s_specifier *spec, va_list ap)
{
	bool upper_case;

	upper_case = ft_isupper(spec->symb);
	if (upper_case)
	{
		spec->symb = ft_tolower(spec->symb);
		if (spec->symb == 'o')
			spec->length_type = MAX(spec->length_type, l_length);
	}
	if (spec->symb == 'o')
		print_octa(spec, ap, upper_case);
	if (spec->symb == 'x')
		print_hexa(spec, ap, upper_case);
	if (spec->symb == 'b')
		print_binary(spec, ap, upper_case);
}

void	process_floating_point_specifier(struct s_specifier *spec, va_list ap)
{
	bool upper_case;

	upper_case = ft_isupper(spec->symb);
	if (upper_case)
		spec->symb = ft_tolower(spec->symb);
	if (spec->symb == 'f')
		print_float(spec, ap, upper_case);
	else if (spec->symb == 'e')
		print_scientific(spec, ap, upper_case);
	else if (spec->symb == 'g')
		print_shortest_float(spec, ap, upper_case);
}

void	process_number_specifier(struct s_specifier *spec, va_list ap)
{
	if (ft_strchr(g_decimal_specifiers, spec->symb) != NULL)
	{
		if (ft_isupper(spec->symb))
		{
			spec->symb = ft_tolower(spec->symb);
			spec->length_type = MAX(spec->length_type, l_length);
		}
		if (spec->symb == 'd' || spec->symb == 'i')
			print_signed_integer(spec, ap);
		else
			print_unsigned_integer(spec, ap);
	}
	else if (spec->symb == 'p')
		print_pointer(spec, ap);
	else if (ft_strchr(g_radix_specifiers, spec->symb) != NULL)
		process_radix_specifier(spec, ap);
	else
		process_floating_point_specifier(spec, ap);
}

char	*process_specifier(char *s, va_list ap)
{
	struct s_specifier	specifier;
	int					*n;

	if (*s == '\0')
		return (s);
	ft_memset(&specifier, 0, sizeof(struct s_specifier));
	s = parse_sub_specifiers(s, &specifier, ap);
	if (specifier.symb == '\0')
		return (s - 1);
	if (ft_strchr(g_string_specifiers, specifier.symb) != NULL)
		process_string_specifier(&specifier, ap);
	else if (ft_strchr(g_number_specifiers, specifier.symb) != NULL)
		process_number_specifier(&specifier, ap);
	else if (specifier.symb == 'n')
	{
		n = va_arg(ap, int*);
		if (n != NULL)
			*n = g_bufman.total_size + g_bufman.curr_size;
	}
	else
		print(&specifier, &specifier.symb, 1, false);
	return (s);
}
