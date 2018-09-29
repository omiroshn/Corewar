/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:28:17 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/21 09:35:32 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_private.h"
#include <assert.h>

t_vector_type_fnc g_vector_fncs[kVectorValueSizeCustom] =
{
	{
		.copy = copy_8bit,
		.del = delete_placeholder,
		.default_value = default_8bit_value,
		.size_of = sizeof(uint8_t)
	},
	{
		.copy = copy_16bit,
		.del = delete_placeholder,
		.default_value = default_16bit_value,
		.size_of = sizeof(uint16_t)
	},
	{
		.copy = copy_32bit,
		.del = delete_placeholder,
		.default_value = default_32bit_value,
		.size_of = sizeof(uint32_t)
	},
	{
		.copy = copy_64bit,
		.del = delete_placeholder,
		.default_value = default_64bit_value,
		.size_of = sizeof(uint64_t)
	}
};

t_vector	*vector_new(
	t_vector_type type,
	size_t initial_capacity,
	t_vector_type_fnc *vector_fncs)
{
	t_vector *vector;

	vector = malloc(sizeof(t_vector));
	vector->ref_count = 1;
	assert(type >= 0);
	if (type < kVectorValueSizeCustom)
		vector->fnc = g_vector_fncs[type];
	else
	{
		assert(vector_fncs != NULL);
		vector->fnc = *vector_fncs;
	}
	vector->size = 0;
	vector->capacity = initial_capacity;
	if (initial_capacity > 0)
		vector->data = malloc(vector->fnc.size_of * initial_capacity);
	pthread_rwlock_init(&vector->rwlock, NULL);
	return (vector);
}

void		vector_release(t_vector *vector)
{
	void	*data;

	pthread_rwlock_wrlock(&vector->rwlock);
	assert(vector->ref_count > 0);
	vector->ref_count--;
	if (vector->ref_count == 0)
	{
		data = vector->data;
		while (vector->size--)
		{
			vector->fnc.del(data);
			data += vector->fnc.size_of;
		}
		pthread_rwlock_unlock(&vector->rwlock);
		pthread_rwlock_destroy(&vector->rwlock);
		free(vector);
		return ;
	}
	pthread_rwlock_unlock(&vector->rwlock);
}
