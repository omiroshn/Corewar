/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_geometry_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:27:09 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 09:27:30 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"
#include <scalar.h>
#include <math.h>

inline float	vec4_length(t_vec4 v)
{
	return (sqrtf(vec4_dot(v, v)));
}

inline float	vec4_halfarea(t_vec4 v)
{
	return (madd(v.x, v.y + v.z, v.y + v.z));
}

inline float	vec4_area(t_vec4 v)
{
	return (vec4_halfarea(v) * 2.0f);
}

inline float	vec4_square_length(t_vec4 v)
{
	return (vec4_dot(v, v));
}

inline float	vec4_rcp_length(t_vec4 v)
{
	const float d = vec4_dot(v, v);

	return (ft_rsqrt(d));
}
