/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:50:09 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/03 23:38:48 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAM_PARSER_H
# define PARAM_PARSER_H

# include "op.h"
# include "param.h"
# include "libft.h"

typedef void		*(*t_param_parser)(
						t_pair mem,
						t_op_param *param,
						int dir_size);

extern void			*parse_param(
						uint8_t arg_code,
						t_pair mem,
						t_op_param *param,
						int dir_size);

#endif
