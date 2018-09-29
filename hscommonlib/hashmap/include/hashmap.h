/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 09:11:16 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 14:01:33 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stdlib.h>

typedef struct s_entry		t_entry;
typedef struct s_hashmap	*t_hashmap;

typedef void		*(*t_key_alloc_func)(const void *key);
typedef void		(*t_key_free_func)(void *key);
typedef int			(*t_key_compare_func)(const void *rhs, const void *lhs);
typedef size_t		(*t_key_hash_func)(const void *key);
typedef void		(*t_value_free_func)(void *value);

struct			s_entry
{
	void		*key;
	void		*data;
};

struct			s_key_descriptor
{
	t_key_hash_func		hash_func;
	t_key_alloc_func	alloc_func;
	t_key_free_func		free_func;
	t_key_compare_func	compare_func;
};

typedef enum	e_hashmap_key_type
{
	kHashmapKeyTypeString = 0,
	kHashmapKeyTypeStackString,
	kHashmapKeyTypeInt,
	kHashmapKeyTypesTotal
}				t_hashmap_key_type;

t_hashmap		hashmap_init(size_t initial_size, t_hashmap_key_type type);
t_hashmap		hashmap_init_custom(size_t initial_size,
									struct s_key_descriptor *descriptor);

void			*hashmap_put(t_hashmap map, const void *key, void *data);
void			*hashmap_get(const t_hashmap map, const void *key);
void			*hashmap_pop(t_hashmap map, const void *key);

void			hashmap_iterate(
					t_hashmap map,
					void (*iter)(t_entry entry, void *ctx),
					void *ctx);

void			hashmap_destroy(t_hashmap map, t_value_free_func data_del);

#endif
