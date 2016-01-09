/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 14:39:29 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 14:10:35 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

#include "ft_asprintf.c.part"

static void		add_string(t_array *arr, const char *s)
{
	while (*s)
	{
		array_add(arr, (char *)s);
		s++;
	}
}

static void		add_int(t_array *arr, int n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_itoa(n);
	while (temp[i])
	{
		array_add(arr, &temp[i]);
		i++;
	}
	free(temp);
}
