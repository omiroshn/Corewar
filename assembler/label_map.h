/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:52:38 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:51:07 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_MAP_H
# define LABEL_MAP_H

# include "hashmap.h"
# include "token_parser_args.h"
# include <stdbool.h>

struct s_op_list;

struct				s_label_map
{
	t_hashmap	map;
	bool		valid;
};

struct s_label_map	*label_map_init(
						struct s_op_list *list,
						const char *filename);
int					label_offset(struct s_label_map *map, char *label);
bool				label_resolve(
						struct s_label_map *label_map,
						t_op_arg *arg,
						size_t line_offset);
void				label_map_release(struct s_label_map *map);

#endif
