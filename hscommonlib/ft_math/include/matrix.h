/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 00:10:23 by admin             #+#    #+#             */
/*   Updated: 2018/08/15 21:05:26 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vecf.h"
# include <stdbool.h>

typedef struct	s_mat4
{
	union
	{
		struct
		{
			t_vec4 col[4];
		};
		struct
		{
			t_vec4 col0;
			t_vec4 col1;
			t_vec4 col2;
			t_vec4 col3;
		};
		struct
		{
			float m11;
			float m21;
			float m31;
			float m41;
			float m12;
			float m22;
			float m32;
			float m42;
			float m13;
			float m23;
			float m33;
			float m43;
			float m14;
			float m24;
			float m34;
			float m44;
		};
	};
}				t_mat4;

extern t_mat4	mat4_from_vec4(t_vec4 *vectors);
extern t_mat4	mat4_with_value(float value);
extern t_mat4	mat4_identity(void);

extern t_mat4	mat4_translation(t_vec3 t);
extern t_mat4	mat4_scale(t_vec3 scale);
extern t_mat4	mat4_uniform_scale(float scale);
extern t_mat4	mat4_rotation(t_vec3 axis, float angle);

extern t_mat4	mat4_projection(
					float aspect,
					float fov,
					float near,
					float far);
extern t_mat4	mat4_view(t_vec3 look_at, t_vec3 eye, t_vec3 up_n);

extern t_mat4	mat4_mul_mat4(t_mat4 m1, t_mat4 m2);
extern t_vec4	mat4_mul_vec4(t_mat4 m, t_vec4 v);
extern t_mat4	mat4_transpose(t_mat4 m);
extern t_mat4	mat4_inverse(t_mat4 m);

bool			mat4_equal_mat4(t_mat4 m1, t_mat4 m2);

#endif
