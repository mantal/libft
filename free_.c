/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:56:34 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/07 17:16:48 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "malloc_.h"
#include <sys/mman.h>

static void		free__(void *p)
{
	unsigned long	*pp;

	if (p == NULL)
		return ;
	pp = ((unsigned long *)p) - sizeof(unsigned long *);
	munmap(pp, pp[0]);
}

#define GMEM (g_malloc_memory)

void			free_(void *p)
{
	t_chunk		*c;
	t_mem		*m;

	if (!p)
		return ;
	g_malloc_memory = g_malloc_memory ? GMEM : array_new(sizeof(t_chunk), 0);
	while ((c = (t_chunk *)array_next(g_malloc_memory)))
	{
		if ((char *)p < c->start || (char *)p > c->start + c->size)
			continue ;
		while ((m = (t_mem *)array_next(c->mem)))
		{
			if ((char *)p < m->start || (char *)p > m->start + m->size)
				continue ;
			array_remove(c->mem, c->mem->it - 1);
			c->mem->it = 0;
			g_malloc_memory->it = 0;
			if (c->mem->size == 0)
				array_remove(g_malloc_memory, g_malloc_memory->it);
			return ;
		}
		c->mem->it = 0;
	}
	g_malloc_memory->it = 0;
	free__(p);
}
