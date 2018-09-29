/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisspaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:19:27 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/04 12:20:14 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strisspace(const char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (false);
		++str;
	}
	return (true);
}
