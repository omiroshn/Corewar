/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:27:11 by admin             #+#    #+#             */
/*   Updated: 2018/09/09 13:52:58 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_FILE_H
# define COR_FILE_H

# include "op.h"
# include <stddef.h>

struct				s_cor_file
{
	void			*content;
	t_header		*header;
	void			*text_section;
	size_t			size;
	bool			free_content;
};

struct s_cor_file	*cor_file_init(const char *path);
struct s_cor_file	*cor_file_init_data(
						void *file_content,
						size_t file_size,
						const char *file_name);
void				cor_file_release(struct s_cor_file *cor_file);

#endif
