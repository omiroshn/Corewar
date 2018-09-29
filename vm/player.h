/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:57:15 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 12:45:31 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "op.h"
# include "process.h"
# include "dlist.h"
# include <stddef.h>

struct s_cor_file;

struct			s_player
{
	struct s_cor_file	*cor_file;
	const char			*name;
	int32_t				id;
	uint8_t				num;
};

struct s_player	*player_init(const char *path, int32_t id);
struct s_player	*player_init_data(
					void *file_content,
					size_t file_size,
					const char *file_name,
					int id);
void			player_introduce_yourself(struct s_player *player);
void			player_release(void *player);

#endif
