/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 22:46:06 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:12:02 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "buffer_manager.h"

#include <libft.h>
#include <stdlib.h>

const char *g_colors[] =
{
	"red", "green", "yellow", "blue", "magenta", "cyan", NULL
};

const char *g_color_ansi[] =
{
	"\x1b[31m", "\x1b[32m", "\x1b[33m", "\x1b[34m", "\x1b[35m", "\x1b[36m"
};

const char *g_end_of_color = "\x1b[0m";

int		color_is_available(char *s, int *color_len)
{
	int i;
	int curr_color_len;

	*color_len = ft_strclen(s, '}');
	if (*(s + *color_len) != '}')
		return (-1);
	i = -1;
	while (g_colors[++i] != NULL)
	{
		curr_color_len = ft_strlen(g_colors[i]);
		if (*color_len == curr_color_len &&
			!ft_strncmp(g_colors[i], s, curr_color_len))
		{
			++(*color_len);
			return (i);
		}
	}
	return (-1);
}

char	*process_color(char *s)
{
	int			color_len;
	const int	color = color_is_available(s + 1, &color_len);

	if (color != -1)
	{
		print_to_buffer((void*)g_color_ansi[color],
						ft_strlen(g_color_ansi[color]));
		s += color_len + 1;
	}
	else
	{
		if (!ft_strncmp("eoc", s + 1, color_len))
		{
			print_to_buffer((void*)g_end_of_color, ft_strlen(g_end_of_color));
			s += 1 + 3 + 1;
		}
		else
		{
			print_to_buffer("{", 1);
			++s;
		}
	}
	return (s);
}
