/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 11:19:19 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/08 15:19:46 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBUFFER_H
# define CBUFFER_H

# include "libft.h"

# define CBUFFER_IS_EMPTY(buffer) (buffer->start==buffer->end && buffer->write)

typedef struct	s_cbuffer
{
	char			*arr;
	unsigned int	start;
	unsigned int	end;
	unsigned int	capacity;
	unsigned int	it;
	bool			write;
}				t_cbuffer;

t_cbuffer		*cbuffer_new(unsigned int capacity);
t_cbuffer		*cbuffer_add(t_cbuffer *buffer, const char *data,
				unsigned int size);
t_cbuffer		*cbuffer_clear(t_cbuffer *buffer);
void			cbuffer_free(t_cbuffer **buffer);

bool			cbuffer_has_next(const t_cbuffer *buffer);
bool			cbuffer_it_is_last(const t_cbuffer *buffer);
char			cbuffer_cnext(t_cbuffer *buffer);
char			cbuffer_next(t_cbuffer *buffer);
char			cbuffer_get_next(const t_cbuffer *buffer);
char			cbuffer_get(const t_cbuffer *buffer);

#endif
