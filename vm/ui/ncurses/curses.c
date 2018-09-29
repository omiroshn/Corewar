/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 14:58:42 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/20 16:44:30 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "curses.h"
#include "render.h"
#include "libft.h"
#include <ncurses.h>
#include <stdlib.h>

static void	ncurses_init(void)
{
	saveterm();
	endwin();
	initscr();
	start_color();
	curs_set(0);
	timeout(0);
	cbreak();
	noecho();
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COLOR_WHITE, 255, 255, 255);
	init_pair(kCanvasColor, COLOR_BLACK, COLOR_WHITE);
	init_pair(kProgram1CounterColor, COLOR_BLACK, COLOR_GREEN);
	init_pair(kProgram2CounterColor, COLOR_BLACK, COLOR_BLUE);
	init_pair(kProgram3CounterColor, COLOR_BLACK, COLOR_RED);
	init_pair(kProgram4CounterColor, COLOR_BLACK, COLOR_CYAN);
	init_pair(kPlayer1Color, COLOR_GREEN, COLOR_BLACK);
	init_pair(kPlayer2Color, COLOR_BLUE, COLOR_BLACK);
	init_pair(kPlayer3Color, COLOR_RED, COLOR_BLACK);
	init_pair(kPlayer4Color, COLOR_CYAN, COLOR_BLACK);
	init_pair(kNoMansLand, COLOR_WHITE, COLOR_BLACK);
	init_pair(kWindowBackgroundColor, COLOR_BLACK, COLOR_BLACK);
	keypad(stdscr, TRUE);
}

bool		curses_init(struct s_curses *ret)
{
	int	i;

	ft_memset(ret, 0, sizeof(struct s_curses));
	i = -1;
	while (++i < MEM_SIZE)
		ret->cells[i].player_num = INVALID_PLAYER_NUM;
	ret->processes = DLIST_INITIALIZER;
	ret->cycles_to_die = CYCLE_TO_DIE;
	init_timer(&ret->timer);
	ncurses_init();
	ret->main.h = 80;
	ret->main.w = 197;
	ret->main.win = newwin(ret->main.h, ret->main.w, 0, 0);
	refresh();
	ret->info.h = 80;
	ret->info.w = 58;
	ret->info.win = newwin(ret->info.h, ret->info.w, 0, 196);
	refresh();
	return (ret->main.win && ret->info.win);
}

void		curses_deinit(struct s_curses *curses)
{
	dlist_release(&curses->processes, free, true);
//	ncurses_release();
}

int			curses_get_event_key(void)
{
	const int key = getch();

	if (key == ERR)
		return (kCursesKeyNone);
	else if (!ft_isascii(key))
		return (kCursesKeyNone);
	return (key);
}
