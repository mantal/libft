/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 18:07:57 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/21 14:48:43 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "malloc_.h"
#include <stdlib.h>

/*
** if g_malloc_use == true use system malloc, else use our.
*/
bool	g_malloc_use = true;

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = g_malloc_use ? malloc(size) : malloc_(size);
	if (!ptr)
	{
		ft_error();
		return (NULL);
	}
	return (ptr);
}
