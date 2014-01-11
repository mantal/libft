/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 17:16:54 by dlancar           #+#    #+#             */
/*   Updated: 2014/01/11 17:46:42 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*array_get(t_array *arr, unsigned int index)
{
	return (arr->tab + (arr->size_type * index));
}

void	*array_next(t_array *arr)
{
	if (arr->flags & LOOP && arr->it >= arr->size)
		arr->it = 0;
	if (arr->it < arr->size)
	{
		arr->it++;
		return (arr->tab + (arr->size_type * (arr->it - 1)));
	}
	return (NULL);
}

/*
** Return a new t_array which is a copy of src. Iterator is not copied.
** Return NULL if an error occure.
*/
t_array	*array_cpy(const t_array *src)
{
	t_array	*res;

	res = array_new(src->capacity, src->size_change, src->size_type,
					src->flags);
	if (!res)
		return (NULL);
	res->err_func = src->err_func;
	res->size = src->size;
	ft_memcpy(res->tab, src->tab, src->size * src->size_change);
	return (res);
}

/*
** Remove the content at index.
*/
t_array	*array_remove(t_array *arr, unsigned int index)
{
	unsigned int	i;

	arr->size--;
	i = index;
	while (i < arr->size)
	{
		ft_memcpy(arr->tab + i * arr->size_type, arr->tab + (i + 1)
				* arr->size_type, arr->size_type);
		i++;
	}
	return (arr);
}

