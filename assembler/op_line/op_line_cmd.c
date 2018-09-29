/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_line_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:17:32 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/05 16:27:08 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_line_cmd.h"
#include "op_line.h"
#include "libft.h"
#include <stdlib.h>

bool	op_line_parse_cmd(char **tokens, struct s_op_line *line)
{
	line->c.cmd.value_len = ft_strlen(tokens[1]);
	if (line->c.cmd.value_len > 2 &&
		tokens[1][0] == '"' && tokens[1][line->c.cmd.value_len - 1] == '"')
	{
		line->type = kOpLineTypeCmd;
		line->c.cmd.key = ft_strdup(tokens[0]);
		line->c.cmd.value = ft_strdup(tokens[1]);
		return (true);
	}
	return (false);
}
