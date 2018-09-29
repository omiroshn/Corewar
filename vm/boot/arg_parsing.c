/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 13:16:26 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:25:18 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parsing.h"
#include "vm.h"
#include "libft.h"
#include "init.h"
#include "ft_printf.h"

static bool		player_id_is_available(int32_t id, struct s_dlist *players)
{
	struct s_dlist_iter	iter;
	struct s_player		*player;

	if (id == 0)
		return (false);
	iter = dlist_iter_init(players);
	while (iter.node != NULL)
	{
		player = dlist_iter_data(&iter);
		if (id == player->id)
			return (false);
		dlist_next(&iter);
	}
	return (true);
}

static int		parse_n_flag(struct s_arena *ar, int i, int ac, char **av)
{
	char			err_buf[128];
	int32_t			id;
	struct s_player	*player;

	if (i + 2 >= ac)
		print_usage(av[0], "-n requires two arguments");
	else if (ar->players.size >= MAX_PLAYERS)
		print_usage(av[0], "too much players specified");
	id = ft_atoi(av[i + 1]);
	if (!player_id_is_available(id, &ar->players))
	{
		ft_snprintf(err_buf, sizeof(err_buf),
			"player id %d is not available", id);
		print_usage(av[0], err_buf);
	}
	if ((player = player_init(av[i + 2], id)) == NULL)
		print_usage(av[0], "invalid player .cor file");
	dlist_push_back_data(&ar->players, player);
	ar->life_cycle.last_alive_player = player->id;
	return (2);
}

static int		parse_flag(struct s_vm *vm, int i, int ac, char **av)
{
	const char	*flag = &av[i][1];

	if (ft_strequ("dump", flag))
	{
		if (i + 1 == ac)
			print_usage(av[0], "-dump requires one argument");
		vm->cfg.dump_period = ft_atoi(av[i + 1]);
		if (vm->cfg.dump_period <= 0)
			print_usage(av[0], "invalid dump period");
		return (1);
	}
	else if (ft_strequ("n", flag))
		return (parse_n_flag(&vm->arena, i, ac, av));
	else if (ft_strequ("-verbose", flag))
		vm->cfg.verbose = true;
	else if (ft_strequ("s", flag) || ft_strequ("-server", flag))
		vm->cfg.type = kVmTypeServer;
	else if (ft_strequ("c", flag) || ft_strequ("-client", flag))
		vm->cfg.type = kVmTypeClient;
	else if (ft_strequ("v", flag) || ft_strequ("-visualization", flag))
		vm->cfg.ui = kUiTypeNcurses;
	else if (ft_strequ("h", flag) || ft_strequ("-help", flag))
		print_usage(av[0], NULL);
	return (0);
}

bool			parse_args(struct s_vm *vm, int ac, char **av)
{
	struct s_player	*player;
	int				i;
	int32_t			id;

	id = 0xffffffff;
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
			i += parse_flag(vm, i, ac, av);
		else if (vm->arena.players.size < MAX_PLAYERS)
		{
			while (!player_id_is_available(id, &vm->arena.players))
				id--;
			if ((player = player_init(av[i], id)) == NULL)
				print_usage(av[0], "invalid player .cor file");
			dlist_push_back_data(&vm->arena.players, player);
			vm->arena.life_cycle.last_alive_player = player->id;
		}
		else
			print_usage(av[0], "too much players specified");
	}
	return (true);
}
