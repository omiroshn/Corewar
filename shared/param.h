/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:37:58 by Admin             #+#    #+#             */
/*   Updated: 2018/09/03 23:38:32 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAM_H
# define PARAM_H

# include <inttypes.h>
# include <stdbool.h>

typedef enum		e_param_type
{
	kParamTypeUnknown = 0,
	kParamTypeRegister,
	kParamTypeDirect,
	kParamTypeIndirect,
	kParamTypesTotal
}					t_param_type;

typedef struct		s_op_param
{
	int32_t			value;
	t_param_type	type;
	bool			valid;
}					t_op_param;

#endif
