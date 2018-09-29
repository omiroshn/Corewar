/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_constructors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:12:24 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 09:49:14 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include <math.h>
#include <scalar.h>

inline t_quaternion		quat_init_rad(t_vec3 v, float w)
{
	t_quaternion	quat;

	quat = vec3_mult_scalar(v, sin(w * 0.5f));
	quat.w = cosf(w * 0.5f);
	return (vec4_normalize(quat));
}

inline t_quaternion		quat_init_normalizing_rad(t_vec3 v, float w)
{
	return (quat_init_rad(vec3_normalize(v), w));
}

inline t_quaternion		quat_init_deg(t_vec3 v, float w)
{
	return (quat_init_rad(v, TORAD(w)));
}

inline t_quaternion		quat_init_normalizing_deg(t_vec3 v, float w)
{
	return (quat_init_rad(vec3_normalize(v), TORAD(w)));
}
