/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 01:02:10 by admin             #+#    #+#             */
/*   Updated: 2018/08/15 20:49:04 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

inline t_mat4		mat4_translation(t_vec3 t)
{
	t_mat4 res;

	res = mat4_identity();
	res.col[3] = vec4_init_vec3(t, 1.0f);
	return (res);
}

inline t_mat4		mat4_scale(t_vec3 scale)
{
	t_mat4 res;

	res = mat4_identity();
	res.m11 = scale.x;
	res.m22 = scale.y;
	res.m33 = scale.z;
	res.m44 = 1.0f;
	return (res);
}

inline t_mat4		mat4_uniform_scale(float scale)
{
	t_mat4 res;

	res = mat4_identity();
	res.m11 = scale;
	res.m22 = scale;
	res.m33 = scale;
	res.m44 = 1.0f;
	return (res);
}

inline t_mat4		mat4_rotation(t_vec3 axis, float angle)
{
	const float	c = cosf(angle);
	const float	s = sinf(angle);
	t_mat4		res;

	res.col[0].x = axis.x * axis.x + (1 - axis.x * axis.x) * c;
	res.col[0].y = axis.x * axis.y * (1 - c) - axis.z * s;
	res.col[0].z = axis.x * axis.z * (1 - c) + axis.y * s;
	res.col[0].w = 0.0;
	res.col[1].x = axis.x * axis.y * (1 - c) + axis.z * s;
	res.col[1].y = axis.y * axis.y + (1 - axis.y * axis.y) * c;
	res.col[1].z = axis.y * axis.z * (1 - c) - axis.x * s;
	res.col[1].w = 0.0;
	res.col[2].x = axis.x * axis.z * (1 - c) - axis.y * s;
	res.col[2].y = axis.y * axis.z * (1 - c) + axis.x * s;
	res.col[2].z = axis.z * axis.z + (1 - axis.z * axis.z) * c;
	res.col[2].w = 0.0;
	res.col[3].x = 0.0;
	res.col[3].y = 0.0;
	res.col[3].z = 0.0;
	res.col[3].w = 1.0;
	return (res);
}
