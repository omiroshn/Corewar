/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 15:09:21 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char *s1_ptr;

	s1_ptr = s1;
	while (n--)
	{
		if (*s2)
			*s1++ = *s2++;
		else
			*s1++ = '\0';
	}
	return (s1_ptr);
}

char	*ft_emplace_string(char *dst, const char *src, int pos)
{
	const int	len = ft_strlen(dst) + ft_strlen(src);
	char		*res;

	res = malloc(len + 1);
	ft_strncpy(res, dst, pos);
	ft_strcpy(res + pos, src);
	ft_strcpy(res + pos + ft_strlen(src), dst + pos);
	res[len] = '\0';
	free(dst);
	return (res);
}
