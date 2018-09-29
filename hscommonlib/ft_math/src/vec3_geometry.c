/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_geometry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 01:07:42 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 09:25:38 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"
#include <smmintrin.h>
#include <scalar.h>

inline t_vec3	vec3_dotv(t_vec3 v1, t_vec3 v2)
{
	return (vec3_init_m128(_mm_dp_ps(v1.m128, v2.m128, 0x77)));
}

inline float	vec3_dot(t_vec3 v1, t_vec3 v2)
{
	return (_mm_dp_ps(v1.m128, v2.m128, 0x71)[0]);
}

inline t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2)
{
	__m128 a_yzx = _mm_shuffle_ps(v1.m128, v1.m128, _MM_SHUFFLE(3, 0, 2, 1));
	__m128 b_yzx = _mm_shuffle_ps(v2.m128, v2.m128, _MM_SHUFFLE(3, 0, 2, 1));
	__m128 c = _mm_sub_ps(_mm_mul_ps(v1.m128, b_yzx),
							_mm_mul_ps(a_yzx, v2.m128));
	return (vec3_init_m128(_mm_shuffle_ps(c, c, _MM_SHUFFLE(3, 0, 2, 1))));
}
