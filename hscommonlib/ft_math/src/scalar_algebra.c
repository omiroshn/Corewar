/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_algebra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 02:12:09 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 02:34:05 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <immintrin.h>
#include <stdbool.h>
#include <math.h>

/*inline */float	madd(const float a, const float b, const float c)
{
	return (a * b + c);
//	return (_mm_cvtss_f32(
//				_mm_fmadd_ss(
//					_mm_set_ss(a),
//					_mm_set_ss(b),
//					_mm_set_ss(c)
//					)
//				)
//			);
}

/*inline */float	msub(const float a, const float b, const float c)
{
	return (a * b - c);
//	return (_mm_cvtss_f32(
//				_mm_fmsub_ss(
//					_mm_set_ss(a),
//					_mm_set_ss(b),
//					_mm_set_ss(c)
//					)
//				)
//			);
}

/*inline */float	nmadd(const float a, const float b, const float c)
{
	return (-a * b + c);
//	return (_mm_cvtss_f32(
//				_mm_fnmadd_ss(
//					_mm_set_ss(a),
//					_mm_set_ss(b),
//					_mm_set_ss(c)
//					)
//				)
//			);
}

/*inline */float	nmsub(const float a, const float b, const float c)
{
	return (-a * b - c);
//	return (_mm_cvtss_f32(
//				_mm_fnmsub_ss(
//					_mm_set_ss(a),
//					_mm_set_ss(b),
//					_mm_set_ss(c)
//					)
//				)
//			);
}

bool	float_equal_float(float f1, float f2)
{
	return (fabsf(f1 - f2) < 1e-5f);
}
