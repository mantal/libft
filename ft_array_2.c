/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 17:16:54 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/08 14:54:14 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include <assert.h>

t_array	*array_set(t_array *arr, void *value, size_t index)
{
	if (arr->flags & PTR)
		ft_memcpy((arr->tab + (index * arr->size_type)), &value,
					arr->size_type);
	else
		ft_memcpy((arr->tab + (index * arr->size_type)), value, arr->size_type);
	return (arr);
}

void	*array_get(const t_array *arr, size_t index)
{
	assert(index < arr->size);
	return (arr->tab + (arr->size_type * index));
}

void	*array_next(t_array *arr)
{
	if (arr->it < arr->size)
	{
		arr->it++;
		return (arr->tab + (arr->size_type * (arr->it - 1)));
	}
	return (NULL);
}

t_array	*array_cpy(const t_array *src)
{
	t_array	*res;

	res = array_new(src->size_type, src->flags);
	if (!res)
		return (NULL);
	res->size = src->size;
	ft_memcpy(res->tab, src->tab, src->size * src->size_type);
	return (res);
}

t_array	*array_remove(t_array *arr, size_t index)
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
