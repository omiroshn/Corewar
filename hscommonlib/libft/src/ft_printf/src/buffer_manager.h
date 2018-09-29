/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/08/29 12:47:33 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_MANAGER_H
# define BUFFER_MANAGER_H

# include <stddef.h>

# define BUFF_SIZE 4096

void	reset_buffer(int fd, char *user_buff, size_t user_buff_size);
void	print_to_buffer(void *ptr, int size);
void	print_padding(char c, int amount);
void	set_buffer_error(void);
int		fflush_buffer(void);

struct	s_bufman
{
	char	buff[BUFF_SIZE + 1];
	size_t	buff_size;
	int		curr_size;
	int		total_size;
	char	*user_buff;
	int		fd;
	int		invalid;
};

#endif
