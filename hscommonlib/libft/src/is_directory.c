/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:01:36 by hshakula          #+#    #+#             */
/*   Updated: 2018/06/19 20:12:09 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>

int		is_directory(const char *path)
{
	const int fd = open(path, O_DIRECTORY);

	close(fd);
	return (fd != -1);
}

size_t	ft_read_file(const char *path, void **file)
{
	int		fd;
	size_t	ret;

	*file = NULL;
	if (is_directory(path))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror(path);
		return (0);
	}
	ret = ft_read_file_fd(fd, file);
	close(fd);
	return (ret);
}

size_t	ft_read_file_fd(int fd, void **file)
{
	ssize_t	size;
	ssize_t	ret;

	*file = NULL;
	if (fd == -1)
		return (0);
	size = lseek(fd, 0, SEEK_END);
	if (size == 0)
		return (0);
	lseek(fd, 0, SEEK_SET);
	*file = malloc(size + 1);
	((char*)*file)[size] = '\0';
	ret = read(fd, *file, size);
	if (ret != size)
		return (0);
	return (ret);
}

void	*map_file(const char *path, int64_t *size)
{
	const int	fd = open(path, O_RDONLY);
	struct stat	stat;
	void		*ret;

	*size = 0;
	if (fd == -1)
		return (NULL);
	if (fstat(fd, &stat) == -1)
		return (NULL);
	ret = mmap(0, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (ret == MAP_FAILED)
		return (NULL);
	*size = stat.st_size;
	return (ret);
}

void	unmap_file(const void *file_ptr, int64_t size)
{
	munmap((void*)file_ptr, size);
}
