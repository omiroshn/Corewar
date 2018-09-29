/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 00:03:16 by admin             #+#    #+#             */
/*   Updated: 2018/08/23 14:04:15 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECF_H
# define VECF_H

# include <xmmintrin.h>
# include <stdbool.h>

typedef struct	s_vec3
{
	union {
		__m128 m128;
		struct
		{
			float x, y, z;
			union
			{
				int a;
				unsigned u;
				float w;
			}; 
		};
		float v[4];
	};
}				t_vec3;

typedef t_vec3	t_vec4;

extern t_vec3	vec3_init(float x, float y, float z);
extern t_vec3	vec3_init_single(float x);
extern t_vec3	vec3_init_m128(__m128 m128);
extern t_vec3	vec3_init_int_string(const char *s);
extern t_vec3	vec3_init_float_string(const char *s);

extern t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);
extern t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2);
extern t_vec3	vec3_mult(t_vec3 v1, t_vec3 v2);
extern t_vec3	vec3_div(t_vec3 v1, t_vec3 v2);

extern t_vec3	vec3_mult_scalar(t_vec3 vector, float c);
extern t_vec3	vec3_div_scalar(t_vec3 vector, float c);
extern t_vec3	scalar_mult_vec3(float c, t_vec3 vector);
extern t_vec3	scalar_div_vec3(float c, t_vec3 vector);

extern t_vec3	vec3_dotv(t_vec3 v1, t_vec3 v2);
extern t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2);
extern float	vec3_dot(t_vec3 v1, t_vec3 v2);

extern float	vec3_length(t_vec3 v);
extern float	vec3_square_length(t_vec3 v);
extern float	vec3_rcp_length(t_vec3 v);

extern float	vec3_distance(t_vec3 v1, t_vec3 v2);
extern t_vec3	vec3_normalize(t_vec3 v);
extern t_vec3	vec3_normalize_safe(t_vec3 v);
extern float	vec3_halfarea(t_vec3 v);
extern float	vec3_area(t_vec3 v);

bool			vec3_equal_vec3(t_vec3 v1, t_vec3 v2);
extern t_vec4	vec4_min(t_vec4 v1, t_vec4 v2);
extern t_vec4	vec4_max(t_vec4 v1, t_vec4 v2);

extern t_vec4	vec4_init(float x, float y, float z, float w);
extern t_vec4	vec4_init_single(float x);
extern t_vec4	vec4_init_m128(__m128 m128);
extern t_vec4	vec4_init_vec3(t_vec3 v, float value);

extern t_vec4	vec4_add(t_vec4 v1, t_vec4 v2);
extern t_vec4	vec4_sub(t_vec4 v1, t_vec4 v2);
extern t_vec4	vec4_mult(t_vec4 v1, t_vec4 v2);
extern t_vec4	vec4_div(t_vec4 v1, t_vec4 v2);

extern t_vec4	vec4_mult_scalar(t_vec4 vector, float c);
extern t_vec4	vec4_div_scalar(t_vec4 vector, float c);
extern t_vec4	scalar_mult_vec4(float c, t_vec4 vector);
extern t_vec4	scalar_div_vec4(float c, t_vec4 vector);

extern t_vec4	vec4_dotv(t_vec4 v1, t_vec4 v2);
extern t_vec4	vec4_cross(t_vec4 v1, t_vec4 v2);
extern float	vec4_dot(t_vec4 v1, t_vec4 v2);

extern float	vec4_length(t_vec4 v);
extern float	vec4_square_length(t_vec4 v);
extern float	vec4_rcp_length(t_vec4 v);

extern float	vec4_distance(t_vec4 v1, t_vec4 v2);
extern t_vec4	vec4_normalize(t_vec4 v);
extern t_vec4	vec4_normalize_safe(t_vec4 v);
extern float	vec4_halfarea(t_vec4 v);
extern float	vec4_area(t_vec4 v);

bool			vec4_equal_vec4(t_vec4 v1, t_vec4 v2);
extern t_vec4	vec4_min(t_vec4 v1, t_vec4 v2);
extern t_vec4	vec4_max(t_vec4 v1, t_vec4 v2);

#endif
