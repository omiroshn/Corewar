/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_reader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 17:49:40 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/13 23:12:03 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAM_READER_H
# define PARAM_READER_H

# include "param_parser.h"

struct s_arena;
struct s_process;

typedef int32_t	(*t_param_reader)(
					t_op_param *param,
					struct s_arena *arena,
					struct s_process *process);

int32_t			read_param(
					t_op_param *param,
					struct s_arena *arena,
					struct s_process *process);

#endif
