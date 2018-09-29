/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_type_64bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:14:30 by admin             #+#    #+#             */
/*   Updated: 2018/08/21 01:57:06 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <sys/_types/_size_t.h>

void	copy_64bit(void *dst, void *src)
{
	*(uint64_t*)dst = *(uint64_t*)src;
}

void	default_64bit_value(void *dst)
{
	*(uint64_t*)dst = 0;
}
