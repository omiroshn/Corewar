/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:55:34 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 12:57:21 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NCURSES_OBSERVER_IMPLEMENTATION
#include "ncurses_observer_private.h"
#include <assert.h>

void	ncurses_proc_create(struct s_event *event, struct s_curses *curses)
{
	const struct s_event_proc_create	*proc_info = &event->info.pc;
	struct s_curses_process				*process;
	struct s_curses_player				*player;

	player = ncurses_find_player(curses, proc_info->player_id, NULL);
	assert(player);
	if (player)
		++player->num_processes;
	else
		return ;
	process = ft_memalloc(sizeof(struct s_curses_process));
	process->id = proc_info->proc_id;
	process->owner_id = proc_info->player_id;
	process->position = proc_info->position;
	dlist_push_back_data(&curses->processes, process);
}

void	ncurses_player_create(struct s_event *event, struct s_curses *curses)
{
	const struct s_event_player_create	*player_info = &event->info.plc;
	struct s_curses_player				*player;
	size_t								comment_len;

	assert(player_info->num < MAX_PLAYERS && curses->num_players < MAX_PLAYERS);
	if (player_info->num >= MAX_PLAYERS || curses->num_players == MAX_PLAYERS)
		return ;
	player = curses->players + player_info->num;
	player->id = player_info->id;
	player->weight = player_info->weight;
	ft_strcpy(player->name, event->arbitrary_string);
	ft_strcpy(player->comment, event->arbitrary_string2);
	comment_len = ft_strlen(player->comment);
	ft_memcpy(player->code, &event->arbitrary_string2[comment_len + 1],
				player->weight);
	++curses->num_players;
}
