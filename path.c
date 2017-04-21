/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:56:25 by dlancar           #+#    #+#             */
/*   Updated: 2017/04/21 15:44:37 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include "libft.h"
#include "fterror.h"
#include "ftstring.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

char	*g_path_root = "/";

char		*path_to_absolute(const char *path)
{
	return (path_join(g_path_root, path));
}

bool		path_is_valid_dir(const char *path)
{
	struct stat statbuf;
	int			fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	if (fstat(fd, &statbuf) != 0)
	{
		close(fd);
		return (false);
	}
	close(fd);
	errno = ENOTDIR;
	return (S_ISDIR(statbuf.st_mode));
}

bool		path_is_valid(const char *path)
{
	t_array	*arr;
	void	*dir;
	int		level;

	level = 0;
	arr = ft_strsplit(path, '/');
	while ((dir = array_next(arr)) != NULL && level >= 0)
	{
		dir = *(char **)dir;
		if (ft_strcmp(dir, ".") == 0)
			continue ;
		if (ft_strcmp(dir, "..") == 0)
			level--;
		else
			level++;
	}
	array_free(arr);
	if (level < 0)
		errno = EACCES;
	return (level >= 0);
}
