/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_constructors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 00:42:15 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 01:23:01 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"

inline t_vec4	vec4_init(float x, float y, float z, float w)
{
	return ((t_vec4){{x, y, z, w}});
}

inline t_vec4	vec4_init_single(float x)
{
	return ((t_vec4){{x, x, x, x}});
}

inline t_vec4	vec4_init_m128(__m128 m128)
{
	return ((t_vec4){.m128 = m128});
}

inline t_vec4	vec4_init_vec3(t_vec3 v, float value)
{
	return ((t_vec4){{v.x, v.y, v.z, value}});
}
