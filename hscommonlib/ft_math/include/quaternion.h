/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:09:07 by admin             #+#    #+#             */
/*   Updated: 2018/08/14 09:13:31 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include "vecf.h"

typedef t_vec4	t_quaternion;

extern t_quaternion		quat_init_rad(t_vec3 v, float w);
extern t_quaternion		quat_init_normalizing_rad(t_vec3 v, float w);
extern t_quaternion		quat_init_deg(t_vec3 v, float w);
extern t_quaternion		quat_init_normalizing_deg(t_vec3 v, float w);

extern t_quaternion		invert_quat(t_quaternion q);
extern t_quaternion		quat_mult_quat(t_quaternion q1, t_quaternion q2);
extern t_quaternion		quat_mult_vec3(t_quaternion q, t_vec3 v);
extern t_vec3			quat_transform_vec3(t_quaternion q, t_vec3 v);

#endif
