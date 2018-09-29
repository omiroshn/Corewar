/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:27:10 by admin             #+#    #+#             */
/*   Updated: 2018/09/08 10:29:47 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor_file.h"
#include "libft.h"
#include "swap.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdbool.h>

static bool			cor_file_is_valid(struct s_cor_file *file, const char *path)
{
	const size_t	code_size = swap32(file->header->prog_size);

	if (file->size <= sizeof(struct s_header))
		ft_dprintf(2, "%s: {red}%s{eoc}\n", path, "insufficient file size");
	else if (file->size - sizeof(struct s_header) != code_size)
		ft_dprintf(2, "%s: {red}%s{eoc}\n", path, "unexpected file size");
	else if (file->header->magic != COREWAR_EXEC_CIGAM)
		ft_dprintf(2, "%s: {red}%s{eoc}\n", path, "invalid magic number");
	else if (ft_strlen(file->header->comment) == 0)
		ft_dprintf(2, "%s: {red}%s{eoc}\n", path, "empty comment");
	else if (ft_strlen(file->header->prog_name) == 0)
		ft_dprintf(2, "%s: {red}%s{eoc}\n", path, "empty name");
	else if (code_size >= CHAMP_MAX_SIZE && code_size == 0)
		ft_dprintf(2, "%s: %s: %zu\n", path, "invalid code size", code_size);
	else
	{
		file->header->prog_size = code_size;
		return (true);
	}
	return (false);
}

bool				cor_file_init_common(
						struct s_cor_file *cor,
						void *file_content,
						size_t file_size,
						const char *file_name)
{
	cor->size = file_size;
	cor->content = file_content;
	cor->header = file_content;
	cor->text_section = file_content + sizeof(t_header);
	return (cor_file_is_valid(cor, file_name));
}

struct s_cor_file	*cor_file_init_data(
						void *file_content,
						size_t file_size,
						const char *file_name)
{
	struct s_cor_file	*ret;

	ret = malloc(sizeof(struct s_cor_file));
	ret->free_content = false;
	if (!cor_file_init_common(ret, file_content, file_size, file_name))
	{
		cor_file_release(ret);
		ret = NULL;
	}
	return (ret);
}

struct s_cor_file	*cor_file_init(const char *path)
{
	void				*file_content;
	const size_t		file_size = ft_read_file(path, &file_content);
	struct s_cor_file	*ret;

	if (file_size == 0 || file_content == NULL)
		return (NULL);
	ret = malloc(sizeof(struct s_cor_file));
	ret->free_content = true;
	if (!cor_file_init_common(ret, file_content, file_size, fs_file_name(path)))
	{
		cor_file_release(ret);
		ret = NULL;
	}
	return (ret);
}

void				cor_file_release(struct s_cor_file *cor_file)
{
	if (cor_file->free_content)
		free(cor_file->content);
	free(cor_file);
}
