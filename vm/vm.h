/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:49:55 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 13:21:33 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "timer.h"
# include "op.h"
# include "dlist.h"
# include "player.h"
# include "server.h"
# include "hashmap.h"

# include <stdbool.h>

struct s_vm_controller;

# define MEMPOOL_POS(ptr, mempool_ptr) ((uint16_t)(ptr - (void*)mempool_ptr))

typedef enum		e_vm_type
{
	kVmTypeOrdinary = 0,
	kVmTypeServer,
	kVmTypeClient,
	kVmTypesTotal
}					t_vm_type;

typedef enum		e_ui_type
{
	kUiTypeTerminal,
	kUiTypeNcurses
}					t_ui_type;

struct				s_life_cycle
{
	uint16_t	num_live_calls;
	int32_t		last_alive_player;
};

struct				s_vm_config
{
	t_vm_type	type;
	t_ui_type	ui;
	int			dump_bytes_per_row;
	int32_t		dump_period;
	bool		verbose;
};

struct				s_arena
{
	uint8_t				memory_pool[MEM_SIZE];

	struct s_dlist		players;
	t_hashmap			player_map;
	struct s_dlist		processes;

	uint32_t			cycles_counter;
	int16_t				cycles_to_die;
	uint8_t				num_checkups_wo_decrease;

	struct s_life_cycle	life_cycle;
};

struct				s_vm
{
	struct s_vm_controller	*controller;
	struct s_vm_config		cfg;
	struct s_arena			arena;
};

typedef bool		(*t_vm_executor)(struct s_vm *vm, char **err);
bool				vm_execute_ordinary(struct s_vm *vm, char **err);
bool				vm_execute_server(struct s_vm *vm, char **err);
bool				vm_execute_client(struct s_vm *vm, char **err);

#endif
