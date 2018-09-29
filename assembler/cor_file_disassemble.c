/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_file_disassemble.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:27:03 by admin             #+#    #+#             */
/*   Updated: 2018/09/08 18:12:59 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor_file_disassemble.h"
#include "op.h"
#include "ft_printf.h"
#include "operand_input.h"
#include "mempool_io.h"
#include "swap.h"
#include "cor_file.h"

static const char	*g_param_format[kParamTypesTotal] =
{
	"",
	"r%d",
	"%%%d",
	"%d"
};

static size_t	disassemble_encoded_op(
					const t_op *op,
					uint8_t *text_section,
					size_t size,
					int fd)
{
	t_operand_input	input;
	t_op_param		*param;
	size_t			ptr;
	int				i;

	ptr = (size_t)text_section;
	input = parse_operand_input(&text_section, op->opcode - 1, text_section);
	ptr = (size_t)(text_section - ptr);
	i = -1;
	while (++i < op->nb_arg)
	{
		param = input.params + i;
		ft_dprintf(fd, g_param_format[param->type], param->value);
		if (i + 1 != op->nb_arg)
			ft_dprintf(fd, ", ");
	}
	ft_dprintf(fd, "\n");
	return (ptr);
}

static size_t	disassemble_op(
					t_operation_type operand,
					uint8_t *mem,
					size_t size,
					int fd)
{
	const t_op		*op;
	size_t			ptr;
	uint16_t		word;
	uint32_t		dword;

	op = g_op_tab + operand;
	ft_dprintf(fd, "    %-4s    ", op->label);
	if (op->encoded_input)
		return (disassemble_encoded_op(op, mem, size, fd));
	else
	{
		ptr = (size_t)mem;
		if (op->dir_size == 2)
		{
			mem = mempool_read(&word, mem, 2, mem);
			ft_dprintf(fd, "%%%d", (int16_t)swap16(word));
		}
		else if (op->dir_size == 4)
		{
			mem = mempool_read(&dword, mem, 4, mem);
			ft_dprintf(fd, "%%%d", (int32_t)swap32(dword));
		}
		ptr = (size_t)(mem - ptr);
		return ((size_t)ptr);
	}
}

bool			cor_file_disassemble(
					struct s_cor_file *cor,
					int fd)
{
	size_t				ptr;
	t_operation_type	op;
	uint8_t				*text_section;
	size_t				text_size;

	ft_dprintf(fd, "%-16s\"%s\"\n", ".name", cor->header->prog_name);
	ft_dprintf(fd, "%-16s\"%s\"\n\n", ".comment", cor->header->comment);
	text_section = cor->text_section;
	text_size = cor->header->prog_size;
	ptr = 0;
	while (ptr < text_size)
	{
		op = ((int8_t*)text_section)[ptr] - 1;
		if (operation_is_valid(op) && ++ptr < text_size)
			ptr += disassemble_op(op, text_section + ptr, text_size - ptr, fd);
		else
			++ptr;
	}
	return (true);
}
