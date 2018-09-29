/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:59:28 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/16 18:05:56 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "op.h"
# include "operations/operations.h"
# include <inttypes.h>
# include <stddef.h>

struct s_arena;
struct s_player;

struct				s_process
{
	int32_t				registers[REG_NUMBER];
	uint8_t				*pc;
	uint8_t				*operand_pc;
	uint32_t			owner_id;
	int32_t				id;
	uint16_t			num_cycles_to_execution;
	uint8_t				carry;
	t_operation_type	current_op;
	bool				is_alive;
};

struct s_process	*process_init(
						void *pc,
						int32_t player_id,
						struct s_arena *arena);
struct s_process	*process_copy(
						struct s_process *src,
						size_t pc_offset,
						struct s_arena *arena);
bool				process_is_dead(void *process, void *arena);
void				process_reset(void *process, void *ctx);
void				process_cycle_update(
						struct s_process *process,
						struct s_arena *arena);
void				process_release(void *process);

#endif
