/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:04:30 by yvikhrov          #+#    #+#             */
/*   Updated: 2018/06/16 20:51:01 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_private.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

t_gnl	*check_list(t_gnl *head, int fd, t_gnl *tmp1, t_gnl *tmp)
{
	if (head == NULL)
	{
		if ((tmp = (t_gnl*)malloc(sizeof(t_gnl))) != NULL)
		{
			tmp->next = NULL;
			tmp->fd = fd;
			tmp->buf = NULL;
		}
		return (tmp);
	}
	else
	{
		tmp = head;
		tmp1 = head;
		while (tmp)
		{
			if (tmp->fd == fd)
				return (tmp);
			tmp1 = tmp;
			tmp = tmp->next;
		}
		return ((tmp1->next = check_list(NULL, fd, tmp1, tmp)));
	}
}

int		write_line(t_gnl *gnl, char **line, int flag)
{
	char	buf[BUFF_SIZE + 1];
	char	*s;
	char	*tmp;
	int		ret;

	ft_memset(buf, 0, sizeof(buf));
	while ((ret = read(gnl->fd, buf, BUFF_SIZE)) > 0)
	{
		flag = 1;
		if ((s = ft_strchr(buf, '\n')))
		{
			tmp = ft_strsub(buf, 0, s - buf);
			*line = *line ? ft_strjoin_front(*line, tmp) : ft_strdup(tmp);
			free(tmp);
			if (ret - (s - buf + 1) > 0)
				gnl->buf = ft_strsub(buf, s - buf + 1, ret - (s - buf + 1));
			return (1);
		}
		*line = *line ? ft_strjoin_front(*line, buf) : ft_strdup(buf);
		ft_memset(buf, 0, sizeof(buf));
	}
	if (ret == -1)
		return (-1);
	return ((*line != NULL && **line != '\0') ? 1 : 0);
}

int		init_line(t_gnl *gnl, char **line)
{
	char	*s;
	size_t	len;
	char	*tmp;

	*line = NULL;
	if (gnl->buf != NULL)
	{
		if ((s = ft_strchr(gnl->buf, '\n')))
		{
			len = s - gnl->buf;
			*line = ft_strsub(gnl->buf, 0, len);
			tmp = gnl->buf;
			if ((len = ft_strlen(gnl->buf) - len - 1) != 0)
				gnl->buf = ft_strsub(gnl->buf, s - gnl->buf + 1, len);
			else
				gnl->buf = NULL;
			free(tmp);
			return (0);
		}
		*line = ft_strdup(gnl->buf);
		free(gnl->buf);
		gnl->buf = NULL;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*current_gnl;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL ||
		(current_gnl = check_list(gnl, fd, NULL, NULL)) == NULL)
		return (-1);
	if (gnl == NULL)
		gnl = current_gnl;
	if (init_line(current_gnl, line))
		return (write_line(current_gnl, line, 0));
	return (1);
}
