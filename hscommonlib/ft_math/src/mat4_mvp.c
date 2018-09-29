/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_mvp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:50:16 by admin             #+#    #+#             */
/*   Updated: 2018/08/15 21:01:59 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

inline t_mat4	mat4_projection(float aspect, float fov, float near, float far)
{
	t_mat4	res;
	float	s;

	res = mat4_identity();
	s = 1.0 / (tanf(fov * 0.5));
	res.m11 = s / aspect;
	res.m22 = s;
	res.m33 = -(far + near) / (far - near);
	res.m34 = -1.0f;
	res.m43 = res.m33 * 2.0f;
	// res.v[0] = s / aspect;
	// res.v[5] = s;
	// res.v[10] = -(far + near) / (far - near);
	// res.v[11] = -1;
	// res.v[14] = -2.0 * far * near / (far - near);
	return (res);
}

inline t_mat4	mat4_view(t_vec3 look_at, t_vec3 eye, t_vec3 up_n)
{
	t_mat4			res;
	const t_vec3	dir = vec3_normalize(vec3_sub(eye, look_at));
	const t_vec3	right = vec3_normalize(vec3_cross(dir, up_n));
	const t_vec3	up = vec3_cross(right, dir);

	res = mat4_identity();
	res.m11 = right.x;
	res.m21 = right.y;
	res.m31 = right.z;
	res.m12 = up.x;
	res.m22 = up.y;
	res.m32 = up.z;
	res.m13 = dir.x;
	res.m23 = dir.y;
	res.m33 = dir.z;
	res.m41 = -vec3_dot(right, eye);
	res.m42 = -vec3_dot(up, eye);
	res.m43 = -vec3_dot(dir, eye);
	return (res);
}
