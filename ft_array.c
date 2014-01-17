/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:42:35 by dlancar           #+#    #+#             */
/*   Updated: 2014/01/17 20:40:21 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include <stdlib.h>

/*
** Return a pointer to a mallocated t_array.
** capacity is the inital capacity of the array.
** size_type is the number of byte of the data that the array will
** contain (usually get with sizeof()).
** If nul is passed to capacity, size_change or size_type, the behavior is
** undefined.
** Current flags : TRUE      -> memory will be initialised to nul.
**                 PTR       -> enable the array to store pointer.
**                 LOOP      -> make array_next loop (don't work).
** Return NULL if an error occured.
*/
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
	res->tab = (char *)ft_malloc(size_change * capacity);
	if (!res->tab)
		return (NULL);
	if (flags & TRUE)
		ft_bzero(res->tab, size_change * capacity);
	return (res);
}

t_array	*array_add(t_array *arr, void* value)
{
	if (arr->capacity == arr->size)
		array_resize(arr, FALSE);
	if (arr->flags & PTR)
		ft_memcpy((arr->tab + (arr->size * arr->size_type)),
				&value, arr->size_type);
	else
		ft_memcpy((arr->tab + (arr->size * arr->size_type)),
				value, arr->size_type);
	arr->size++;
	return (arr);
}

/*
** Insert an element at index.
*/
t_array	*array_insert(t_array *arr, void* value, unsigned int index)
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
		array_resize(arr, FALSE);
	return (arr);
}

/*
** Increase the capacity of arr.
** If auto_resize = TRUE, the new capacity will be calculated to feet a
** load factor of LOAD_FACTOR.
** Else, the new capacity will be increase by size_change.
** Return NULL if an error occured.
** TODO : Implemente auto resize.
*/
t_array	*array_resize(t_array *arr, t_bool auto_resize)
{
	void	*tab;

	(void)auto_resize;
	arr->capacity += arr->size_change;
	tab = (char *)ft_malloc(arr->size_type * arr->capacity);
	if (!tab)
		return (NULL);
	if (arr->flags & TRUE)
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

