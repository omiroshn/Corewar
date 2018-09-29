/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:50:06 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/31 17:56:45 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "param_parser.h"
#include "swap.h"
#include "mempool_io.h"
#include "shift.h"
#include "libft.h"
#include "param.h"

static void	*parse_param_unknown(t_pair mem,
						t_op_param *param,
						int dir_size)
{
	*param = (t_op_param){0, kParamTypeUnknown, 1};
	return (mem.first);
}

static void	*parse_param_register(t_pair mem,
						t_op_param *param,
						int dir_size)
{
	param->value = (int32_t)(*((uint8_t*)mem.first));
	param->type = kParamTypeRegister;
	return (mempool_shift(mem.first, mem.second, 1));
}

static void	*parse_param_direct(t_pair mem,
						t_op_param *param,
						int dir_size)
{
	uint16_t	word;
	uint32_t	dword;

	if (dir_size == 2)
	{
		mempool_read(&word, mem.first, 2, mem.second);
		param->value = (int16_t)swap16(word);
	}
	else if (dir_size == 4)
	{
		mempool_read(&dword, mem.first, 4, mem.second);
		param->value = swap32(dword);
	}
	else
		param->valid = false;
	param->type = kParamTypeDirect;
	return (mempool_shift(mem.first, mem.second, dir_size));
}

static void	*parse_param_indirect(t_pair mem,
						t_op_param *param,
						int dir_size)
{
	uint16_t value;

	mempool_read(&value, mem.first, 2, mem.second);
	param->value = (int16_t)swap16(value);
	param->type = kParamTypeIndirect;
	return (mempool_shift(mem.first, mem.second, 2));
}

static const t_param_parser	g_param_parsers[kParamTypesTotal] =
{
	parse_param_unknown,
	parse_param_register,
	parse_param_direct,
	parse_param_indirect
};

inline void	*parse_param(uint8_t arg_code,
						t_pair mem,
						t_op_param *param,
						int dir_size)
{
	return (g_param_parsers[arg_code](mem, param, dir_size));
}
