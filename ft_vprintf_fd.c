/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:28:46 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/19 15:33:45 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include <stdarg.h>

void	ft_vprintf_fd(int fd, const char *str, va_list ap)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				ft_putchar_fd(fd, '%');
			else if (*str == 'c')
				ft_putchar_fd(fd, va_arg(ap, int));
			else if (*str == 's')
				ft_putstr_fd(fd, va_arg(ap, char*));
			else if (*str == 'd' || *str == 'i')
				ft_putint_fd(fd, va_arg(ap, int));
			else if (*str == 'u')
				ft_putubase_fd(fd, va_arg(ap, unsigned long), 10);
			else if (*str == 'f')
				ft_putdouble_fd(fd, va_arg(ap, double));
			else if (*str == 'x' || *str == 'X' || *str == 'p')
				ft_putubase_fd(fd, va_arg(ap, unsigned long), 16);
		}
		else
			ft_putchar_fd(fd, *str);
		str++;
	}
}
