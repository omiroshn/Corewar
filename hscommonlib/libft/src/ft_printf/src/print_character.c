/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:36:57 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "specifier.h"
#include "buffer_manager.h"
#include "padding.h"
#include "libft.h"
#include <stdlib.h>

void	check_current_locale(wchar_t wchar)
{
	if (wchar_len(wchar) == 0)
		set_buffer_error();
}

int		wchar_len(wchar_t wchar)
{
	if (wchar < 0x0)
		return (0);
	if ((wchar <= 0x7f && MB_CUR_MAX >= 1) ||
		(wchar <= 0xff && MB_CUR_MAX == 1))
		return (1);
	else if (wchar <= 0x7ff && MB_CUR_MAX >= 2)
		return (2);
	else if (wchar <= 0xffff && MB_CUR_MAX >= 3)
		return (3);
	else if (wchar <= 0x10ffff && MB_CUR_MAX >= 4)
		return (4);
	else
		return (0);
}

int		print_wchar_to_buffer(wchar_t w, char buf[4])
{
	check_current_locale(w);
	if ((w <= 0x7f && MB_CUR_MAX >= 1) || (w <= 0xff && MB_CUR_MAX == 1))
		buf[0] = (char)w;
	else if (w <= 0x7ff && MB_CUR_MAX >= 2)
	{
		buf[0] = (char)((w >> 6) + 0xc0);
		buf[1] = (char)((w & 0x3f) + 0x80);
		return (2);
	}
	else if (w <= 0xffff && MB_CUR_MAX >= 3)
	{
		buf[0] = (char)((w >> 12) + 0xe0);
		buf[1] = (char)(((w >> 6) & 0x3f) + 0x80);
		buf[2] = (char)((w & 0x3f) + 0x80);
		return (3);
	}
	else if (w <= 0x10ffff && MB_CUR_MAX >= 4)
	{
		buf[0] = (char)((w >> 18) + 0xf0);
		buf[1] = (char)(((w >> 12) & 0x3f) + 0x80);
		buf[2] = (char)(((w >> 6) & 0x3f) + 0x80);
		buf[3] = (char)((w & 0x3f) + 0x80);
		return (4);
	}
	return (1);
}

void	print_character(struct s_specifier *spec, va_list ap)
{
	char	buf[4];
	int		size;

	if (spec->length_type == none_length)
	{
		buf[0] = (char)va_arg(ap, int);
		print(spec, buf, 1, false);
	}
	else
	{
		size = print_wchar_to_buffer((wchar_t)va_arg(ap, void*), buf);
		print(spec, buf, size, false);
	}
}
