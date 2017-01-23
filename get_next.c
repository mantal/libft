/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:51:23 by dlancar           #+#    #+#             */
/*   Updated: 2017/01/23 18:24:57 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftio.h"

#include <unistd.h>

static int	get_from_buffer(t_sarray *buffer, t_array *line, char c)
{
	int			i;

	i = buffer->it;
	while (buffer->it < GT_BUFF_SIZE
			&& buffer->arr[buffer->it] != c
			&& buffer->arr[buffer->it])
	{
		array_add(line, &buffer->arr[buffer->it]);
		buffer->arr[buffer->it] = '\0';
		buffer->it++;
	}
	if (buffer->it < GT_BUFF_SIZE && buffer->arr[buffer->it])
	{
		array_add(line, &buffer->arr[buffer->it]);
		buffer->arr[buffer->it] = '\0';
		buffer->it++;
	}
	return (buffer->it - i);
}

static int	get(int fd, char c, t_array *line)
{
	static t_sarray	buffer;
	int				r;
	int				rr;

	r = 0;
	while (true)
	{
		rr = get_from_buffer(&buffer, line, c);
		r += rr;
		if (rr == 0)
		{
			buffer.it = 0;
			rr = read(fd, &buffer.arr, GT_BUFF_SIZE);
			if (rr <= 0)
			{
				array_add(line, "\0");
				return (r);
			}
		}
		else if (*(char *)array_get(line, line->size - 1) == c)
		{
			array_set(line, "\0", line->size - 1);
			return (r);
		}
	}
}

int			get_next(const int fd, char **buff, char c)
{
	t_array	*line;
	int		res;

	line = array_new(sizeof(char), 0);
	res = get(fd, c, line);
	*buff = line->tab;
	return (res);
}
