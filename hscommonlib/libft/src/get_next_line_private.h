/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:46:29 by hshakula          #+#    #+#             */
/*   Updated: 2018/02/25 14:14:33 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_PRIVATE_H
# define GET_NEXT_LINE_PRIVATE_H

# define BUFF_SIZE 1

typedef struct		s_gnl
{
	char			*buf;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

#endif
