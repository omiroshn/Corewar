/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:43:19 by hshakula          #+#    #+#             */
/*   Updated: 2016/12/12 17:43:39 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	register char	*s1_ptr;
	register char	*s2_ptr;
	register size_t	i;

	s1_ptr = (char *)s1;
	s2_ptr = (char *)s2;
	i = 0;
	c = (char)c;
	if (!s2)
		return (s1);
	while (i < n)
	{
		if ((*s1_ptr++ = *s2_ptr++) == c)
			return (s1_ptr);
		i++;
	}
	return (NULL);
}
