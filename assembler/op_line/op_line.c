/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:26:36 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:28:06 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_line.h"
#include "op_line_size.h"
#include "libft.h"
#include "token_parser.h"
#include "error_logger.h"
#include <stdlib.h>

struct s_op_line	g_empty_line =
{
	.str = NULL
};

static char			*op_line_cleared(char *file_line)
{
	const size_t		len = ft_strslen(file_line, "\n#");
	char				*tmp;
	char				*line;

	if (len == 0)
		return (NULL);
	line = malloc(len + 1);
	line[len] = '\0';
	ft_strncpy(line, file_line, len);
	line = ft_strrmchar(line, "\v\f\r");
	tmp = line;
	line = ft_strtrim(line);
	free(tmp);
	if (line[0] == '\0' || ft_strisspace(line))
	{
		free(line);
		line = NULL;
	}
	return (line);
}

static bool			valid_arg_line(const char *line)
{
	size_t i;

	if (*line == ',')
		return (false);
	i = 0;
	while (line[i + 1])
	{
		if (line[i] == ',' && line[i + 1] == ',')
			return (false);
		++i;
	}
	if (line[i] == ',')
		return (false);
	return (true);
}

static bool			parse_line(struct s_op_line *l, char **err)
{
	const char	*op_str = op_line_parse_label(l);
	char		**tokens;
	bool		ret;

	ret = true;
	if (op_str == NULL)
		return (false);
	if (ft_strisspace(op_str))
		return (true);
	if ((tokens = ft_split_once(op_str, " \t%", " \t")) == NULL)
		return (false);
	if (tokens[0][0] != '.')
	{
		l->type |= kOpLineTypeOperation;
		l->c.lop.o.type = token_parse_op_type(tokens[0]);
		l->c.lop.o.args = token_parse_op_args(tokens[1], l->c.lop.o.type, err);
		ret = l->c.lop.o.args.valid && l->c.lop.o.type != kOperationNone &&
			valid_arg_line(tokens[1]);
	}
	else if (l->type != kOpLineTypeLabel && op_line_parse_cmd(tokens, l))
		ret = true;
	else
		ret = false;
	ft_strsplit_release(tokens, 2);
	return (ret);
}

struct s_op_line	*op_line_init(
						char *file_line,
						int num,
						const char *filename)
{
	char				*err;
	char				*str;
	struct s_op_line	*line;

	err = NULL;
	str = op_line_cleared(file_line);
	if (str == NULL)
		return (&g_empty_line);
	line = malloc(sizeof(struct s_op_line));
	ft_memset(line, 0, sizeof(struct s_op_line));
	line->str = str;
	line->num = num;
	line->type = kOpLineTypeUnknown;
	if (parse_line(line, &err))
		line->size = op_line_size(line);
	else
	{
		if (err == NULL)
			err = "invalid instruction format";
		log_error(num, STACK_ERR_PAIR(err));
		op_line_release(line);
		line = NULL;
	}
	return (line);
}

void				op_line_release(void *op_line_ptr)
{
	struct s_op_line	*line;
	int					i;
	t_op_arg			*arg;

	line = op_line_ptr;
	free(line->str);
	if ((line->type & kOpLineTypeOperation) != 0)
	{
		i = -1;
		while (++i < line->c.op.args.num_args)
		{
			arg = line->c.op.args.args + i;
			if (arg->label)
				free(arg->label_str);
		}
	}
	if ((line->type & kOpLineTypeLabel) != 0)
		free(line->c.lop.l.str);
	if (line->type == kOpLineTypeCmd)
	{
		free(line->c.cmd.key);
		free(line->c.cmd.value);
	}
	free(op_line_ptr);
}
