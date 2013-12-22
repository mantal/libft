/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:42:35 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/22 19:11:15 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Return a ptr to a mallocated t_array.
** Current flags : TRUE -> memory will always be initialised to nul.
** Return NULL if an error occured.
*/
t_array	*array_new(size_t capacity, size_t size_change, size_t size_type,
						t_flags flags)
{
	t_array	*res;

	res = (t_array*)malloc(sizeof(t_array));
	if (!res)
		return (ft_error(flags));
	res->size = 0;
	res->capacity = capacity;
	res->size_change = size_change;
	res->size_type = size_type;
	res->flags = flags;
	res->tab = (char*)malloc(size_change * capacity);
	if (!res->tab)
		return (ft_error(flags));
	if (flags & 1)
		ft_bzero(res->tab, size_change * capacity);
	return (res);
}

t_array	*array_add(t_array *arr, void* value)
{
	if (arr->capacity == arr->size)
		array_resize(arr, BUFF_SIZE);
	if (arr->flags & PTR)
		ft_memcpy((arr->tab + (arr->size * arr->size_type)),
				&value, arr->size_type);
	else
		ft_memcpy((arr->tab + (arr->size * arr->size_type)),
				value, arr->size_type);
	arr->size++;
	return (arr);
}

t_array	*array_insert(t_array *arr, void* value, unsigned int index)
{
	while (arr->capacity < index)
		array_resize(arr, FALSE);
	if (index + 1 >= arr->size)
		arr->size = index;
	if (arr->flags & PTR)
		ft_memcpy((arr->tab + (index * arr->size_type)), &value,
					arr->size_type);
	else
		ft_memcpy((arr->tab + (index * arr->size_type)), value, arr->size_type);
	return (arr);
}

/*
** Increase the capacity of arr.
** If auto_resize = TRUE, the new capacity will be calculated to feet a
** load factor of LOAD_FACTOR instead of be capacity + size_change.
** Return NULL if an error occured.
** TODO : Implemente auto resize.
*/
t_array	*array_resize(t_array *arr, t_bool auto_resize)
{
	void	*tab;

	(void)auto_resize;
	arr->capacity += arr->size_change;
	tab = (char*)malloc(arr->size_type * arr->capacity);
	if (!tab)
		return (ft_error(arr->flags));
	if (arr->flags & 1)
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

