/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_constructors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 00:49:41 by admin             #+#    #+#             */
/*   Updated: 2018/08/15 01:01:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <string.h>

const t_mat4 g_identity_mat4 =
{
	.col =
	{
		(t_vec4){{1.0f, 0.0f, 0.0f, 0.0f}},
		(t_vec4){{0.0f, 1.0f, 0.0f, 0.0f}},
		(t_vec4){{0.0f, 0.0f, 1.0f, 0.0f}},
		(t_vec4){{0.0f, 0.0f, 0.0f, 1.0f}}
	}
};

inline t_mat4		mat4_from_vec4(t_vec4 *v)
{
	return ((t_mat4){{{{v[0], v[1], v[2], v[3]}}}});
}

inline t_mat4		mat4_with_value(float value)
{
	const t_vec4 vec = vec4_init_single(value);

	return ((t_mat4){{{{vec, vec, vec, vec}}}});
}

inline t_mat4		mat4_identity(void)
{
	return (g_identity_mat4);
}
