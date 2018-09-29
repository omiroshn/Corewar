/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:48:30 by Admin             #+#    #+#             */
/*   Updated: 2018/09/03 22:49:25 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "asm.h"
#include "job.h"
#include "ft_printf.h"
#include "libft.h"
#include "token_parser.h"

void	asm_init_default_values(struct s_asm *assembler)
{
	assembler->job_list = DLIST_INITIALIZER;
	assembler->job_type = kJobStandard;
}

int		asm_parse_flag(struct s_asm *assembler, int ac, char **av, int i)
{
	const char *flag = &av[i][1];

	if (ft_strequ(flag, "d"))
		assembler->job_type = kJobDisassemble;
	return (0);
}

bool	asm_parse_args(struct s_asm *assembler, int ac, char **av)
{
	struct s_job	*job;
	int				offset;
	int				i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if ((offset = asm_parse_flag(assembler, ac, av, i)) == -1)
				return (false);
			i += offset;
		}
		else
		{
			job = job_init(av[i]);
			if (job == NULL)
				ft_dprintf(2, "Failed to load \"%s\"\n", av[i]);
			else
				dlist_push_back_data(&assembler->job_list, job);
		}
	}
	return (true);
}

bool	asm_init(struct s_asm *assembler, int ac, char **av)
{
	asm_init_default_values(assembler);
	token_parser_init();
	if (!asm_parse_args(assembler, ac, av))
		return (false);
	if (assembler->job_list.size == 0)
	{
		ft_dprintf(2, "No valid .s files specified.");
		return (false);
	}
	return (true);
}
