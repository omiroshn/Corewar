/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:31:50 by hshakula          #+#    #+#             */
/*   Updated: 2017/12/02 15:48:22 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap_private.h"

size_t			hashmap_table_min_size_calc(size_t num_entries)
{
	return (num_entries + (num_entries / 3));
}

size_t			hashmap_table_size_calc(size_t num_entries)
{
	size_t	table_size;
	size_t	min_size;

	table_size = hashmap_table_min_size_calc(num_entries);
	min_size = 32;
	while (min_size < table_size)
		min_size <<= 1;
	return (min_size);
}
