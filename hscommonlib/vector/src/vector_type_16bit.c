/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_type_16bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:14:30 by admin             #+#    #+#             */
/*   Updated: 2018/09/09 14:14:27 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <sys/_types/_size_t.h>

void	copy_16bit(void *dst, void *src)
{
	*(uint16_t*)dst = *(uint16_t*)src;
}

void	default_16bit_value(void *dst)
{
	*(uint16_t*)dst = 0;
}
