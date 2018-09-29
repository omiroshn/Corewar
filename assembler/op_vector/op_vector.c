/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:34:49 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/05 18:29:02 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "op_vector.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

struct s_op_vector	*op_vector_init(void)
{
	struct s_op_vector	*ret;

	ret = malloc(sizeof(struct s_op_vector));
	ret->capacity = CHAMP_MAX_SIZE + sizeof(t_header);
	ret->data = malloc(ret->capacity);
	ret->size = 0;
	return (ret);
}

void				op_vector_release(struct s_op_vector *vector)
{
	if (vector == NULL)
		return ;
	free(vector->data);
	free(vector);
}

bool				op_vector_write(
						struct s_op_vector *vector,
						const void *data,
						size_t size)
{
	if (vector->size + size >= vector->capacity)
		return (false);
	ft_memcpy(vector->data + vector->size, data, size);
	vector->size += size;
	return (true);
}

bool				op_vector_save_to_file(
						struct s_op_vector *vector,
						const char *path)
{
	int		fd;
	ssize_t	ret;

	if ((fd = open(path, O_CREAT | O_TRUNC | O_WRONLY,
					S_IRWXU | S_IRWXG | S_IROTH)) == -1)
	{
		perror("File");
		return (false);
	}
	ret = write(fd, vector->data, vector->size);
	close(fd);
	return (ret == vector->size);
}
