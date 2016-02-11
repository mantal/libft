/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:56:43 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/21 16:02:32 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** MAP_ANONYMOUS is a gnu extention
*/
#define _GNU_SOURCE

#include "error.h"
#include "malloc_.h"

#include <unistd.h>
#include <sys/mman.h>

t_array	*new_(size_t size_type)
{
	t_array	*res;

	res = alloc(sizeof(t_array));
	if (!res)
	{
		ft_error();
		return (NULL);
	}
	res->size = 0;
	res->capacity = 1024;
	res->size_change = 1024;
	res->it = 0;
	res->flags = 0;
	res->tab = alloc(res->capacity * size_type);
	if (!res->tab)
	{
		ft_error();
		return (NULL);
	}
	res->size_type = size_type;
	return (res);
}

void	*alloc(size_t size)
{
	unsigned long	*res;

	size += sizeof(void *);
	size += getpagesize() - (size % getpagesize());
	res = mmap(NULL, size,
			PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (res == MAP_FAILED)
	{
		ft_error();
		return (NULL);
	}
	res[0] = size;
	return (res + sizeof(void *));
}

void	*malloc_(size_t size)
{
	if (size == 0)
		return (NULL);
	if (g_malloc_memory == NULL)
		g_malloc_memory = new_(sizeof(t_chunk));
	return (chunk_find(size));
}
