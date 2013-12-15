/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:28:48 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/15 17:28:36 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
** These function allow the use of dynamic int array.
*/

/*
** Return a ptr to a mallocated t_array.
** Capacity is set to capacity. If set is TRUE, the array is also set to nul.
** Return NULL if an error occured.
*/
t_array	*array_new_c(size_t capacity, t_bool set)
{
	t_array	*res;

	res = (t_array*)malloc(sizeof(t_array));
	if (!res)
		return (NULL);
	res->size = 0;
	res->capacity = capacity;
	res->tab = (int*)malloc(sizeof(int) * capacity);
	if (!res->tab)
		return (NULL);
	if (set)
		ft_bzero(res->tab, capacity);
	return (res);
}

/*
** Similar to array_create_c(BUFF_SIZE);
*/
t_array	*array_new()
{
	return (array_new_c(BUFF_SIZE, FALSE));
}

t_array	*array_add(t_array *arr, int value)
{
	if (arr->capacity == arr->size)
	{
		if (!array_resize(arr, BUFF_SIZE))
			return (NULL);
	}
	arr->tab[arr->size] = value;
	arr->size++;
	return (arr);	
}

/*
** Increase the size of arr by add.
** If add = 0, the new size will be calculated to feet a load factor of
** LOAD_FACTOR.
** Return NULL if an error occured.
** TODO : Implemente auto resize.
*/
t_array	*array_resize(t_array *arr, size_t add)
{
	int		*tab;

	arr->capacity += add;
	tab = (int*)malloc(sizeof(int) * arr->capacity);
	if (!tab)
		return (NULL);
	ft_memcpy(tab, arr->tab, arr->capacity);
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

