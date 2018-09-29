/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:56:04 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:26:42 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_parser_args.h"
#include "libft.h"
#include <stdlib.h>

const uint8_t		g_param_type_to_code[kParamTypesTotal] =
{
	0, REG_CODE, DIR_CODE, IND_CODE
};

uint8_t				codage_byte(t_op_args *args)
{
	uint8_t	ret;
	int		i;
	int		shift;

	ret = 0;
	i = -1;
	while (++i < args->num_args)
	{
		shift = (MAX_ARGS_NUMBER - i - 1) << 1;
		ret |= g_param_type_to_code[args->args[i].type] << shift;
	}
	return (ret);
}

void				token_parse_value(char *token, t_op_arg *arg, char **err)
{
	if (ft_strchr(token, ':') == NULL)
	{
		arg->valid = ft_strisnumber(token);
		if (arg->valid == false)
			*err = "invalid operand argument format";
		arg->value = ft_atoi(token);
	}
	else
	{
		arg->label = true;
		arg->label_str = ft_strdup(token);
	}
}

t_op_arg			token_parse_op_arg(char *token, char **err)
{
	t_op_arg	arg;

	arg.label = false;
	arg.valid = true;
	if (token[0] == 'r')
	{
		arg.type = kParamTypeRegister;
		arg.value = ft_atoi(token + 1);
		if (!(arg.valid = ft_strisnumber(token + 1)))
			*err = "invalid operand argument format";
		else if (!(arg.valid = arg.value >= 0 && arg.value < REG_NUMBER))
			*err = "register number must be in range [0;15]";
	}
	else if (token[0] == '%')
	{
		arg.type = kParamTypeDirect;
		token_parse_value(token + 1, &arg, err);
	}
	else
	{
		arg.type = kParamTypeIndirect;
		token_parse_value(token, &arg, err);
	}
	free(token);
	return (arg);
}

bool				params_is_valid(
						t_op_args *args,
						t_operation_type op_type,
						char **err)
{
	const t_op	*op;
	int			arg_n;

	if (!operation_is_valid(op_type))
	{
		*err = "unknown instruction";
		return (false);
	}
	op = g_op_tab + op_type;
	if (args->num_args != op->nb_arg)
	{
		*err = "invalid amount of arguments";
		return (false);
	}
	arg_n = -1;
	while (++arg_n < op->nb_arg)
	{
		if (!valid_param_type(args->args[arg_n].type, op->type[arg_n]))
		{
			*err = "invalid argument type";
			return (false);
		}
	}
	return (true);
}

t_op_args			token_parse_op_args(
						char *token,
						t_operation_type op_type,
						char **err)
{
	t_op_args		ret;
	int				num;
	char			**subtokens;
	int				i;

	ft_memset(&ret, 0, sizeof(t_op_args));
	ret.valid = true;
	subtokens = ft_strssplit(token, ",", &num);
	if ((ret.valid = subtokens != NULL && num <= 4 && num != 0))
	{
		ret.num_args = num;
		i = -1;
		while (++i < num)
		{
			ret.args[i] = token_parse_op_arg(ft_strtrim(subtokens[i]), err);
			if (!ret.args[i].valid)
			{
				ret.valid = false;
				break ;
			}
		}
	}
	ft_strsplit_release(subtokens, num);
	ret.valid = ret.valid && params_is_valid(&ret, op_type, err);
	return (ret);
}
