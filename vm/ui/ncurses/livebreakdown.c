/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   livebreakdown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:41:59 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/20 17:44:28 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "livebreakdown.h"
#include "render.h"
#include "curses.h"

void		draw_live_breakdown(
				struct s_win *window,
				struct s_curses *curses,
				int y,
				double *livebreakdown)
{
	int i;
	int length;
	int printed;

	i = -1;
	printed = 1;
	mvwprintw(window->win, y, 3, "[");
	while (++i < curses->num_players)
	{
		length = livebreakdown[i] * kLiveBreakdownLength + 0.5;
		length -= length + printed > 50 ? length + printed - 50 : 0;
		wattron(window->win, COLOR_PAIR(kPlayer1Color + i));
		mvwprintw(window->win, y, 3 + printed, "%.*s", length, LIVEBREAKDOWN);
		wattroff(window->win, COLOR_PAIR(kPlayer1Color + i));
		printed += length;
	}
	mvwprintw(window->win, y, 3 + printed, "]");
}
