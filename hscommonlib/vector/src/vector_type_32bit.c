/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_type_32bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:14:30 by admin             #+#    #+#             */
/*   Updated: 2018/08/21 01:56:58 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <sys/_types/_size_t.h>

void	copy_32bit(void *dst, void *src)
{
	*(uint32_t*)dst = *(uint32_t*)src;
}

void	default_32bit_value(void *dst)
{
	*(uint32_t*)dst = 0;
}
