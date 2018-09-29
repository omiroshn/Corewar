/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeofnumber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:43:19 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/23 21:58:06 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizeofnumber(int n)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = n;
	if (n == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

int	ft_get_size(long long n, int base)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		if (base == 10)
			size++;
		n = -n;
	}
	while (n >= base)
	{
		n /= base;
		size++;
	}
	return (size);
}
