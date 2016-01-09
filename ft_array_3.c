/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:56:09 by dlancar           #+#    #+#             */
/*   Updated: 2014/05/22 16:53:40 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_array		*array_clear(t_array *arr, t_bool b)
{
	arr->it = 0;
	while (arr->it < arr->size)
	{
		if (b)
			free(array_get(arr, arr->it));
		arr->it++;
	}
	ft_bzero(arr->tab, arr->size * arr->size_type);
	arr->size = 0;
	arr->it = 0;
	return (arr);
}

t_array		*array_init(t_array *arr, size_t capacity, size_t size_change,
							size_t size_type, t_flags flags)
{
	arr->size = 0;
	arr->capacity = capacity;
	arr->size_change = size_change;
	arr->size_type = size_type;
	arr->it = 0;
	arr->flags = flags;
	arr->tab = (char *)ft_malloc(size_change * capacity);
	if (flags & TRUE)
		ft_bzero(arr->tab, size_change * capacity);
	return (arr);
}

t_array		*array_new_s(size_t size_type)
{
	return (array_new(1000, 1000, size_type, 0));
}
