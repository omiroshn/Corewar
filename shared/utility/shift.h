/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_shift.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:35:30 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:56:14 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIFT_H
# define SHIFT_H

# include <inttypes.h>
# include <stddef.h>

struct s_vm;

extern size_t	cyclic_shift_mem(size_t offset, size_t period, int side);
extern uint32_t	cyclic_shift_u32(uint32_t offset, uint32_t period, int side);
extern int32_t	cyclic_shift_32(int32_t offset, int32_t period, int side);
extern void		*mempool_shift(void *pc, void *ground_ptr, int side);

#endif
