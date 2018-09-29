/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:43:19 by hshakula          #+#    #+#             */
/*   Updated: 2016/12/17 14:53:19 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_getword(const char *s, char c, int *i)
{
	char	*str;
	int		k;

	if (!(str = malloc(ft_strclen(s, c) + 1)))
		return (NULL);
	k = 0;
	while (s[*i] != c && s[*i])
	{
		str[k] = s[*i];
		k++;
		*i += 1;
	}
	str[k] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}

char	*ft_getsword(const char *s, char *c, int *i)
{
	const int	len = ft_strslen(s + *i, c);
	char		*str;

	if (!(str = malloc(len + 1)))
		return (NULL);
	ft_strncpy(str, s + *i, len);
	str[len] = '\0';
	*i += len;
	while (ft_strchr(c, s[*i]) != NULL && s[*i])
		*i += 1;
	return (str);
}
