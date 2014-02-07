/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:56:09 by dlancar           #+#    #+#             */
/*   Updated: 2014/02/07 17:12:49 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Clear the internal tab with 0 or NULL.
** If b is true, the free() function will be call on each cell.
** Original size and iterator are set to zero.
*/
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

