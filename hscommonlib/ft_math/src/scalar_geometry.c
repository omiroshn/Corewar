/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_geometry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 01:50:39 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 09:05:53 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <xmmintrin.h>
#include <immintrin.h>

float	ft_rsqrt(const float x)
{
	const __m128 a = _mm_set_ss(x);
	const __m128 r = _mm_rsqrt_ss(a);

	return (_mm_cvtss_f32(
				_mm_add_ss(
					_mm_mul_ss(_mm_set_ss(1.5f), r),
					_mm_mul_ss(
						_mm_mul_ss(
							_mm_mul_ss(
								a,
								_mm_set_ss(-0.5f)),
							r),
						_mm_mul_ss(r, r)
						)
					)
				));
}
