/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 23:35:15 by admin             #+#    #+#             */
/*   Updated: 2018/09/18 23:39:30 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "dump.h"
#include "server.h"
#include "cor_file.h"
#include "check_up.h"

static bool	collect_users(struct s_vm *vm, struct s_server *server)
{
	struct s_client_info	*client;
	struct s_player			*player;
	int						id;

	id = -1;
	if (vm->arena.players.size)
		id = ((struct s_player*)dlist_back(&vm->arena.players))->id - 1;
	while (vm->arena.players.size < MAX_PLAYERS)
	{
		client = accept_client(server);
		if (client)
		{
			player = player_init_data(client->binary, client->binary_size,
									client->name, id--);
			player->cor_file->free_content = true;
			if (player)
			{
				dlist_push_back_data(&vm->arena.players, player);
				vm->arena.life_cycle.last_alive_player = player->id;
			}
		}
	}
	multicast_stop(server);
	return (true);
}

bool		vm_execute_server(struct s_vm *vm, char **err)
{
	struct s_server	*server;
	bool			ret;

	server = server_init();
	if (!server)
		return (false);
	if (!collect_users(vm, server))
	{
		server_release(server);
		return (false);
	}
	ret = vm_execute_ordinary(vm, err);
	server_release(server);
	return (ret);
}
