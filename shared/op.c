/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2018/09/03 16:40:53 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static const t_arg_type	g_param_type_to_arg_type[kParamTypesTotal] =
{
	0, T_REG, T_DIR, T_IND
};

const t_op	g_op_tab[] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", false, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", true, 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", true, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", true, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "substraction", true, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", true, 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", true, 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", true, 4},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", false, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", true, 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", true, 2},
	{"fork", 1, {T_DIR}, 12, 800, "fork", false, 2},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", true, 4},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", true, 2},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", false, 2},
	{"aff", 1, {T_REG}, 16, 2, "aff", true, 0},
	{"mul", 3, {T_REG, T_REG, T_REG}, 17, 20, "multiply", true, 0},
	{"div", 3, {T_REG, T_REG, T_REG}, 18, 30, "divide", true, 0},
	{"cmp", 2, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND}, 19, 2,
		"compare", true, 0},
	{"jne", 1, {T_DIR}, 19, 20, "jump if not zero", false, 2},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

bool	operation_is_valid(t_operation_type op)
{
	return (op > kOperationNone && op < kOperationsTotal);
}

bool	valid_param_type(t_param_type param, t_arg_type ground)
{
	return ((g_param_type_to_arg_type[param] & ground) != 0);
}
