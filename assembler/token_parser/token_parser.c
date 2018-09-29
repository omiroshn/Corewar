/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:46:38 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/04 16:51:30 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_parser.h"
#include "hashmap.h"
#include "libft.h"
#include <assert.h>

t_hashmap			g_op_type_hashmap;
t_operation_type	*g_op_type_wrapper;
int					g_reference_counter = 0;

void				token_parser_init(void)
{
	t_operation_type	type;

	if (g_reference_counter++ == 0)
	{
		g_op_type_wrapper = malloc(sizeof(t_operation_type) * kOperationsTotal);
		g_op_type_hashmap = hashmap_init(kOperationsTotal * 4,
										kHashmapKeyTypeStackString);
		type = kOperationLive;
		while (type < kOperationsTotal)
		{
			g_op_type_wrapper[type] = type;
			hashmap_put(g_op_type_hashmap, g_op_tab[type].label,
						&g_op_type_wrapper[type]);
			++type;
		}
	}
}

void				token_parser_deinit(void)
{
	if (--g_reference_counter == 0)
	{
		hashmap_destroy(g_op_type_hashmap, NULL);
		free(g_op_type_wrapper);
	}
	assert(g_reference_counter >= 0);
}

t_operation_type	token_parse_op_type(char *token)
{
	const t_operation_type	*type_ptr = hashmap_get(g_op_type_hashmap, token);

	if (type_ptr == NULL)
		return (kOperationNone);
	else
		return (*type_ptr);
}
