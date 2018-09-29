/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 14:28:26 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/29 14:31:07 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include <inttypes.h>

extern uint16_t	swap16(uint16_t value);
extern uint32_t	swap32(uint32_t value);
extern uint64_t	swap64(uint64_t value);

#endif
