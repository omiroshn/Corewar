/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_key_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:43:55 by hshakula          #+#    #+#             */
/*   Updated: 2018/06/22 12:49:44 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_funcs.h"
#include "libft.h"

size_t	hash_string(const void *key)
{
	register const char	*key_str;
	size_t				hash;

	key_str = (const char *)key;
	hash = 0;
	while (*key_str)
	{
		hash += *key_str;
		hash += (hash << 10);
		hash ^= (hash >> 6);
		++key_str;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}

int		compare_string(const void *a, const void *b)
{
	return (ft_strcmp((const char *)a, (const char *)b));
}

void	*alloc_string(const void *key)
{
	return ((void *)ft_strdup((char *)key));
}
