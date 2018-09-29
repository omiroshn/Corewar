/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:12:04 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 13:25:14 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "deinit.h"
#include "vm_controller.h"
#include "ncurses_observer.h"
#include "terminal_observer.h"

#include <stdlib.h>

void	vm_deinit(struct s_vm *vm)
{
	dlist_release(&vm->arena.players, player_release, true);
	dlist_release(&vm->arena.processes, process_release, true);
	if (vm->cfg.ui == kUiTypeNcurses)
		unregister_ncurses_observer();
	else if (vm->cfg.ui == kUiTypeTerminal)
		unregister_terminal_observer();
	vm_controller_release(vm->controller);
}
