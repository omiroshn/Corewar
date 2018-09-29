/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_type_descriptors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:42:38 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/16 01:02:44 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap_private.h"
#include "key_funcs.h"

struct s_key_descriptor g_key_type_descriptors[kHashmapKeyTypesTotal] =
{
	{
		.hash_func = hash_string,
		.alloc_func = alloc_string,
		.free_func = free,
		.compare_func = compare_string
	},
	{
		.hash_func = hash_string,
		.alloc_func = NULL,
		.free_func = NULL,
		.compare_func = compare_string
	},
	{
		.hash_func = hash_int,
		.alloc_func = NULL,
		.free_func = NULL,
		.compare_func = compare_int
	}
};
