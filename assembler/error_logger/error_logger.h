/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_logger.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 23:01:47 by admin             #+#    #+#             */
/*   Updated: 2018/09/09 13:30:44 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_LOGGER_H
# define ERROR_LOGGER_H

# include <stdbool.h>

# define STACK_ERR_STR(str) ((struct s_error_str){(char*)str, false})
# define HEAP_ERR_STR(str) ((struct s_error_str){(char*)str, true})
# define STACK_ERR_PAIR(str) STACK_ERR_STR(str), STACK_ERR_STR(filename)

struct s_dlist;

struct				s_error_str
{
	char	*s;
	bool	free;
};

struct				s_error_desc
{
	int					line;
	struct s_error_str	msg;
	struct s_error_str	file;
};

void				log_error_s(struct s_error_desc desc);
extern void			log_error(
						int line,
						struct s_error_str msg,
						struct s_error_str file);
struct s_dlist		*log_fflush(void);
void				log_release_err(void *err_ptr);

#endif
