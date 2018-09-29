/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:56:37 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:00:44 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dump.h"
#include "op.h"
#include "ft_printf.h"

void	dump_mempool(uint8_t *mempool, int bytes_per_row)
{
	int i;
	int j;

	i = 0;
	ft_printf("0x");
	while (i < MEM_SIZE)
	{
		ft_printf("%#.4x : ", i);
		j = -1;
		while (++j < bytes_per_row && i + j < MEM_SIZE)
		{
			ft_printf("%.2x ", mempool[i + j]);
		}
		ft_printf("\n");
		i += bytes_per_row;
	}
}
