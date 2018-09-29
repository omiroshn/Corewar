/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   livebreakdown.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:42:01 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/20 17:43:55 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIVEBREAKDOWN_H
# define LIVEBREAKDOWN_H

# define LIVEBREAKDOWN "--------------------------------------------------"

struct s_win;
struct s_curses;

enum
{
	kLiveBreakdownLength = 50
};

void		draw_live_breakdown(
				struct s_win *window,
				struct s_curses *curses,
				int y,
				double *livebreakdown);

#endif
