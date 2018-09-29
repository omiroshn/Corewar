/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 21:48:20 by admin             #+#    #+#             */
/*   Updated: 2018/09/09 14:02:45 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	ft_atod(const char *s)
{
	const int	int_part = ft_atoi_end(s, (char**)&s);
	int			frac_part;
	double		res;

	frac_part = 0;
	if (*s == '.')
	{
		s++;
		frac_part = ft_atoi(s);
	}
	res = int_part + (double)frac_part / pow(10.0, ft_get_size(frac_part, 10));
	return (res);
}

double	ft_atod_end(const char *s, char **end)
{
	const int	int_part = ft_atoi_end(s, (char**)&s);
	int			frac_part;
	double		res;

	frac_part = 0;
	if (*s == '.')
	{
		s++;
		frac_part = ft_atoi_end(s, end);
	}
	res = int_part + (double)frac_part / pow(10.0, ft_get_size(frac_part, 10));
	return (res);
}
