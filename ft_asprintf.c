/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 14:39:29 by dlancar           #+#    #+#             */
/*   Updated: 2015/04/09 17:05:30 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

static void		add_string(t_array *arr, const char *s)
{
	while (*s)
	{
		array_add(arr, &s);
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

int				ft_asprintf(char **s, const char *format, ...)
{
	va_list		ap;
	t_array		*res;
	int			i;

	if (!(res = array_new(64, 64, sizeof(char), 0)))
		return (-1);
	(va_start(ap, format), i = -1);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[++i] == '%')
				array_add(res, "%");
			else if (format[i] == 'c')
				array_add(res, (int[]){va_arg(ap, int)});
			else if (format[i] == 's')
				add_string(res, va_arg(ap, char *));
			else if (format[i] == 'd')
				add_int(res, va_arg(ap, int));
		}
		else
			array_add(res, &((char *)format)[i]);
	}
	(va_end(ap), *s = res->tab, ft_memset(&i, res->size, sizeof(i)), free(res));
	return (i);
}
