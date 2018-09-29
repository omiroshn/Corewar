/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scalar_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 01:02:00 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 01:04:12 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"

inline t_vec3	vec3_mult_scalar(t_vec3 v, float c)
{
	return (vec3_mult(v, vec3_init_single(c)));
}

inline t_vec3	vec3_div_scalar(t_vec3 v, float c)
{
	return (vec3_div(v, vec3_init_single(c)));
}

inline t_vec3	scalar_mult_vec3(float c, t_vec3 v)
{
	return (vec3_mult(vec3_init_single(c), v));
}

inline t_vec3	scalar_div_vec3(float c, t_vec3 v)
{
	return (vec3_div(vec3_init_single(c), v));
}
