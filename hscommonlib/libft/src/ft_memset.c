/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/15 01:06:51 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	register size_t			i;
	register char			*s_ptr;

	if (!s)
		return (s);
	s_ptr = (char*)s;
	i = 0;
	while (i < len)
	{
		s_ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
