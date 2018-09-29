/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 23:58:05 by admin             #+#    #+#             */
/*   Updated: 2018/09/20 17:42:41 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

struct s_curses;
struct s_win;

enum
{
	kRowSize = 64,
	kOffsetX = 3,
	kOffsetY = 2,
	kBacklightDuration = 50,
	kPlayer1Color = 1,
	kPlayer2Color,
	kPlayer3Color,
	kPlayer4Color,
	kNoMansLand,
	kProgram1CounterColor,
	kProgram2CounterColor,
	kProgram3CounterColor,
	kProgram4CounterColor,
	kCanvasColor,
	kWindowBackgroundColor
};

void	render(struct s_curses *curses);
void	render_last_screen(struct s_curses *curses);
void	render_info_panel(struct s_win *panel, struct s_curses *curses);

#endif
