/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 18:07:57 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/08 15:32:33 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterror.h"
#include "libft.h"
#include "malloc_.h"
#include <stdlib.h>

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
