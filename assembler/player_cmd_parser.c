/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_cmd_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:49:44 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/05 12:51:32 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_cmd_parser.h"
#include "player.h"
#include "op_line.h"
#include "hashmap.h"
#include "libft.h"
#include "ft_printf.h"

t_hashmap	g_cmd_parsers_hashmap = NULL;

static bool	parse_name(
				struct s_player *player,
				struct s_op_line_cmd *cmd,
				char **err)
{
	const size_t	effective_len = cmd->value_len - 2;

	if (effective_len > PROG_NAME_LENGTH)
	{
		*err = "player's name is too long";
		return (false);
	}
	ft_strncpy(player->header.prog_name, cmd->value + 1, effective_len);
	return (true);
}

static bool	parse_comment(
				struct s_player *player,
				struct s_op_line_cmd *cmd,
				char **err)
{
	const size_t	effective_len = cmd->value_len - 2;

	if (effective_len > COMMENT_LENGTH)
	{
		*err = "player's comment is too long";
		return (false);
	}
	ft_strncpy(player->header.comment, cmd->value + 1, effective_len);
	return (true);
}

static void	init_parsers(void)
{
	g_cmd_parsers_hashmap = hashmap_init(32, kHashmapKeyTypeStackString);
	hashmap_put(g_cmd_parsers_hashmap, NAME_CMD_STRING, parse_name);
	hashmap_put(g_cmd_parsers_hashmap, COMMENT_CMD_STRING, parse_comment);
}

bool		player_parse_cmd(
				struct s_player *player,
				struct s_op_line *line,
				char **err)
{
	bool	ret;
	bool	(*cmd_parser)(struct s_player *, struct s_op_line_cmd *, char **);

	if (g_cmd_parsers_hashmap == NULL)
		init_parsers();
	cmd_parser = hashmap_get(g_cmd_parsers_hashmap, line->c.cmd.key);
	ret = true;
	if (cmd_parser != NULL)
		ret = cmd_parser(player, &line->c.cmd, err);
	op_line_release(line);
	return (ret);
}
