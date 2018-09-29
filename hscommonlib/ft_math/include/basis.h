/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 23:15:16 by admin             #+#    #+#             */
/*   Updated: 2018/08/15 23:27:59 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

# include "matrix.h"

typedef struct	s_basis
{
	union
	{
		struct
		{
			t_vec3 v[3];
		};
		struct
		{
			t_vec3 dir;
			t_vec3 right;
			t_vec3 up;
		};
	}
}				t_basis;

extern t_basis	basis_init(t_vec3 dir, t_vec3 right, t_vec3 up);
extern t_mat4	basis_convert_to_mat4(t_basis *basis);
extern t_basis	basis_rotate_axis(t_vec3 axis, float angle);
extern t_basis	basis_rotate_mat4(t_mat4 rotation_matrix);