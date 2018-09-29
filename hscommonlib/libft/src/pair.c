/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 23:46:55 by admin             #+#    #+#             */
/*   Updated: 2018/08/22 23:50:35 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

inline t_tuple	make_tuple(void *first, void *second, void *third)
{
	return ((t_tuple){first, second, third});
}

inline t_pair	make_pair(void *first, void *second)
{
	return ((t_pair){first, second});
}

t_pair			*alloc_pair(void *first, void *second)
{
	t_pair	*pair;

	pair = malloc(sizeof(t_pair));
	*pair = (t_pair){first, second};
	return (pair);
}
