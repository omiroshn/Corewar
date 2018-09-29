/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:07:31 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 13:21:58 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "init.h"
#include "libft.h"
#include "curses.h"
#include "cor_file.h"
#include "ft_printf.h"
#include "arg_parsing.h"
#include "vm_controller.h"
#include "game_observer.h"
#include "ncurses_observer.h"
#include "terminal_observer.h"

#include <limits.h>
#include <stdlib.h>
#include <assert.h>

void			print_usage(const char *exe_path, const char *err_msg)
{
	int indent;

	if (err_msg)
		ft_dprintf(2, "Error: %s: %s.\n", exe_path, err_msg);
	indent = ft_printf("Usage: %s ", exe_path);
	ft_printf("[--verbose] [--help [-h]] [--server [-s]]\n");
	ft_printf("%*s[--client [-c]] [--visualization [-v]]\n", indent, "");
	ft_printf("%*s[-dump nbr_cycles]\n", indent, "");
	ft_printf("%*s[[-n number] champion1.cor] ...\n", indent, "");
	exit(0);
}

static void		init_default_values(struct s_vm *vm)
{
	ft_memset(vm, 0, sizeof(struct s_vm));
	vm->cfg.dump_period = INT32_MAX;
	vm->cfg.dump_bytes_per_row = 32;
	vm->cfg.verbose = false;
	vm->cfg.type = kVmTypeOrdinary;
	vm->cfg.ui = kUiTypeTerminal;
	vm->arena.players = DLIST_INITIALIZER;
	vm->arena.processes = DLIST_INITIALIZER;
	vm->arena.cycles_to_die = CYCLE_TO_DIE;
	vm->arena.cycles_counter = 0;
	vm->arena.num_checkups_wo_decrease = 0;
	vm->arena.life_cycle.last_alive_player = -1;
	vm->arena.life_cycle.num_live_calls = 0;
}

bool			vm_init(struct s_vm *vm, int ac, char **av)
{
	if (ac == 1)
		print_usage(av[0], NULL);
	init_default_values(vm);
	parse_args(vm, ac, av);
	if (vm->arena.players.size > MAX_PLAYERS)
		print_usage(av[0], "too much players specified. \
			Tell me if you get here");
	if (vm->cfg.ui == kUiTypeNcurses)
		register_ncurses_observer();
	else if (vm->cfg.ui == kUiTypeTerminal)
		register_terminal_observer(vm->cfg.verbose);
	register_game_observer(vm);
	vm->controller = vm_controller_init(vm);
	return (true);
}
