/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_compare_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:57:21 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/23 14:04:35 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"
#include <math.h>

inline t_vec4	vec4_min(t_vec4 v1, t_vec4 v2)
{
	return (vec4_init_m128(_mm_min_ps(v1.m128, v2.m128)));
}

inline t_vec4	vec4_max(t_vec4 v1, t_vec4 v2)
{
	return (vec4_init_m128(_mm_max_ps(v1.m128, v2.m128)));
}

bool			vec4_equal_vec4(t_vec4 v1, t_vec4 v2)
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
