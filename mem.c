/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:40:29 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/08 15:02:27 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include "libft.h"
#include "malloc_.h"

t_array	*g_malloc_memory = NULL;

static void		*mem_find(t_chunk *c, size_t size)
{
	unsigned int	i;
	t_mem			m;

	i = 0;
	if (c->mem->size == 0)
		return (c->start);
	while (i < c->mem->size)
	{
		m = *(t_mem *)array_get(c->mem, i);
		if (m.start + m.size + size >= c->start + c->size)
			return (NULL);
		if (i == c->mem->size - 1)
			return (m.start + m.size);
		if ((*(t_mem*)array_get(c->mem, i + 1)).start > m.start + m.size + size)
			return (m.start + m.size);
		i++;
	}
	return (NULL);
}

static t_chunk	*chunk_create(size_t size)
{
	t_chunk	c;

	if (size > MEDIUM_SIZE)
	{
		c.start = alloc(size);
		c.size = size;
	}
	else if (size > SMALL_SIZE)
	{
		c.start = alloc(MEDIUM_CHUNK);
		c.size = MEDIUM_CHUNK;
	}
	else
	{
		c.start = alloc(SMALL_CHUNK);
		c.size = SMALL_CHUNK;
	}
	c.mem = new_(sizeof(t_mem));
	array_add(g_malloc_memory, &c);
	return ((t_chunk *)array_get(g_malloc_memory, g_malloc_memory->size - 1));
}

#define M(n) (n == SMALL_CHUNK ? "TINY" : n == MEDIUM_CHUNK ? "SMALL" : "LARGE")

void			malloc_dump_chunk(void)
{
	t_chunk			c;
	t_mem			m;
	unsigned int	i;

	if (!g_malloc_memory)
		return ;
	i = 0;
	while (g_malloc_memory->it < g_malloc_memory->size)
	{
		c = *(t_chunk *)array_get(g_malloc_memory, g_malloc_memory->it);
		ft_printf("%s: %p\n", M(c.size), c.start);
		while (c.mem->it < c.mem->size)
		{
			m = *(t_mem *)array_get(c.mem, c.mem->it);
			ft_printf("%p - %p : %u octets\n", m.start,
					m.start + m.size, m.size);
			c.mem->it++;
			i += m.size;
		}
		c.mem->it = 0;
		g_malloc_memory->it++;
	}
	g_malloc_memory->it = 0;
	ft_printf("Total : %u octets\n", i);
}

void			*chunk_find(size_t size)
{
	unsigned int	i;
	t_mem			m;
	t_chunk			c;

	m.size = size;
	i = -1;
	while (++i < g_malloc_memory->size)
	{
		c = *(t_chunk *)array_get(g_malloc_memory, i);
		if ((size <= SMALL_SIZE && c.size != SMALL_CHUNK)
		|| (size > SMALL_SIZE && size <= MEDIUM_SIZE && c.size != MEDIUM_CHUNK)
		|| (size > MEDIUM_SIZE && c.size >= MEDIUM_CHUNK))
			continue ;
		m.start = mem_find(&c, size);
		if (m.start)
		{
			array_add(c.mem, &m);
			return (m.start);
		}
	}
	c = *chunk_create(size);
	m.start = c.start;
	array_add(c.mem, &m);
	return (m.start);
}
