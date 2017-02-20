/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:56:09 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/20 17:18:18 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_array		*array_clear(t_array *arr)
{
	if (arr->flags & ARR_FREE_ON_CLEAR)
		array_free_content(arr);
	ft_bzero(arr->tab, arr->size * arr->size_type);
	arr->size = 0;
	arr->it = 0;
	return (arr);
}

t_array		*array_init(t_array *arr, size_t size_type, t_flags flags)
{
	arr->capacity = 1000;
	arr->capacity_change = 0;
	arr->size = 0;
	arr->size_type = size_type;
	arr->it = 0;
	arr->flags = flags;
	arr->tab = ft_malloc(arr->size_type * arr->capacity);
	if (flags & 1)
		ft_bzero(arr->tab, arr->size_type * arr->capacity);
	return (arr);
}

void		*array_prev(t_array *arr)
{
	if (arr->it > 0)
	{
		arr->it--;
		return (arr->tab + (arr->size_type * (arr->it)));
	}
	return (NULL);
}

t_array		*array_free_content(t_array *arr)
{
	void	*tmp;

	arr->it = 0;
	while (arr->it < arr->size)
	{
		tmp = array_get(arr, arr->it);
		if (tmp)
			free(*(char **)tmp);
		arr->it++;
	}
	return (arr);
}
