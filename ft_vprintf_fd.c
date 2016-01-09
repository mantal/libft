/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:28:46 by dlancar           #+#    #+#             */
/*   Updated: 2015/12/08 14:38:36 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_vprintf_fd(int fd, const char *str, va_list ap)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				ft_putchar_fd('%', fd);
			else if (*str == 'c')
				ft_putchar_fd(va_arg(ap, int), fd);
			else if (*str == 's')
				ft_putstr_fd(va_arg(ap, char*), fd);
			else if (*str == 'd')
				ft_putnbr_fd(va_arg(ap, int), fd);
			else if (*str == 'f')
				ft_putdouble_fd(va_arg(ap, double), fd);
			else if (*str == 'x' || *str == 'X' || *str == 'p')
				ft_puthex_fd(va_arg(ap, unsigned long), fd);
		}
		else
			ft_putchar_fd(*str, fd);
		str++;
	}
}
