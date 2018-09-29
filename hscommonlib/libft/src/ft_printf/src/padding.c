/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:33:57 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "padding.h"
#include "libft.h"
#include <stdlib.h>

char	*append_padding(char *str, char padding, int size, bool front)
{
	char		*res;
	const int	str_len = ft_strlen(str);
	int			i;

	res = malloc(size + str_len + 1);
	i = -1;
	if (front)
	{
		while (++i < size)
			res[i] = padding;
		ft_strcpy(res + i, str);
	}
	else
	{
		ft_strcpy(res, str);
		while (++i < size)
			res[i + str_len] = padding;
	}
	res[size + str_len] = '\0';
	free((void*)str);
	return (res);
}

char	*padding_string(char padding, int size)
{
	char *res;

	res = malloc(size + 1);
	res[size] = '\0';
	while (size--)
		res[size] = padding;
	return (res);
}
