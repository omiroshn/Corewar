/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:45:41 by admin             #+#    #+#             */
/*   Updated: 2018/08/21 01:47:52 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_private.h"
#include <stdlib.h>
#include <scalar.h>

void	vector_resize(t_vector *v, size_t new_size)
{
	pthread_rwlock_wrlock(&v->rwlock);
	v->data = realloc(v->data, new_size);
	v->size = new_size;
	v->capacity = new_size;
	pthread_rwlock_unlock(&v->rwlock);
}

void	vector_reserve(t_vector *v, size_t size)
{
	pthread_rwlock_wrlock(&v->rwlock);
	if (v->capacity <= size)
		return ;
	v->capacity = size;
	v->data = realloc(v->data, size);
	pthread_rwlock_unlock(&v->rwlock);
}
