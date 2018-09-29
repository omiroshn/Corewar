/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:28:17 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 14:14:16 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include <pthread.h>

typedef enum			e_vector_type
{
	kVectorValueSize8 = 0,
	kVectorValueSize16,
	kVectorValueSize32,
	kVectorValueSize64,
	kVectorValueSizeCustom
}						t_vector_type;

typedef struct			s_vector_type_fnc
{
	void				(*copy)(void *dst, void *src);
	void				(*del)(void *data);
	void				(*default_value)(void *dst);
	size_t				size_of;
}						t_vector_type_fnc;

typedef struct			s_vector
{
	void				*data;
	size_t				size;
	size_t				capacity;
	t_vector_type_fnc	fnc;
	int					ref_count;
	pthread_rwlock_t	rwlock;
}						t_vector;

t_vector				*vector_new(
							t_vector_type type,
							size_t initial_capacity,
							t_vector_type_fnc *vector_fncs);
bool					vector_retain(t_vector *vector);
void					vector_release(t_vector *vector);

/*
** Modifiers
*/
void					vector_push_back(t_vector *vector, void *data);

/*
** Capacity
*/
void					vector_resize(t_vector *vector, size_t new_size);
void					vector_reserve(t_vector *vector, size_t size);

/*
** Element Access
*/
void					*vector_read(t_vector *vector, size_t index);

void					delete_placeholder(void *data);

#endif
