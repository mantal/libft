/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 14:56:16 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/15 17:26:53 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_array			*arr;
	unsigned int	i;

	arr = array_new_c(2, FALSE);
	array_add(arr, 1);
	array_add(arr, 3);
	array_add(arr, 3);
	array_add(arr, 7);
	i = 0;
	while (i < arr->size)
		ft_printf("%d", arr->tab[i++]);
	array_free(&arr);
	return (0);
}
