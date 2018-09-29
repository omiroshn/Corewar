/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_observer_private.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:53:02 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 13:03:40 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_OBSERVER_PRIVATE_H
# define NCURSES_OBSERVER_PRIVATE_H

# ifndef NCURSES_OBSERVER_IMPLEMENTATION
#  error "Private header file shouldn't be included out of scope."
# endif

# include "ncurses_observer.h"
# include "curses.h"
# include "render.h"
# include "event.h"

# include <inttypes.h>

void					ncurses_proc_create(
							struct s_event *event,
							struct s_curses *curses);
void					ncurses_player_create(
							struct s_event *event,
							struct s_curses *curses);
void					ncurses_proc_write(
							struct s_event *event,
							struct s_curses *curses);
void					ncurses_proc_move(
							struct s_event *event,
							struct s_curses *curses);
void					ncurses_proc_death(
							struct s_event *event,
							struct s_curses *curses);
void					ncurses_end_of_game(
							struct s_event *event,
							struct s_curses *curses);
void					ncurses_check_up(
							struct s_event *event,
							struct s_curses *curses);
void					ncurses_ui_update(
							struct s_event *event,
							struct s_curses *curses);
void					ncurses_new_cycle(
							struct s_event *event,
							struct s_curses *curses);
void					ncurses_proc_live(
							struct s_event *event,
							struct s_curses *curses);

void					ncurses_cell_update(
							uint16_t offset,
							uint16_t size,
							uint8_t player_num,
							struct s_curses *curses);
void					ncurses_setup_mempool(
							struct s_curses *curses);

#endif
