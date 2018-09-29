/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:40:34 by Admin             #+#    #+#             */
/*   Updated: 2018/09/09 13:27:41 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "op.h"
# include "vector.h"

struct s_job;
struct s_op_list;
struct s_op_vector;

struct				s_player
{
	struct s_header		header;
	struct s_op_list	*op_list;
	struct s_op_vector	*op_vector;
};

struct s_player		*player_init(
						struct s_job *job);
bool				player_compile(
						struct s_player *player,
						const char *save_path,
						const char *filename);
void				player_release(struct s_player *player);

#endif
