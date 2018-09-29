/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 15:09:35 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	const int	s1_len = ft_strlen(s1);
	char		*str;

	if (!(str = malloc(s1_len + ft_strlen((char*)s2) + 1)))
		return (NULL);
	ft_strcpy(str, (char*)s1);
	ft_strcpy(str + s1_len, (char*)s2);
	return (str);
}

char	*ft_strjoin_front(char *s1, char *s2)
{
	const int	s1_len = ft_strlen(s1);
	char		*str;

	if (!(str = malloc(s1_len + ft_strlen((char*)s2) + 1)))
		return (NULL);
	ft_strcpy(str, (char*)s1);
	free((void*)s1);
	ft_strcpy(str + s1_len, (char*)s2);
	return (str);
}

char	*ft_strjoin_back(char *s1, char *s2)
{
	const int	s1_len = ft_strlen(s1);
	char		*str;

	if (!(str = malloc(s1_len + ft_strlen((char*)s2) + 1)))
		return (NULL);
	ft_strcpy(str, (char*)s1);
	ft_strcpy(str + s1_len, (char*)s2);
	free((void*)s2);
	return (str);
}

char	*ft_strjoin_both(char *s1, char *s2)
{
	const int	s1_len = ft_strlen(s1);
	char		*str;

	if (!(str = malloc(s1_len + ft_strlen((char*)s2) + 1)))
		return (NULL);
	ft_strcpy(str, (char*)s1);
	ft_strcpy(str + s1_len, (char*)s2);
	free((void*)s1);
	free((void*)s2);
	return (str);
}
