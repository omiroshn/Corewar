/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_compare_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:57:21 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/23 14:04:27 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"
#include <math.h>

inline t_vec3	vec3_min(t_vec3 v1, t_vec3 v2)
{
	return (vec3_init_m128(_mm_min_ps(v1.m128, v2.m128)));
}

inline t_vec3	vec3_max(t_vec3 v1, t_vec3 v2)
{
	return (vec3_init_m128(_mm_max_ps(v1.m128, v2.m128)));
}

bool			vec3_equal_vec3(t_vec3 v1, t_vec3 v2)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		if ((fabsf(v1.v[i] - v2.v[i])) > 1e-5f)
			return (false);
	}
	return (true);
}
