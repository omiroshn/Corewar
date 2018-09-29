/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:31:50 by hshakula          #+#    #+#             */
/*   Updated: 2018/06/19 20:11:33 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap_private.h"
#include "libft.h"

inline static size_t	hashmap_calc_index(const t_hashmap map,
											const void *key)
{
	return (map->hash(key) & (map->table_size - 1));
}

t_entry					*hashmap_entry_find(const t_hashmap map,
											const void *key,
											bool find_empty)
{
	register size_t	i;
	size_t			index;
	size_t			probe_len;
	t_entry			*entry;

	probe_len = map->table_size >> 1;
	index = hashmap_calc_index(map, key);
	i = 0;
	while (i < probe_len)
	{
		entry = &map->table[index];
		if (!entry->key)
		{
			if (find_empty)
				return (entry);
			return (NULL);
		}
		if (map->key_compare(key, entry->key) == 0)
			return (entry);
		index = (index + 1) & (map->table_size - 1);
		++i;
	}
	return (NULL);
}

inline static char		rehash(t_hashmap map,
								t_entry *old_table,
								size_t old_size,
								t_entry **new_table)
{
	t_entry *entry;
	t_entry *new_entry;

	entry = old_table;
	while (entry < old_table + old_size)
	{
		if (!entry->data)
		{
			entry++;
			continue;
		}
		new_entry = hashmap_entry_find(map, entry->key, true);
		if (!new_entry)
		{
			map->table_size = old_size;
			map->table = old_table;
			free(*new_table);
			return (-1);
		}
		new_entry->key = entry->key;
		new_entry->data = entry->data;
		entry++;
	}
	return (0);
}

int						hashmap_rehash(t_hashmap map,
										size_t new_size)
{
	size_t		old_size;
	t_entry		*old_table;
	t_entry		*new_table;

	if (!(new_table = (t_entry *)malloc(new_size * sizeof(t_entry))))
		return (-1);
	ft_memset(new_table, 0, new_size * sizeof(t_entry));
	old_size = map->table_size;
	old_table = map->table;
	map->table_size = new_size;
	map->table = new_table;
	if (rehash(map, old_table, old_size, &new_table) < 0)
		return (-1);
	free(old_table);
	return (0);
}
