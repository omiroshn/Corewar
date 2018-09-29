/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:43:00 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/13 23:06:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "op.h"
# include <stdbool.h>

struct s_arena;
struct s_process;

typedef void	(*t_op_fnc)(struct s_arena *arena, struct s_process *process);
void			op_live(struct s_arena *arena, struct s_process *process);
void			op_ld(struct s_arena *arena, struct s_process *process);
void			op_st(struct s_arena *arena, struct s_process *process);
void			op_add(struct s_arena *arena, struct s_process *process);
void			op_sub(struct s_arena *arena, struct s_process *process);
void			op_and(struct s_arena *arena, struct s_process *process);
void			op_or(struct s_arena *arena, struct s_process *process);
void			op_xor(struct s_arena *arena, struct s_process *process);
void			op_zjmp(struct s_arena *arena, struct s_process *process);
void			op_ldi(struct s_arena *arena, struct s_process *process);
void			op_sti(struct s_arena *arena, struct s_process *process);
void			op_fork(struct s_arena *arena, struct s_process *process);
void			op_lld(struct s_arena *arena, struct s_process *process);
void			op_lldi(struct s_arena *arena, struct s_process *process);
void			op_lfork(struct s_arena *arena, struct s_process *process);
void			op_aff(struct s_arena *arena, struct s_process *process);
void			op_mul(struct s_arena *arena, struct s_process *process);
void			op_div(struct s_arena *arena, struct s_process *process);
void			op_cmp(struct s_arena *arena, struct s_process *process);
void			op_jne(struct s_arena *arena, struct s_process *process);

extern t_op_fnc	g_op_functions[kOperationsTotal];

#endif
