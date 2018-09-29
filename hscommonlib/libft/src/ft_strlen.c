/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 15:08:50 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen(const char *str)
{
	register char *s;

	s = (char*)str;
	while (*s)
		++s;
	return ((int)(s - str));
}

int		ft_strclen(const char *str, char c)
{
	register char *s;

	s = (char*)str;
	while (*s && *s != c)
		++s;
	return ((int)(s - str));
}

int		ft_strslen(const char *str, const char *c)
{
	register char *s;

	s = (char*)str;
	while (*s && ft_strchr(c, *s) == NULL)
		++s;
	return ((int)(s - str));
}
