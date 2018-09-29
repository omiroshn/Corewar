/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/15 01:06:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char*)s);
	else
		return (NULL);
}

char	*ft_strrmchar(char *str, const char *rm_chars)
{
	char *src;
	char *dst;

	src = str;
	dst = str;
	while (*src != '\0')
	{
		*dst = *src;
		if (ft_strchr(rm_chars, *dst) == NULL)
			dst++;
		++src;
	}
	*dst = '\0';
	return (str);
}

char	*ft_strremovespaces(char *str)
{
	return (ft_strrmchar(str, SPACE_CHARS));
}
