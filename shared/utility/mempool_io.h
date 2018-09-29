/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_mempool_io.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 23:01:00 by Admin             #+#    #+#             */
/*   Updated: 2018/09/09 13:56:06 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMPOOL_IO_H
# define MEMPOOL_IO_H

struct s_vm;

/*
**	Returns the pointer to the next byte after the last read byte
*/

void	*mempool_read(
	void *dst,
	void *mempool_ptr,
	int num_bytes,
	void *ground_ptr);

void	mempool_write(
	void *mempool_ptr,
	void *src,
	int num_bytes,
	void *ground_ptr);

#endif
