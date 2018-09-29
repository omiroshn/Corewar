/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:23:53 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "specifier.h"
#include "print.h"
#include "libft.h"

extern const char *g_known_specifiers;
const char *g_known_flags = "#0-+ ";

char	*parse_flags(char *s, struct s_flags *flags)
{
	while (*s != '\0' && ft_strchr(g_known_flags, *s) != NULL)
	{
		if (*s == '#')
			flags->special = true;
		else if (*s == '0')
			flags->padding_with_zeros = true;
		else if (*s == '-')
			flags->left_justification = true;
		else if (*s == '+')
			flags->force_sign_preceding = true;
		else if (*s == ' ')
			flags->put_space_instead_of_sign = true;
		++s;
	}
	if (flags->left_justification)
		flags->padding_with_zeros = false;
	return (s);
}

char	*parse_sub_specifiers(char *s, struct s_specifier *spec, va_list ap)
{
	ft_memset(&spec->flags, 0, sizeof(struct s_flags));
	s = parse_flags(s, &spec->flags);
	s = parse_min_width(s, spec, ap);
	s = parse_flags(s, &spec->flags);
	s = parse_precision(s, spec, ap);
	s = parse_flags(s, &spec->flags);
	s = parse_length_type(s, &spec->length_type);
	s = parse_flags(s, &spec->flags);
	spec->symb = *s;
	if (spec->length_type == L_length &&
		ft_strchr("eEfFgG", spec->symb) == NULL)
		spec->length_type = ll_length;
	return (s + 1);
}
