/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_constructors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 00:42:15 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 01:21:32 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecf.h"
#include <libft.h>

inline t_vec3	vec3_init(float x, float y, float z)
{
	return ((t_vec3){{x, y, z, 0.0f}});
}

inline t_vec3	vec3_init_single(float x)
{
	return ((t_vec3){{x, x, x, 0.0f}});
}

inline t_vec3	vec3_init_m128(__m128 m128)
{
	return ((t_vec3){.m128 = m128});
}

inline t_vec3	vec3_init_int_string(const char *s)
{
	t_vec3	ret;
	int		i;

	i = 0;
	while (i < 3)
	{
		ret.v[i] = (float)ft_atoi_end(s, (char**)&s);
		while (ft_isspace(*s))
			++s;
		++i;
	}
	ret.w = 0.0f;
	return (ret);
}

inline t_vec3	vec3_init_float_string(const char *s)
{
	t_vec3	ret;
	int		i;

	i = 0;
	while (i < 3)
	{
		ret.v[i] = (float)ft_atod_end(s, (char**)&s);
		while (ft_isspace(*s))
			++s;
		++i;
	}
	ret.w = 0.0f;
	return (ret);
}
