/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:31:50 by hshakula          #+#    #+#             */
/*   Updated: 2018/06/22 12:58:23 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_PRIVATE_H
# define HASHMAP_PRIVATE_H

# include "hashmap.h"
# include <stdbool.h>

struct			s_hashmap
{
	size_t		table_size;
	size_t		num_entries;
	t_entry		*table;
	size_t		(*hash)(const void *);
	int			(*key_compare)(const void *, const void *);
	void		*(*key_alloc)(const void *);
	void		(*key_free)(void *);
};

size_t			hashmap_table_min_size_calc(size_t num_entries);
size_t			hashmap_table_size_calc(size_t num_entries);

t_entry			*hashmap_entry_find(const t_hashmap map,
									const void *key,
									bool empty);
int				hashmap_rehash(t_hashmap map, size_t new_size);

extern struct s_key_descriptor g_key_type_descriptors[kHashmapKeyTypesTotal];

#endif
