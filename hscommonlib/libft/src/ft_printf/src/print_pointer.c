/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:52:04 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "specifier.h"
#include "libft.h"
#include "padding.h"
#include <stdlib.h>

void	print_pointer(struct s_specifier *spec, va_list ap)
{
	const uintmax_t	value = (uintmax_t)va_arg(ap, void*);
	int				size;
	char			*res;
	char			*pad_str;

	res = ft_uitoa_base(value, 16, &size);
	if (spec->precision != PRECISION_NOT_SET)
		size = handle_integer_precision(spec, &res, size, value == 0);
	if (spec->flags.padding_with_zeros && spec->min_width > size + 2)
	{
		pad_str = padding_string('0', spec->min_width - size - 2);
		res = ft_emplace_string(res, pad_str, 0);
		free(pad_str);
		size = spec->min_width - 2;
		spec->min_width = 0;
	}
	res = ft_strjoin_back("0x", res);
	size += 2;
	print(spec, res, size, true);
}
