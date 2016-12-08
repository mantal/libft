/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:56:09 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/07 18:16:34 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_array		*array_clear(t_array *arr)
{
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
