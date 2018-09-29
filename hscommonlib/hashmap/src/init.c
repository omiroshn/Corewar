/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:31:50 by hshakula          #+#    #+#             */
/*   Updated: 2018/06/22 13:44:28 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap_private.h"
#include "libft.h"
#include <assert.h>
#include "ft_printf.h"

t_hashmap	hashmap_common_init(size_t initial_size)
{
	t_hashmap map;

	if ((map = malloc(sizeof(struct s_hashmap))) == NULL)
		return (NULL);
	if (!initial_size)
		initial_size = 512;
	else
		initial_size = hashmap_table_size_calc(initial_size);
	map->table_size = initial_size;
	map->num_entries = 0;
	map->table = (t_entry *)malloc(initial_size * sizeof(t_entry));
	if (!map->table)
	{
		free(map);
		return (NULL);
	}
	ft_memset(map->table, 0, initial_size * sizeof(t_entry));
	return (map);
}

void		hashmap_set_key_funcs(t_hashmap map,
								struct s_key_descriptor *desc)
{
	map->hash = desc->hash_func;
	map->key_compare = desc->compare_func;
	map->key_alloc = desc->alloc_func;
	map->key_free = desc->free_func;
}

t_hashmap	hashmap_init_custom(size_t initial_size,
								struct s_key_descriptor *descriptor)
{
	t_hashmap map;

	map = hashmap_common_init(initial_size);
	hashmap_set_key_funcs(map, descriptor);
	return (map);
}

t_hashmap	hashmap_init(size_t initial_size, t_hashmap_key_type type)
{
	t_hashmap map;

	assert(type >= 0 && type < kHashmapKeyTypesTotal);
	map = hashmap_common_init(initial_size);
	hashmap_set_key_funcs(map, &g_key_type_descriptors[type]);
	return (map);
}

void		hashmap_destroy(t_hashmap map, t_value_free_func data_del)
{
	const t_entry	*table_end = map->table + map->table_size;
	t_entry			*entry;

	entry = map->table;
	if (map->key_free || data_del)
	{
		while (entry < table_end)
		{
			if (entry->key != NULL)
			{
				if (map->key_free != NULL)
					map->key_free(entry->key);
				if (entry->data != NULL && data_del != NULL)
					data_del(entry->data);
			}
			++entry;
		}
	}
	free(map->table);
	free(map);
}
