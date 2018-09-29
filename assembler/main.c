/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:48:30 by Admin             #+#    #+#             */
/*   Updated: 2018/09/03 22:49:44 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "init.h"
#include "deinit.h"
#include "op.h"
#include "job.h"

int	main(int ac, char **av)
{
	struct s_asm assembler;

	if (asm_init(&assembler, ac, av))
		dlist_iterate(&assembler.job_list, job_execute, &assembler);
	asm_deinit(&assembler);
}
