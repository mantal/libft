/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:35:16 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 17:06:55 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include "error.h"

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/mman.h>
#include <sys/stat.h>

int				ft_open(const char *path, int oflag, ...)
{
	va_list	ap;
	int		r;

	va_start(ap, oflag);
	r = open(path, oflag, ap);
	if (r < 0)
	{
		ft_error();
		return (r);
	}
	return (r);
}

int				ft_close(int fd)
{
	if (close(fd) < 0)
	{
		ft_error();
		return (-1);
	}
	return (0);
}

static t_array	*g_iomap = NULL;

static int		get_index(void *p)
{
	t_uint	i;
	t_iomap	im;

	i = 0;
	while (i < g_iomap->size)
	{
		im = *(t_iomap *)array_get(g_iomap, i);
		if (im.p == p)
			return (i);
		i++;
	}
	return (-1);
}

char			*io_map_file(int fd, int prot)
{
	struct stat	stats;
	char		*res;

	if (!g_iomap)
		g_iomap = array_new_s(sizeof(t_iomap));
	if (fstat(fd, &stats) < 0)
	{
		ft_error();
		return (NULL);
	}
	res = mmap(NULL, stats.st_size, prot, MAP_FILE | MAP_SHARED, fd, 0);
	array_add(g_iomap, (t_iomap[]) { { res, stats.st_size } });
	return (res);
}

int				io_unmap_file(char *p)
{
	int		i;
	size_t	size;

	i = get_index(p);
	if (i < 0)
	{
		errno = EFAULT;
		ft_error();
		return (-1);
	}
	size = (*(t_iomap *)array_get(g_iomap, i)).size;
	if (munmap(p, size) < 0)
	{
		ft_error();
		return (-1);
	}
	return (0);
}
