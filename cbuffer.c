/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 11:20:47 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 14:09:27 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbuffer.h"
#include <stdlib.h>

t_cbuffer	*cbuffer_new(t_uint capacity)
{
	t_cbuffer	*res;

	res = ft_malloc(sizeof(t_cbuffer));
	if (!res)
		return (NULL);
	res->arr = ft_malloc(capacity + 1);
	if (!res->arr)
		return (NULL);
	ft_bzero(res->arr, capacity + 1);
	res->capacity = capacity;
	res->start = 0;
	res->end = 0;
	res->it = res->start;
	res->write = FALSE;
	return (res);
}

t_cbuffer	*cbuffer_add(t_cbuffer *buffer, const char *data, t_uint data_size)
{
	t_uint		overflow;

	buffer->write = TRUE;
	if (buffer->end + data_size <= buffer->capacity)
	{
		ft_memcpy(buffer->arr + buffer->end, data, data_size);
		buffer->end += data_size;
		return (buffer);
	}
	ft_memcpy(buffer->arr + buffer->end, data, buffer->capacity - buffer->end);
	overflow = data_size - (buffer->capacity - buffer->end);
	ft_memcpy(buffer->arr,
			data + buffer->capacity - buffer->end,
			overflow);
	buffer->start = (buffer->start + overflow) % buffer->capacity;
	buffer->it = buffer->start;
	buffer->end = overflow;
	return (buffer);
}

t_bool		cbuffer_has_next(const t_cbuffer *buffer)
{
	return ((buffer->it + 1) % buffer->capacity != buffer->end
			|| buffer->write);
}

char		cbuffer_get_next(const t_cbuffer *buffer)
{
	return (buffer->arr[(buffer->it + 1) % buffer->capacity]);
}

char		cbuffer_next(t_cbuffer *buffer)
{
	char	res;

	res = buffer->arr[buffer->it];
	buffer->write = FALSE;
	buffer->it = (buffer->it + 1) % buffer->capacity;
	return (res);
}
