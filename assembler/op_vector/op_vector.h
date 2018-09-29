/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:34:49 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:28:33 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_VECTOR_H
# define OP_VECTOR_H

# include <stddef.h>

struct				s_op_vector
{
	void		*data;
	size_t		size;
	size_t		capacity;
};

struct s_op_vector	*op_vector_init(void);
void				op_vector_release(struct s_op_vector *vector);
bool				op_vector_write(
						struct s_op_vector *vector,
						const void *data,
						size_t size);
bool				op_vector_save_to_file(
						struct s_op_vector *vector,
						const char *path);

#endif
