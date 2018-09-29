/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:47:51 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 12:47:23 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_op_fnc	g_op_functions[kOperationsTotal] =
{
	op_live,
	op_ld,
	op_st,
	op_add,
	op_sub,
	op_and,
	op_or,
	op_xor,
	op_zjmp,
	op_ldi,
	op_sti,
	op_fork,
	op_lld,
	op_lldi,
	op_lfork,
	op_aff,
	op_mul,
	op_div,
	op_cmp,
	op_jne
};
