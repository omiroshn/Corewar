/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_observer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:54:01 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 12:53:52 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_OBSERVER_H
# define NCURSES_OBSERVER_H

# include <inttypes.h>

struct s_curses;

void					register_ncurses_observer(void);
void					unregister_ncurses_observer(void);

struct s_curses_player	*ncurses_find_player(
							struct s_curses *curses,
							int32_t id,
							uint8_t *num);

#endif
