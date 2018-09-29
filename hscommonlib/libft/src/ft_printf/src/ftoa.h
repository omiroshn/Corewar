/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:26:14 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTOA_H
# define FTOA_H

# include <inttypes.h>
# include <stdbool.h>

enum
{
	g_max_ftoa_precision = 18
};

struct	s_ftoa
{
	char		buf[g_max_ftoa_precision];
	int			is_negative;
	intmax_t	int_part;
	double		floating_frac;
	uintmax_t	frac;
	double		frac_diff;
	int			precision;
	bool		force_decimal_point;
};

char	*ft_ftoa(double value,
				int precision,
				int *size,
				bool force_decimal_point);
char	*ft_float_to_scientific(double value,
				int precision,
				int *size,
				bool force_decimal_point);

#endif
