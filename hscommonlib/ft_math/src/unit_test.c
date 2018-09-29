/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 00:09:28 by admin             #+#    #+#             */
/*   Updated: 2018/08/16 10:06:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>
#include <quaternion.h>
#include <scalar.h>
#include <ft_printf.h>
#include <math.h>

const t_mat4 g_base_mat =
{
	.col =
	{
		(t_vec4){{1.0f, 2.0f, 3.0f, 4.0f}},
		(t_vec4){{5.0f, 1.0f, 6.0f, 7.0f}},
		(t_vec4){{8.0f, 9.0f, 1.0f, 10.0f}},
		(t_vec4){{11.0f, 12.0f, 13.0f, 14.0f}}
	}
};

const t_vec3 g_transl_vec =
{
	{1.0f, 2.0f, 3.0f, 0.0f}
};
const t_mat4 g_transl_mat =
{
	.col =
	{
		(t_vec4){{1.0f, 0.0f, 0.0f, 0.0f}},
		(t_vec4){{0.0f, 1.0f, 0.0f, 0.0f}},
		(t_vec4){{0.0f, 0.0f, 1.0f, 0.0f}},
		(t_vec4){{1.0f, 2.0f, 3.0f, 1.0f}}
	}
};

const t_mat4 g_base_transl_mat_mult_ret =
{
	.col =
	{
		(t_vec4){{1.0f, 2.0f, 3.0f, 4.0f}},
		(t_vec4){{5.0f, 1.0f, 6.0f, 7.0f}},
		(t_vec4){{8.0f, 9.0f, 1.0f, 10.0f}},
		(t_vec4){{46.0f, 43.0f, 31.0f, 62.0f}}
	}
};

const t_vec3 g_x_axis =
{
	{1.0f, 0.0f, 0.0f, 0.0f}
};
const t_vec3 g_y_axis =
{
	{0.0f, 1.0f, 0.0f, 0.0f}
};
const t_vec3 g_z_axis =
{
	{0.0f, 0.0f, 1.0f, 0.0f}
};

//.col =
//{
//	(t_vec4){{1.0f, 0.0f, 0.0f, 0.0f}},
//	(t_vec4){{0.0f, 1.0f, 0.0f, 0.0f}},
//	(t_vec4){{0.0f, 0.0f, 1.0f, 0.0f}},
//	(t_vec4){{0.0f, 0.0f, 0.0f, 1.0f}}
//}

void	print_mat4(t_mat4 m, char *id)
{
	int	col;
	int	row;

	ft_printf("%s mat:\n", id);
	col = -1;
	while (++col < 4)
	{
		row = -1;
		while (++row < 4)
		{
			ft_printf("%4.2f ", m.col[row].v[col]);
		}
		ft_printf("\n");
	}
}

void	print_test(char *test_name, bool success)
{
	if (success)
		ft_printf("%s: %s\n", test_name, "success");
	else
		ft_printf("%s: %s\n", test_name, "fail");
}

int	main(void)
{
	print_test("Translation matrix", mat4_equal_mat4(g_transl_mat, mat4_translation(g_transl_vec)));


	t_mat4 base_transl_mat_mult_ret = mat4_mul_mat4(g_base_mat, g_transl_mat);
	print_test("Matrix multiplication", mat4_equal_mat4(g_base_transl_mat_mult_ret, base_transl_mat_mult_ret));

	t_quaternion q = quat_init_deg(g_z_axis, -90.0f);
	t_vec3 x_axis = quat_transform_vec3(q, g_y_axis);
	print_test("Quaternion rotation", vec3_equal_vec3(g_x_axis, x_axis));

	print_test("Vec3 cross", vec3_equal_vec3(g_z_axis, vec3_cross(g_x_axis, g_y_axis)));

	print_test("Vec3 dot #1", float_equal_float(0.0f, vec3_dot(g_x_axis, g_z_axis)));
	print_test("Vec3 dot #2", float_equal_float(1.0f, vec3_dot(g_x_axis, x_axis)));

	print_test("Vec3 distance", float_equal_float(sqrtf(2.0f), vec3_distance(g_x_axis, g_z_axis)));
}
















