/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:28:17 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/21 01:56:09 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_PRIVATE_H
# define VECTOR_PRIVATE_H

# define GROWTH_RATE 0.25f
# define MIN_GROWTH 128

# include "vector.h"
# include <stdlib.h>

void	copy_8bit(void *dst, void *src);
void	default_8bit_value(void *dst);

void	copy_16bit(void *dst, void *src);
void	default_16bit_value(void *dst);

void	copy_32bit(void *dst, void *src);
void	default_32bit_value(void *dst);

void	copy_64bit(void *dst, void *src);
void	default_64bit_value(void *dst);

#endif
