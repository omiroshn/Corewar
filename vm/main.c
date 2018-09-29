/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:24:23 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 13:22:31 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "dump.h"
#include "init.h"
#include "deinit.h"
#include "curses.h"
#include "check_up.h"
#include "cor_file.h"
#include "ft_printf.h"
#include "vm_controller.h"
#include "ncurses_observer.h"

#include <fcntl.h>
#include <stdlib.h>

static void	update_game(struct s_vm *vm)
{
	post_new_cycle(
		vm->arena.cycles_counter,
		vm->arena.life_cycle.last_alive_player,
		vm->arena.life_cycle.num_live_calls);
	++vm->arena.cycles_counter;
	if (vm->arena.cycles_counter % vm->arena.cycles_to_die == 0)
		check_up(&vm->arena);
	dlist_iterate(
		&vm->arena.processes,
		(t_dlist_iter_fnc)process_cycle_update,
		&vm->arena);
}

static void	setup_game(struct s_vm *vm)
{
	struct s_dlist_iter	iter;
	struct s_player		*player;
	const int			player_offset = MEM_SIZE / vm->arena.players.size;
	void				*pool_ptr;
	int					i;

	vm->arena.player_map = hashmap_init(MAX_PLAYERS * 4, kHashmapKeyTypeInt);
	iter = dlist_iter_init(&vm->arena.players);
	i = -1;
	while (++i < vm->arena.players.size)
	{
		player = dlist_iter_data(&iter);
		pool_ptr = vm->arena.memory_pool + player_offset * i;
		hashmap_put(vm->arena.player_map, &player->id, player);
		ft_memcpy(pool_ptr, player->cor_file->text_section,
				player->cor_file->header->prog_size);
		player->num = i;
		player_introduce_yourself(player);
		dlist_push_front_data(&vm->arena.processes,
							process_init(pool_ptr, player->id, &vm->arena));
		dlist_next(&iter);
	}
}

bool		vm_execute_ordinary(struct s_vm *vm, char **err)
{
	struct s_player	*player;

	setup_game(vm);
	while (vm->arena.processes.size && vm->arena.cycles_to_die != 0)
	{
		vm_controller_read_input(vm->controller);
		if (vm_should_update_game(vm->controller))
		{
			update_game(vm);
			if (vm->arena.cycles_counter == vm->cfg.dump_period)
			{
				dump_mempool(vm->arena.memory_pool, vm->cfg.dump_bytes_per_row);
				break ;
			}
		}
	}
	if (vm->arena.cycles_counter != vm->cfg.dump_period)
	{
		player = hashmap_get(vm->arena.player_map,
							 &vm->arena.life_cycle.last_alive_player);
		if (player)
			post_end_of_game(player->num);
	}
	return (true);
}

static t_vm_executor	g_vm_executors[kVmTypesTotal] =
{
	vm_execute_ordinary,
	vm_execute_server,
	vm_execute_client
};

static void	vm_execute(struct s_vm *vm)
{
	char *err;

	err = NULL;
	if (!g_vm_executors[vm->cfg.type](vm, &err) && err != NULL)
		ft_dprintf(2, "VM execution error: %s\n", err);
}

int			main(int ac, char **av)
{
	struct s_vm		vm;

	if (vm_init(&vm, ac, av))
		vm_execute(&vm);
	vm_deinit(&vm);
	return (0);
}
