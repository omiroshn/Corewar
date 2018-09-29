/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:17:08 by Admin             #+#    #+#             */
/*   Updated: 2018/09/09 13:30:27 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_H
# define JOB_H

# include <stddef.h>

struct s_dlist;

struct				s_job
{
	char			*file_path;
	const char		*file_name;
	char			*file_content;
	size_t			file_size;
};

typedef void		(*t_job_executor)(struct s_job *job);

struct s_job		*job_init(char *file_path);
void				job_execute(void *job, void *ctx);
void				job_release(struct s_job *job);

#endif
