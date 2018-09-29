/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:48:30 by Admin             #+#    #+#             */
/*   Updated: 2018/09/03 22:49:04 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deinit.h"
#include "asm.h"
#include "job.h"
#include "token_parser.h"

void	asm_deinit(struct s_asm *assembler)
{
	dlist_release(&assembler->job_list, (void (*)(void*))job_release, true);
	token_parser_deinit();
}
