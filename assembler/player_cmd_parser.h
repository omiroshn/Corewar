/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_cmd_parser.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:49:45 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:27:33 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CMD_PARSER_H
# define PLAYER_CMD_PARSER_H

# include <stdbool.h>

struct s_op_line;
struct s_player;

bool	player_parse_cmd(
			struct s_player *player,
			struct s_op_line *cmd_line,
			char **err);

#endif
