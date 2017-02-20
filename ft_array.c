/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:42:35 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/20 17:14:30 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>

t_array	*array_new(size_t size_type, t_flags flags)
{
	t_array	*res;

	res = ft_malloc(sizeof(t_array));
	if (!res)
		return (NULL);
	res->size = 0;
	res->capacity = 100;
	res->capacity_change = 0;
	res->size_type = size_type;
	res->it = 0;
	res->flags = flags;
	res->tab = ft_malloc(size_type * res->capacity);
	if (!res->tab)
		return (NULL);
	return (res);
}

t_array	*array_add(t_array *arr, const void *value)
{
	if (arr->capacity == arr->size)
		array_resize(arr);
	ft_memcpy((arr->tab + (arr->size * arr->size_type)),
			value, arr->size_type);
	arr->size++;
	return (arr);
}

t_array	*array_insert(t_array *arr, void *value, size_t index)
{
	void	*temp;

	assert(index < arr->size);
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
		array_resize(arr);
	return (arr);
}

t_array	*array_resize(t_array *arr)
{
	void	*iarr;

	arr->capacity = arr->capacity_change != 0 ?
		arr->capacity + arr->capacity_change : arr->capacity * 2;
	iarr = ft_malloc(arr->size_type * arr->capacity);
	if (!iarr)
		return (NULL);
	ft_memcpy(iarr, arr->tab, arr->size * arr->size_type);
	free(arr->tab);
	arr->tab = iarr;
	return (arr);
}

void	array_free(t_array *arr)
{
	if (arr->flags & ARR_FREE_CONTENT)
		array_free_content(arr);
	free(arr->tab);
	free(arr);
}
