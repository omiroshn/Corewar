/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_base_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 00:41:48 by admin             #+#    #+#             */
/*   Updated: 2018/08/23 14:04:24 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"
#include <math.h>

inline t_vec3	vec3_add(t_vec3 v1, t_vec3 v2)
{
	return (vec3_init_m128(_mm_add_ps(v1.m128, v2.m128)));
}

inline t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2)
{
	return (vec3_init_m128(_mm_sub_ps(v1.m128, v2.m128)));
}

inline t_vec3	vec3_mult(t_vec3 v1, t_vec3 v2)
{
	return (vec3_init_m128(_mm_mul_ps(v1.m128, v2.m128)));
}

inline t_vec3	vec3_div(t_vec3 v1, t_vec3 v2)
{
	return (vec3_init_m128(_mm_div_ps(v1.m128, v2.m128)));
}
