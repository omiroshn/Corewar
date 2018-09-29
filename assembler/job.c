/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:17:08 by Admin             #+#    #+#             */
/*   Updated: 2018/09/09 13:30:15 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "job.h"
#include "player.h"
#include "libft.h"
#include "dlist.h"
#include "ft_printf.h"
#include "cor_file.h"
#include "error_logger.h"
#include "error_logger_print.h"
#include "cor_file_disassemble.h"
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

struct s_job		*job_init(char *file_path)
{
	struct s_job	*job;
	void			*file_content;
	const size_t	file_size = ft_read_file(file_path, &file_content);

	if (file_size == 0 || file_content == NULL)
		return (NULL);
	job = ft_memalloc(sizeof(struct s_job));
	job->file_content = file_content;
	job->file_size = file_size;
	job->file_path = file_path;
	job->file_name = fs_file_name(file_path);
	return (job);
}

void				job_release(struct s_job *job)
{
	free(job->file_content);
	free(job);
}

static void			job_assemble(struct s_job *job)
{
	const struct s_player	*player = player_init(job);
	char					*out_path;
	struct s_dlist			*err_list;

	if (player == NULL)
	{
		err_list = log_fflush();
		ft_dprintf(2, "Player build error%s\n", err_list ? ":" : ".");
		print_error_list(err_list);
		dlist_release(err_list, log_release_err, false);
		return ;
	}
	out_path = fs_change_extension(job->file_path, "cor");
	if (player_compile((void*)player, out_path, job->file_name))
		ft_printf("Writing output program to %s\n", out_path);
	else
		ft_dprintf(2, "Failed to compile player:\n");
	free(out_path);
	player_release((void*)player);
}

static void			job_disassemble(struct s_job *job)
{
	struct s_cor_file	*cor;
	char				*out_path;
	int					out_fd;
	bool				ret;

	ret = false;
	cor = cor_file_init_data(job->file_content, job->file_size, job->file_name);
	if (cor == NULL)
		return ;
	out_path = fs_change_extension(job->file_path, "ds");
	if ((out_fd = open(out_path, O_CREAT | O_TRUNC | O_WRONLY,
								S_IRWXU | S_IRWXG | S_IROTH)) == -1)
		perror("Failed to create out .ds file");
	else
	{
		ret = cor_file_disassemble(cor, out_fd);
		close(out_fd);
		if (!ret)
			remove(out_path);
	}
	free(out_path);
	cor_file_release(cor);
}

static const t_job_executor	g_job_executors[kJobTypesTotal] =
{
	job_assemble,
	job_disassemble
};

void				job_execute(void *job, void *ctx)
{
	g_job_executors[((struct s_asm*)ctx)->job_type](job);
}
