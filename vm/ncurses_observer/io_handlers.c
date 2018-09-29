/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:59:58 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 13:01:46 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NCURSES_OBSERVER_IMPLEMENTATION
#include "ncurses_observer_private.h"
#include "mempool_io.h"
#include "curses.h"
#include "shift.h"

#include <assert.h>
#include <stdlib.h>

void		ncurses_proc_write(struct s_event *event, struct s_curses *curses)
{
	const struct s_event_proc_write	*wr = &event->info.wr;
	const struct s_curses_player	*player;
	void							*process_ptr;
	uint8_t							player_num;

	player = ncurses_find_player(curses, wr->master_id, &player_num);
	assert(player);
	if (!player)
		return ;
	process_ptr = curses->mem_pool + wr->position;
	mempool_write(process_ptr, (void*)&wr->value, 4, curses->mem_pool);
	ncurses_cell_update(wr->position, 4, player_num, curses);
}

static bool	process_predicate(void *process_ptr, void *ctx)
{
	const struct s_curses_process *process = process_ptr;

	return (process->id == *((int32_t*)ctx));
}

void		ncurses_proc_move(struct s_event *event, struct s_curses *curses)
{
	struct s_curses_process	*process;

	process = dlist_find_if(&curses->processes,
		process_predicate, &event->info.mv.proc_id);
	assert(process);
	if (!process)
		return ;
	process->position = event->info.mv.position;
}

void		ncurses_proc_death(struct s_event *event, struct s_curses *curses)
{
	struct s_curses_process	*process;
	struct s_curses_player	*player;

	process = dlist_find_if(&curses->processes,
		process_predicate, &event->info.pd.proc_id);
	assert(process);
	if (!process)
		return ;
	player = ncurses_find_player(curses, process->owner_id, NULL);
	assert(player);
	if (player)
		--player->num_processes;
	dlist_remove_if(&curses->processes, process_predicate,
		free, &event->info.pd.proc_id);
}
