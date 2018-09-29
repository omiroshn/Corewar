/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_path_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:52:32 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 14:02:36 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*fs_change_extension(const char *path, const char *new_ext)
{
	const char		*ext = ft_strrchr(path, '.');
	const size_t	len = (ext == NULL) ? ft_strlen(path) : ext - path;
	char			*ret;

	ret = malloc(len + 1 + ft_strlen(new_ext) + 1);
	ft_strncpy(ret, path, len);
	ret[len] = '.';
	ft_strcpy(ret + len + 1, new_ext);
	return (ret);
}

const char	*fs_file_name(const char *path)
{
	const char *file_name = ft_strrchr(path, '/');

	if (file_name == NULL)
		file_name = path;
	else
		file_name++;
	return (file_name);
}
