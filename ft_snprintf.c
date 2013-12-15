/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 14:39:29 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/01 16:23:04 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/*
** Same function as printf but the content is stored in the string
** s instead of being printed.
** Flags : %c (char), %s (string), %d (int), %f (double, not implemented yet).
** Return the number of characters that has been stored or a negative value
** if an error occured.
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
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				*s = '%';
			else if (*format == 'c')
				*s = va_arg(ap, int);
			else if (*format == 's')
			{
				temp = va_arg(ap, char*);
				ft_strcpy(s, temp);
				while (*s)
					s++;
				s--;
			}
			else if (*format == 'd')
			{
				temp = ft_itoa(va_arg(ap, int));
				ft_strcpy(s, temp);
				s += sizeof(temp);
				s--;
				free(temp);
			}
			else if (*format == 'f')
				(void)va_arg(ap, double);
		}
		else
			*s = *format;
		s++;
		format++;
		res++;
	}
	*s = '\0';
	va_end(ap);
	return (0);
}
