/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 12:59:28 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 17:05:04 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next.h"
#include "ftio.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int		ft_read(char **line, char **buf, char c, unsigned int max_s)
{
	unsigned int	size;

	if (!*buf || !**buf)
		return (-1);
	size = ft_strclen(*buf, c);
	size = (size > max_s) ? max_s : size;
	if (!ft_strchr(*buf, c))
	{
		if (!(*line = ft_strnjoinf(*line, *buf, size, 1)))
			return (-42);
		ft_memset(*buf, '\0', BUFF_SIZE);
		return (-1);
	}
	if (size == ft_strlen(*buf))
	{
		if (!(*line = ft_strnjoinf(*line, *buf, size, 1)))
			return (-42);
		ft_memset(*buf, '\0', BUFF_SIZE);
		return (0);
	}
	if (!(*line = ft_strnjoinf(*line, *buf, size, 1)))
		return (-42);
	ft_memmove(*buf, (*buf) + size + 1, max_s);
	ft_memset((*buf) + max_s - size, '\0', BUFF_SIZE - max_s);
	return (1);
}

static t_entry	*ft_new(const int fd)
{
	t_entry	*res;

	res = (t_entry*)ft_malloc(sizeof(t_entry));
	if (!res)
		return (NULL);
	res->next = NULL;
	res->fd = fd;
	res->buf = (char*)ft_malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(res->buf, sizeof(char) * (BUFF_SIZE + 1));
	if (!res->buf)
		return (NULL);
	return (res);
}

static t_entry	*ft_search(t_entry **list, const int fd)
{
	t_entry	*it;

	it = *list;
	if (*list)
	{
		while (it->next)
		{
			if (it->fd == fd)
				return (it);
			it = it->next;
		}
		if (it->fd == fd)
			return (it);
		it->next = ft_new(fd);
		return (it->next);
	}
	*list = ft_new(fd);
	return (*list);
}

static int		ft_free(t_entry *list, const int fd)
{
	t_entry		*temp;

	if (!list->next)
	{
		free(list->buf);
		free(list);
		return (1);
	}
	while (list->next)
	{
		if (list->next->fd == fd)
		{
			temp = list->next;
			list->next = list->next->next;
			free(temp->buf);
			free(temp);
		}
		list = list->next;
	}
	return (1);
}

int				ft_get_next(const int fd, char **line, char c)
{
	static t_entry	*list = NULL;
	t_entry			*entry;
	int				res;

	entry = ft_search(&list, fd);
	if (!entry || c == -1)
		return (c == -1 ? ft_free(list, fd) : -1);
	*line = ft_strdup("");
	if (!*line)
		return (-1);
	if ((res = ft_read(line, &(entry->buf), c, BUFF_SIZE)) > 0)
		return (1);
	while ((res = read(fd, entry->buf, BUFF_SIZE)) > 0)
	{
		entry->buf[BUFF_SIZE] = '\0';
		if (res < 0)
			return (-1);
		if ((res = ft_read(line, &(entry->buf), c, res) > 0))
			return (1);
		if (!res && !entry->buf)
			return (ft_free(list, fd));
		if (res < 0)
			return (-1);
	}
	return (res = (res > 0) ? 1 : 0);
}
