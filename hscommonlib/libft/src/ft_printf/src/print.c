/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:35:55 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include "buffer_manager.h"
#include "padding.h"
#include <stdlib.h>

void	print(struct s_specifier *spec, void *str, int size, bool freeing)
{
	const char padding_char = (spec->flags.padding_with_zeros) ? '0' : ' ';

	if (spec->min_width > size && !spec->flags.left_justification)
		print_padding(padding_char, spec->min_width - size);
	print_to_buffer(str, size);
	if (spec->min_width > size && spec->flags.left_justification)
		print_padding(padding_char, spec->min_width - size);
	if (freeing)
		free(str);
}
