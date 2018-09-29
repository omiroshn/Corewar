/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_geometry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 01:28:55 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 09:25:14 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"

#include <smmintrin.h>
#include <scalar.h>

inline t_vec4	vec4_dotv(t_vec4 v1, t_vec4 v2)
{
	return (vec4_init_m128(_mm_dp_ps(v1.m128, v2.m128, 0xFF)));
}

inline float	vec4_dot(t_vec4 v1, t_vec4 v2)
{
	return (_mm_dp_ps(v1.m128, v2.m128, 0xF1)[0]);
}

