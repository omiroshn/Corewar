/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 22:46:06 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:24:36 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_manager.h"
#include "specifier.h"
#include "color.h"

#include <stdlib.h>
#include <stdarg.h>

char	*process_format(char *s, va_list ap)
{
	if (*s == '%')
		s = process_specifier(++s, ap);
	else if (*s == '{')
		s = process_color(s);
	else
		print_to_buffer(s++, 1);
	return (s);
}

int		ft_dprintf(int fd, const char *fmt, ...)
{
	va_list ap;
	char	*s;

	if (fd < 0 || fmt == NULL)
		return (-1);
	reset_buffer(fd, NULL, 0);
	s = (char*)fmt;
	va_start(ap, fmt);
	while (*s != '\0')
		s = process_format(s, ap);
	va_end(ap);
	return (fflush_buffer());
}

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	char	*s;

	if (fmt == NULL)
		return (-1);
	reset_buffer(1, NULL, 0);
	s = (char*)fmt;
	va_start(ap, fmt);
	while (*s != '\0')
		s = process_format(s, ap);
	va_end(ap);
	return (fflush_buffer());
}

int		ft_snprintf(char *dst, size_t size, const char *fmt, ...)
{
	va_list ap;
	char	*s;

	if (fmt == NULL || dst == NULL || size == 0)
		return (-1);
	reset_buffer(-1, dst, size);
	s = (char*)fmt;
	va_start(ap, fmt);
	while (*s != '\0')
		s = process_format(s, ap);
	va_end(ap);
	return (fflush_buffer());
}
