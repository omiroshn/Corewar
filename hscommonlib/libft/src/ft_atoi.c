/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/07/29 15:36:05 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int res;
	int i;
	int temp;

	i = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	temp = i;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	while (ft_isdigit(str[i]) && str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[temp] == '-')
		res *= -1;
	return (res);
}

int	ft_natoi(const char *str, int max_len)
{
	int res;
	int i;
	int temp;

	i = 0;
	while (ft_isspace(str[i]) && str[i] && i < max_len)
		i++;
	temp = i;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	while (ft_isdigit(str[i]) && str[i] && i < max_len)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[temp] == '-')
		res *= -1;
	return (res);
}

int	ft_atoi_end(const char *str, char **end)
{
	int res;
	int i;
	int temp;

	i = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	temp = i;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	while (ft_isdigit(str[i]) && str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	*end = (char*)str + i;
	if (str[temp] == '-')
		res *= -1;
	return (res);
}
