/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:42:35 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/18 16:48:13 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include <stdlib.h>

t_array	*array_new(size_t capacity, size_t size_change, size_t size_type,
						t_flags flags)
{
	t_array	*res;

	res = (t_array *)ft_malloc(sizeof(t_array));
	if (!res)
		return (NULL);
	res->size = 0;
	res->capacity = capacity;
	res->size_change = size_change;
	res->size_type = size_type;
	res->it = 0;
	res->flags = flags;
	res->tab = ft_malloc(size_type * capacity);
	if (!res->tab)
		return (NULL);
	if (flags & 1)
		ft_bzero(res->tab, size_change * capacity);
	return (res);
}

t_array	*array_add(t_array *arr, void *value)
{
	if (arr->capacity == arr->size)
		array_resize(arr, false);
	if (arr->flags & PTR)
		ft_memcpy((arr->tab + (arr->size * arr->size_type)),
				&value, arr->size_type);
	else
		ft_memcpy((arr->tab + (arr->size * arr->size_type)),
				value, arr->size_type);
	arr->size++;
	return (arr);
}

t_array	*array_insert(t_array *arr, void *value, unsigned int index)
{
	void	*temp;

	temp = ft_malloc((arr->size - index) * arr->size_type);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, arr->tab + arr->size_type * index,
				(arr->size - index) * arr->size_type);
	ft_memcpy(arr->tab + arr->size_type * (index + 1), temp,
				(arr->size - index) * arr->size_type);
	array_set(arr, value, index);
	arr->size++;
	if (arr->size == arr->capacity)
		array_resize(arr, false);
	return (arr);
}

t_array	*array_resize(t_array *arr, t_bool auto_resize)
{
	void	*tab;

	(void)auto_resize;
	arr->capacity += arr->size_change;
	tab = (char *)ft_malloc(arr->size_type * arr->capacity);
	if (!tab)
		return (NULL);
	if (arr->flags & 0)
		ft_bzero(tab, arr->size_type * arr->capacity);
	ft_memcpy(tab, arr->tab, arr->size * arr->size_type);
	free(arr->tab);
	arr->tab = tab;
	return (arr);
}

void	array_free(t_array **arr)
{
	free((*arr)->tab);
	free(*arr);
	*arr = NULL;
}
