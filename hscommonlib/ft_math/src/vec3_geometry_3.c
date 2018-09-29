/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_geometry_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:05:40 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 09:06:57 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"
#include <scalar.h>
#include <math.h>

inline float	vec3_length(t_vec3 v)
{
	return (sqrtf(vec3_dot(v, v)));
}

inline float	vec3_halfarea(t_vec3 v)
{
	return (madd(v.x, v.y + v.z, v.y + v.z));
}

inline float	vec3_area(t_vec3 v)
{
	return (vec3_halfarea(v) * 2.0f);
}

inline float	vec3_square_length(t_vec3 v)
{
	return (vec3_dot(v, v));
}

inline float	vec3_rcp_length(t_vec3 v)
{
	const float d = vec3_dot(v, v);

	return (ft_rsqrt(d));
}
