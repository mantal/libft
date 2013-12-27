/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:39:58 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/27 17:41:57 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_printf(const char* str, ...)
{
	va_list		ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				ft_putchar('%');
			else if (*str == 'c')
				ft_putchar(va_arg(ap, int));
			else if (*str == 's')
				ft_putstr(va_arg(ap, char*));
			else if (*str == 'd')
				ft_putnbr(va_arg(ap, int));
			else if (*str == 'f')
				ft_putdouble(va_arg(ap, double));
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(ap);
}
