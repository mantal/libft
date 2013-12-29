/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 14:39:29 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/29 17:41:49 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/*
** Same function as printf but the content is stored in the string
** s instead of being printed.
** Return the number of characters that has been stored or a negative value
** if an error occured.
** DONT WORK
*/

int		ft_snprintf(char *s, size_t n, const char *format, ...)
{
	va_list			ap;
	unsigned int	res;
	char			*temp;

	res = 0;
	va_start(ap, format);
	while (*format && res < n)
	{
		if (*format == '%' && format++)
		{
			if (*format == 's')
			{
				temp = va_arg(ap, char*);
				ft_strcpy(s, va_arg(ap, char *));
				while (*s)
					s++;
				s--;
			}
		}
		else
			*s = *format;
		while ((s++ && format++ && res++) && 0);
	}
	*s = '\0';
	va_end(ap);
	return (0);
}
