/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_observer_private.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:42:00 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 12:49:12 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_OBSERVER_PRIVATE_H
# define TERMINAL_OBSERVER_PRIVATE_H

# ifndef TERMINAL_OBSERVER_IMPLEMENTATION
#  error "Private header file shouldn't be included out of scope."
# endif

# include "terminal_observer.h"

struct s_event;

struct	s_termobs_desc
{
	bool	verbose;
};

void	termobs_proc_move(
			struct s_event *event,
			struct s_termobs_desc *desc);
void	termobs_proc_write(
			struct s_event *event,
			struct s_termobs_desc *desc);
void	termobs_proc_create(
			struct s_event *event,
			struct s_termobs_desc *desc);
void	termobs_proc_death(
			struct s_event *event,
			struct s_termobs_desc *desc);
void	termobs_aff(
			struct s_event *event,
			struct s_termobs_desc *desc);
void	termobs_new_cycle(
			struct s_event *event,
			struct s_termobs_desc *desc);
void	termobs_end_of_game(
			struct s_event *event,
			struct s_termobs_desc *desc);
void	termobs_player_create(
			struct s_event *event,
			struct s_termobs_desc *desc);
void	termobs_proc_live(
			struct s_event *event,
			struct s_termobs_desc *desc);

#endif
