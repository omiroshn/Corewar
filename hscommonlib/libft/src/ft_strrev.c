/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/07/27 17:50:00 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < (len / 2))
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
	str[len] = '\0';
	return (str);
}

void	reverse_int_array(int *arr, int size)
{
	int half_size;
	int i;
	int t;

	half_size = size >> 1;
	--size;
	i = 0;
	while (i < half_size)
	{
		t = arr[i];
		arr[i] = arr[size];
		arr[size] = t;
		--size;
		++i;
	}
}
