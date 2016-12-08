/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:56:49 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/07 17:16:29 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "malloc_.h"
#include <errno.h>
#include <stddef.h>

#define GMEM (g_malloc_memory)

static t_chunk	*find__(void *p, size_t *pos)
{
	unsigned int	i;
	unsigned int	j;
	t_chunk			*c;
	t_mem			*m;

	i = 0;
	g_malloc_memory = GMEM ? GMEM : array_new(sizeof(t_chunk), 0);
	while (i < g_malloc_memory->size)
	{
		c = (t_chunk *)array_get(g_malloc_memory, i);
		if (((char *)p < c->start || (char *)p > c->start + c->size) && ++i)
			continue ;
		j = 0;
		while (j < c->mem->size)
		{
			m = (t_mem *)array_get(c->mem, j);
			if (((char *)p < m->start || (char *)p > m->start + m->size) && ++j)
				continue ;
			array_remove(c->mem, c->mem->it - 1);
			*pos = j;
			return (c);
		}
		i++;
	}
	return (NULL);
}

static t_bool	can_realloc(t_chunk *c, t_mem *m, size_t pos, size_t size)
{
	t_mem	*n;

	if (m->size >= size)
		return (true);
	if (c->start + c->size < m->start + size)
		return (false);
	if (c->mem->size == pos + 1)
		return (true);
	n = (t_mem *)array_get(c->mem, pos + 1);
	return (n->start < m->start + size);
}

void			*realloc_(void *p, size_t size)
{
	void	*res;
	t_chunk	*c;
	t_mem	*m;
	size_t	pos;

	if (!p || !size)
	{
		free_(p);
		return (malloc_(size));
	}
	c = find__(p, &pos);
	if (!c)
	{
		errno = EFAULT;
		ft_error();
		return (NULL);
	}
	m = (t_mem *)array_get(c->mem, pos);
	if (can_realloc(c, m, pos, size) && (m->size = size))
		return (m->start);
	if (!(res = malloc_(size)))
		return (NULL);
	ft_memcpy(res, m->start, m->size);
	free_(m->start);
	return (res);
}
