/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:40:32 by Admin             #+#    #+#             */
/*   Updated: 2018/09/09 13:51:31 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "job.h"
#include "op_list.h"
#include "libft.h"
#include "op_vector_write_arg.h"
#include "op_line.h"
#include "ft_printf.h"
#include "player_cmd_parser.h"
#include "op_vector.h"
#include "label_map.h"
#include "swap.h"
#include "error_logger.h"
#include <stdlib.h>
#include <assert.h>

static bool			player_init_header(
						struct s_player *player,
						struct s_op_list *op_list,
						char **err)
{
	struct s_op_line	*cmd_line;

	cmd_line = dlist_front(&op_list->op_lines);
	while (cmd_line != NULL && cmd_line->type == kOpLineTypeCmd)
	{
		cmd_line = dlist_pop_front(&op_list->op_lines);
		if (!player_parse_cmd(player, cmd_line, err))
			return (false);
		cmd_line = dlist_front(&op_list->op_lines);
	}
	player->header.magic = COREWAR_EXEC_CIGAM;
	if (op_list->program_size == 0 || op_list->program_size >= CHAMP_MAX_SIZE)
	{
		*err = "invalid player code size, expected range [0;682]";
		return (false);
	}
	player->header.prog_size = swap32(op_list->program_size);
	if (*player->header.comment == '\0' || *player->header.prog_name == '\0')
	{
		*err = "player's name and comment must be specified";
		return (false);
	}
	return (true);
}

struct s_player		*player_init(struct s_job *job)
{
	struct s_op_list	*op_list;
	struct s_player		*player;
	char				*err;

	op_list = op_list_init(job->file_content, job->file_size, job->file_name);
	if (op_list == NULL)
		return (NULL);
	player = malloc(sizeof(struct s_player));
	ft_memset(player, 0, sizeof(struct s_player));
	player->op_list = op_list;
	err = NULL;
	if (player_init_header(player, op_list, &err))
		player->op_vector = op_vector_init();
	else
	{
		log_error(-1, STACK_ERR_STR(err), STACK_ERR_STR(job->file_name));
		player_release(player);
		player = NULL;
	}
	return (player);
}

void				player_release(struct s_player *player)
{
	op_vector_release(player->op_vector);
	op_list_release(player->op_list);
	free(player);
}

static bool			player_write_line(
						struct s_player *player,
						struct s_op_line *line,
						const char *filename)
{
	const t_op			*op = g_op_tab + line->c.lop.o.type;
	uint8_t				encoding_byte;
	t_op_arg			*arg;
	int					i;

	if (!op_vector_write(player->op_vector, &op->opcode, 1))
		return (false);
	if (op->encoded_input)
	{
		encoding_byte = codage_byte(&line->c.lop.o.args);
		op_vector_write(player->op_vector, &encoding_byte, 1);
	}
	i = -1;
	while (++i < line->c.lop.o.args.num_args)
	{
		arg = line->c.lop.o.args.args + i;
		if (arg->label && !label_resolve(player->op_list->label_map,
												arg, line->offset))
		{
			log_error(-1, STACK_ERR_PAIR("unknown label"));
			return (false);
		}
		op_vector_write_arg(player->op_vector, arg, line->c.lop.o.type);
	}
	return (true);
}

bool				player_compile(
						struct s_player *player,
						const char *save_path,
						const char *filename)
{
	struct s_dlist_iter	iter;
	struct s_op_line	*line;
	bool				valid;

	if (!op_vector_write(player->op_vector, &player->header, sizeof(t_header)))
		return (false);
	iter = dlist_iter_init(&player->op_list->op_lines);
	line = dlist_iter_data(&iter);
	valid = true;
	while (line != NULL)
	{
		if (line->type == kOpLineTypeCmd)
		{
			log_error(line->num, STACK_ERR_PAIR("unexpected command"));
			valid = false;
		}
		if ((line->type & kOpLineTypeOperation) != 0)
			valid = valid && player_write_line(player, line, filename);
		dlist_next(&iter);
		line = dlist_iter_data(&iter);
	}
	return (valid && op_vector_save_to_file(player->op_vector, save_path));
}
