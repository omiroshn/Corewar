/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:57:15 by hshakula          #+#    #+#             */
/*   Updated: 2018/08/29 11:58:17 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "libft.h"
#include "ft_printf.h"
#include "vm.h"
#include "swap.h"
#include "cor_file.h"

#include <stdlib.h>

struct s_player	*player_init_data(
					void *file_content,
					size_t file_size,
					const char *file_name,
					int id)
{
	struct s_cor_file	*cor_file;
	struct s_player		*player;

	cor_file = cor_file_init_data(file_content, file_size, file_name);
	if (!cor_file)
		return (NULL);
	player = malloc(sizeof(struct s_player));
	player->cor_file = cor_file;
	player->name = cor_file->header->prog_name;
	player->id = id;
	return (player);
}

void			player_introduce_yourself(struct s_player *player)
{
	post_player_create(
		player->id,
		player->cor_file->header->prog_size,
		player->num,
		make_tuple(
			player->cor_file->header->prog_name,
			player->cor_file->header->comment,
			player->cor_file->text_section));
}

struct s_player	*player_init(const char *path, int32_t id)
{
	struct s_cor_file	*cor_file;
	struct s_player		*player;

	if ((cor_file = cor_file_init(path)) == NULL)
		return (NULL);
	player = malloc(sizeof(struct s_player));
	player->cor_file = cor_file;
	player->name = cor_file->header->prog_name;
	player->id = id;
	return (player);
}

void			player_release(void *player)
{
	cor_file_release(((struct s_player*)player)->cor_file);
	free(player);
}
