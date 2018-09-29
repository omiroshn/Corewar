/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_line_cmd.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:17:33 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:29:35 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_LINE_CMD_H
# define OP_LINE_CMD_H

# include <stdbool.h>
# include <stddef.h>

struct s_op_line;

struct	s_op_line_cmd
{
	char	*key;
	char	*value;
	size_t	value_len;
};

bool	op_line_parse_cmd(char **tokens, struct s_op_line *line);

#endif
