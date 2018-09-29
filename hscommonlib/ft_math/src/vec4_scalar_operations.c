/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_scalar_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 01:05:23 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 01:23:12 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"

inline t_vec4	vec4_mult_scalar(t_vec4 v, float c)
{
	return (vec4_mult(v, vec4_init_single(c)));
}

inline t_vec4	vec4_div_scalar(t_vec4 v, float c)
{
	return (vec4_div(v, vec4_init_single(c)));
}

inline t_vec4	scalar_mult_vec4(float c, t_vec4 v)
{
	return (vec4_mult(vec4_init_single(c), v));
}

inline t_vec4	scalar_div_vec4(float c, t_vec4 v)
{
	return (vec4_div(vec4_init_single(c), v));
}
