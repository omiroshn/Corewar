/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_geometry_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 02:04:04 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 09:26:23 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"
#include <scalar.h>

inline float	vec3_distance(t_vec3 v1, t_vec3 v2)
{
	return (vec3_length(vec3_sub(v1, v2)));
}

inline t_vec3	vec3_normalize_safe(t_vec3 v)
{
	const float d = vec3_dot(v, v);

	return (d == 0.0 ? v : vec3_mult_scalar(v, ft_rsqrt(d)));
}

inline t_vec3	vec3_normalize(t_vec3 v)
{
	return (vec3_mult_scalar(v, vec3_rcp_length(v)));
}
