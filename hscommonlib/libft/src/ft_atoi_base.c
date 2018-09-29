/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:00:48 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/10 23:12:36 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_base(char c, int base)
{
	int					i;
	static const char	*base_string = "0123456789ABCDEF";

	i = 0;
	while (i < base)
	{
		if (c == base_string[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(const char *s, int base)
{
	unsigned long long	res;
	size_t				i;
	size_t				temp;
	int					count;

	res = 0;
	i = 0;
	count = 0;
	ft_strtoupper((char*)s);
	while (ft_isspace(s[i]))
		i++;
	if (s[temp = i] == '-' || s[i] == '+')
		i++;
	while ((count = in_base(s[i], base)) != -1)
	{
		res = res * base + count;
		i++;
	}
	if (s[temp] == '-' && base == 10)
		res = -res;
	return ((int)res);
}
