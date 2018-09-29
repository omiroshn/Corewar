/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_hashmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 09:11:16 by hshakula          #+#    #+#             */
/*   Updated: 2018/06/19 20:09:33 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap_private.h"

static bool	hashmap_add_key(t_hashmap map, t_entry *entry, const void *key)
{
	if (map->key_alloc)
	{
		entry->key = map->key_alloc(key);
		if (!entry->key)
			return (false);
	}
	else
		entry->key = (void*)key;
	++map->num_entries;
	return (true);
}

void		*hashmap_put(t_hashmap map, const void *key, void *data)
{
	t_entry	*entry;

	if (map->table_size <= hashmap_table_min_size_calc(map->num_entries))
		hashmap_rehash(map, map->table_size << 1);
	entry = hashmap_entry_find(map, key, true);
	if (!entry)
	{
		if (hashmap_rehash(map, map->table_size << 1) < 0)
			return (NULL);
		entry = hashmap_entry_find(map, key, true);
		if (!entry)
			return (NULL);
	}
	if (!entry->key)
	{
		if (!hashmap_add_key(map, entry, key))
			return (NULL);
	}
	else if (entry->data)
		return (entry->data);
	entry->data = data;
	return (data);
}

void		*hashmap_get(const t_hashmap map, const void *key)
{
	t_entry	*entry;

	if (key == NULL)
		return (NULL);
	entry = hashmap_entry_find(map, key, false);
	if (!entry)
		return (NULL);
	return (entry->data);
}

void		*hashmap_pop(t_hashmap map, const void *key)
{
	t_entry	*entry;
	void	*ret;

	if (key == NULL)
		return (NULL);
	entry = hashmap_entry_find(map, key, false);
	if (!entry)
		return (NULL);
	--map->num_entries;
	ret = entry->data;
	entry->key = NULL;
	entry->data = NULL;
	return (ret);
}

void		hashmap_iterate(
				t_hashmap map,
				void (*iter)(t_entry entry, void *ctx),
				void *ctx)
{
	t_entry	entry;
	size_t	i;

	i = 0;
	while (i < map->table_size)
	{
		entry = map->table[i];
		if (entry.key != NULL)
			iter(entry, ctx);
		++i;
	}
}
