/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_writer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 21:51:00 by Admin             #+#    #+#             */
/*   Updated: 2018/08/31 21:54:37 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAM_WRITER_H
# define PARAM_WRITER_H

# include "param_parser.h"

struct s_arena;
struct s_process;

typedef void	(*t_param_writer)(
					int32_t value,
					t_op_param *param,
					struct s_arena *arena,
					struct s_process *process);

void			write_param(
					int32_t value,
					t_op_param *param,
					struct s_arena *arena,
					struct s_process *process);

#endif
