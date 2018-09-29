/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_base_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 01:04:58 by admin             #+#    #+#             */
/*   Updated: 2018/08/23 14:04:32 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"
#include <math.h>

inline t_vec4	vec4_add(t_vec4 v1, t_vec4 v2)
{
	return (vec4_init_m128(_mm_add_ps(v1.m128, v2.m128)));
}

inline t_vec4	vec4_sub(t_vec4 v1, t_vec4 v2)
{
	return (vec4_init_m128(_mm_sub_ps(v1.m128, v2.m128)));
}

inline t_vec4	vec4_mult(t_vec4 v1, t_vec4 v2)
{
	return (vec4_init_m128(_mm_mul_ps(v1.m128, v2.m128)));
}

inline t_vec4	vec4_div(t_vec4 v1, t_vec4 v2)
{
	return (vec4_init_m128(_mm_div_ps(v1.m128, v2.m128)));
}
