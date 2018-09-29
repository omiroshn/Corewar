/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_type_8bit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:14:30 by admin             #+#    #+#             */
/*   Updated: 2018/08/21 01:56:31 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <sys/_types/_size_t.h>

void	copy_8bit(void *dst, void *src)
{
	*(uint8_t*)dst = *(uint8_t*)src;
}

void	default_8bit_value(void *dst)
{
	*(uint8_t*)dst = 0;
}

void	delete_placeholder(void *data)
{
	(void)data;
}
