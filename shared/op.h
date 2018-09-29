/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2018/09/03 16:39:45 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "param.h"
# include <stdbool.h>

# define IND_SIZE 2
# define REG_SIZE 4
# define DIR_SIZE REG_SIZE

# define REG_CODE 1
# define DIR_CODE 2
# define IND_CODE 3

# define MAX_ARGS_NUMBER 4
# define MAX_PLAYERS 4
# define INVALID_PLAYER_NUM (uint8_t)(-1)
# define MEM_SIZE (4 * 1024)
# define IDX_MOD (MEM_SIZE / 8)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPARATOR_CHAR ','

# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"

# define REG_NUMBER 16

# define CYCLE_TO_DIE 1536
# define CYCLE_DELTA 50
# define NBR_LIVE 21
# define MAX_CHECKS 10

typedef enum	e_arg_type
{
	T_REG = 1,
	T_DIR = 2,
	T_IND = 4
}				t_arg_type;

# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define COREWAR_EXEC_MAGIC 0x00ea83f3
# define COREWAR_EXEC_CIGAM 0xf383ea00

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_op
{
	char			*label;
	int				nb_arg;
	t_arg_type		type[MAX_ARGS_NUMBER];
	int				opcode;
	int				cycle_cost;
	char			*desc;
	bool			encoded_input;
	int				dir_size;
}					t_op;

extern const t_op	g_op_tab[];

typedef enum		e_operation_type
{
	kOperationNone = -1,
	kOperationLive,
	kOperationLd,
	kOperationSt,
	kOperationAdd,
	kOperationSub,
	kOperationAnd,
	kOperationOr,
	kOperationXor,
	kOperationZjmp,
	kOperationLdi,
	kOperationSti,
	kOperationFork,
	kOperationLld,
	kOperationLldi,
	kOperationLfork,
	kOperationAff,
	kOperationMul,
	kOperationDiv,
	kOperationCmp,
	kOperationJne,
	kOperationsTotal
}					t_operation_type;

bool				operation_is_valid(t_operation_type op);
bool				valid_param_type(t_param_type param, t_arg_type ground);

#endif
