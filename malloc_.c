/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:56:43 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/21 14:45:47 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "malloc_.h"

#include <unistd.h>
#include <sys/mman.h>

void	*alloc(size_t size)
{
	unsigned long	*res;

	size += sizeof(void *);
	size += getpagesize() - (size % getpagesize());
	res = mmap(NULL, size,
			PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANON, -1, 0);
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
		g_malloc_memory = array_new_s(sizeof(t_chunk));
	return (chunk_find(size));
}
