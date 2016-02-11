/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:13:49 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/21 16:04:04 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC__H
# define MALLOC__H

# include <stddef.h>

# define SMALL_CHUNK  (SMALL_SIZE * 100)
# define MEDIUM_CHUNK (MEDIUM_SIZE * 100)

# define SMALL_SIZE  32
# define MEDIUM_SIZE 4096

typedef struct s_array	t_array;

typedef struct	s_mem
{
	char	*start;
	size_t	size;
}				t_mem;

typedef struct	s_chunk
{
	char	*start;
	size_t	size;
	t_array	*mem;
}				t_chunk;

extern t_array	*g_malloc_memory;

void			*malloc_(size_t size);
void			*realloc_(void *p, size_t size);
void			free_(void *p);

void			*alloc(size_t size);

void			malloc_dump_chunk(void);

void			*chunk_find(size_t size);

t_array			*new_(size_t size_type);

#endif
