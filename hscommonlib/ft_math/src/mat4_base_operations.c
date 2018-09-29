/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_base_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 01:02:00 by admin             #+#    #+#             */
/*   Updated: 2018/08/16 00:29:22 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <pmmintrin.h>
#include <immintrin.h>
#include <math.h>

bool			mat4_equal_mat4(t_mat4 m1, t_mat4 m2)
{
	int	col;
	int	row;

	col = -1;
	while (++col < 4)
	{
		row = -1;
		while (++row < 4)
		{
			if (fabsf(m1.col[col].v[row] - m2.col[col].v[row]) > 1e-5f)
				return false;
		}
	}
	return true;
}

inline t_mat4	mat4_mul_mat4(t_mat4 m1, t_mat4 m2)
{
	t_mat4	res;
	t_vec4	r;
	int		col;
	int		i;

	col = -1;
	while (++col < 4)
	{
		i = 0;
		r = vec4_mult_scalar(m1.col[i], m2.col[col].v[i]);
		while (++i < 4)
			r = vec4_add(r, vec4_mult_scalar(m1.col[i], m2.col[col].v[i]));
		res.col[col] = r;
	}
	return (res);
}

inline t_vec4	mat4_mul_vec4(t_mat4 m, t_vec4 v)
{
	const __m128	m0 = _mm_mul_ps(m.col0.m128, v.m128);
	const __m128	m1 = _mm_mul_ps(m.col1.m128, v.m128);
	const __m128	m2 = _mm_mul_ps(m.col2.m128, v.m128);
	const __m128	m3 = _mm_mul_ps(m.col3.m128, v.m128);

	return (vec4_init_m128(_mm_hadd_ps(
								_mm_hadd_ps(m0, m1),
								_mm_hadd_ps(m2, m3))));
}

inline t_mat4	mat4_transpose(t_mat4 m)
{
	_MM_TRANSPOSE4_PS(m.col0.m128, m.col1.m128, m.col2.m128, m.col3.m128);
	return (m);
}

inline t_mat4	mat4_inverse(t_mat4 m)
{
	t_mat4 res;

	// Not implemented
	abort();

	return (res);
}
