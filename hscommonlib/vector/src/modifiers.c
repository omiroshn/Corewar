/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:29:01 by Admin             #+#    #+#             */
/*   Updated: 2018/08/21 01:49:14 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_private.h"
#include <scalar.h>
#include <assert.h>

void	vector_push_back(t_vector *v, void *data)
{
	size_t new_capacity;

	pthread_rwlock_wrlock(&v->rwlock);
	if (v->size == v->capacity)
	{
		new_capacity = v->size + MAX(v->size * GROWTH_RATE, MIN_GROWTH);
		v->data = realloc(v->data, new_capacity * v->fnc.size_of);
		v->capacity = new_capacity;
	}
	v->fnc.copy(v->data + v->size * v->fnc.size_of, data);
	++v->size;
	pthread_rwlock_unlock(&v->rwlock);
}

void	*vector_read(t_vector *vector, size_t index)
{
	void	*ret;
	size_t	offset;

	pthread_rwlock_rdlock(&vector->rwlock);
	assert(index < vector->size);
	offset = index * vector->fnc.size_of;
	ret = vector->data + offset;
	pthread_rwlock_unlock(&vector->rwlock);
	return (ret);
}
