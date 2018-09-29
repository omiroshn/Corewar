/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_geometry_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:26:14 by admin             #+#    #+#             */
/*   Updated: 2018/08/16 10:10:56 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"
#include <scalar.h>

inline float	vec4_distance(t_vec4 v1, t_vec4 v2)
{
	return (vec4_length(vec4_sub(v1, v2)));
}

inline t_vec4	vec4_normalize_safe(t_vec4 v)
{
	const float d = vec4_dot(v, v);

	return (d == 0.0 ? v : vec4_mult_scalar(v, ft_rsqrt(d)));
}

inline t_vec4	vec4_normalize(t_vec4 v)
{
	return (vec4_mult_scalar(v, vec4_rcp_length(v)));
}
