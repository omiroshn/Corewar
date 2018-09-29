/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_base_operations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:49:26 by admin             #+#    #+#             */
/*   Updated: 2018/08/16 10:01:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include <pmmintrin.h>

inline t_quaternion		invert_quat(t_quaternion q)
{
	q = vec4_mult_scalar(q, -1.0f);
	q.w *= -1.0f;
	return (q);
}

inline t_quaternion		quat_mult_quat(t_quaternion xyzw, t_quaternion abcd)
{
	__m128 wzyx = _mm_shuffle_ps(xyzw.m128, xyzw.m128, _MM_SHUFFLE(0,1,2,3));
	__m128 baba = _mm_shuffle_ps(abcd.m128, abcd.m128, _MM_SHUFFLE(0,1,0,1));
	__m128 dcdc = _mm_shuffle_ps(abcd.m128, abcd.m128, _MM_SHUFFLE(2,3,2,3));
	__m128 ZnXWY = _mm_hsub_ps(_mm_mul_ps(xyzw.m128, baba),
								_mm_mul_ps(wzyx, dcdc));
	__m128 XZYnW = _mm_hadd_ps(_mm_mul_ps(xyzw.m128, dcdc),
								_mm_mul_ps(wzyx, baba));
	__m128 XZWY = _mm_addsub_ps(
					_mm_shuffle_ps(XZYnW, ZnXWY, _MM_SHUFFLE(3,2,1,0)),
					_mm_shuffle_ps(ZnXWY, XZYnW, _MM_SHUFFLE(2,3,0,1)));

	return vec4_init_m128(_mm_shuffle_ps(XZWY, XZWY, _MM_SHUFFLE(2,1,3,0)));
}

inline t_quaternion		quat_mult_vec3(t_quaternion q, t_vec3 v)
{
	t_quaternion	res;

	res.x = q.y * v.z - q.z * v.y;
	res.y = q.z * v.x - q.x * v.z;
	res.z = q.x * v.y - q.y * v.x;
	res = vec3_add(vec3_mult_scalar(v, q.w), res);
	res.w = -1.0f * vec3_dot(q, v);
	return (res);
}

inline t_vec3			quat_transform_vec3(t_quaternion q, t_vec3 v)
{
	return (vec3_normalize(quat_mult_quat(
								quat_mult_vec3(q, v),
								invert_quat(q))));
}
