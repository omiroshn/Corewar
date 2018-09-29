/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 15:03:22 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "specifier.h"
#include "buffer_manager.h"
#include "libft.h"

extern struct s_bufman g_bufman;

int		ft_wstrlen(wchar_t *wstr, int *buf_size)
{
	wchar_t *w;

	w = wstr;
	*buf_size = 0;
	while (*w)
	{
		*buf_size += wchar_len(*w);
		w++;
	}
	return ((int)(w - wstr));
}

int		num_of_wchar_in(wchar_t *wstr, int precision, int *bytes)
{
	wchar_t	*w;
	int		b;

	w = wstr;
	*bytes = 0;
	while (*w)
	{
		b = wchar_len(*w);
		if (precision != PRECISION_NOT_SET && (*bytes + b) > precision)
			break ;
		*bytes += b;
		w++;
	}
	return ((int)(w - wstr));
}

void	print_wstring(struct s_specifier *spec, va_list ap)
{
	const char	padding_char = spec->flags.padding_with_zeros ? '0' : ' ';
	char		wchar_buf[4];
	wchar_t		*wstr;
	int			print_len;
	int			bytes_num;

	wstr = va_arg(ap, wchar_t*);
	if (wstr == NULL)
		wstr = L"(null)";
	print_len = num_of_wchar_in(wstr, spec->precision, &bytes_num);
	if (spec->min_width > bytes_num && !spec->flags.left_justification)
		print_padding(padding_char, spec->min_width - bytes_num);
	while (*wstr && print_len)
	{
		print_to_buffer(wchar_buf, print_wchar_to_buffer(*wstr, wchar_buf));
		--print_len;
		++wstr;
	}
	if (spec->min_width > bytes_num && spec->flags.left_justification)
		print_padding(padding_char, spec->min_width - bytes_num);
}

void	print_string(struct s_specifier *spec, va_list ap)
{
	char	*res;
	int		len;

	if (spec->length_type == none_length)
	{
		res = va_arg(ap, char*);
		if (res == NULL)
			res = "(null)";
		len = ft_strlen(res);
		if (spec->precision != PRECISION_NOT_SET)
			len = MIN(len, spec->precision);
		print(spec, res, len, false);
	}
	else
		print_wstring(spec, ap);
}
