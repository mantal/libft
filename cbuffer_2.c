/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:08:02 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 14:09:35 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbuffer.h"
#include <stdlib.h>

char		cbuffer_cnext(t_cbuffer *buffer)
{
	buffer->start = (buffer->start + 1) % buffer->capacity;
	return (cbuffer_next(buffer));
}

void		cbuffer_free(t_cbuffer **buffer)
{
	free((*buffer)->arr);
	free(*buffer);
	*buffer = NULL;
}

t_cbuffer	*cbuffer_clear(t_cbuffer *buffer)
{
	buffer->start = 0;
	buffer->end = 0;
	buffer->it = buffer->start;
	buffer->write = FALSE;
	return (buffer);
}

char		cbuffer_get(const t_cbuffer *buffer)
{
	return (buffer->arr[buffer->it]);
}

t_bool		cbuffer_it_is_last(const t_cbuffer *buffer)
{
	return (buffer->it == buffer->end && !buffer->write);
}
