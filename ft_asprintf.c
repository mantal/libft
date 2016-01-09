/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 14:39:29 by dlancar           #+#    #+#             */
/*   Updated: 2015/04/09 11:48:46 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int		ft_asprintf(char **s, const char *format, ...)
{
	va_list		ap;
	t_array		*res;
	int			i;
	int			j;
	char		*temp;

	res = array_new(64, 64, sizeof(char), 0);
	if (!res)
		return (-1);
	va_start(ap, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				array_add(res, "%");
			else if (format[i] == 'c')
				array_add(res, (int[]){va_arg(ap, int)});
			else if (format[i] == 's')
			{
				temp = va_arg(ap, char *);
				while (*temp)
					array_add(res, temp++);
			}
			else if (format[i] == 'd')
			{
				j = -1;
				temp = ft_itoa(va_arg(ap, int));
				while (temp[++j])
					array_add(res, &temp[j]);
				free(temp);
			}
		}
		else
			array_add(res, &((char *)format)[i]);
	}
	va_end(ap);
	*s = res->tab;
	i = res->size;
	free(res);
	return (i);
}
