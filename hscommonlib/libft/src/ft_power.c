/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/15 01:06:47 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int pow)
{
	if (pow == 0)
		return (1);
	return (nb * ft_power(nb, pow - 1));
}

double	ft_fpower(double nbr, int pow)
{
	if (pow == 0)
		return (1.0);
	return (nbr * ft_fpower(nbr, pow - 1));
}
