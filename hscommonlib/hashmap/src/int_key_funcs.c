/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_key_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 00:55:32 by Admin             #+#    #+#             */
/*   Updated: 2018/09/16 01:03:37 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_funcs.h"

size_t	hash_int(const void *key)
{
	unsigned int x;

	x = *((unsigned int*)key);
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = (x >> 16) ^ x;
	return (x);
}

int		compare_int(const void *lhs, const void *rhs)
{
	return (*((int*)lhs) - *((int*)rhs));
}
