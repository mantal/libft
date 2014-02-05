/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:27:21 by dlancar           #+#    #+#             */
/*   Updated: 2014/02/05 19:28:04 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_printf_fd(int fd, const char* str, ...)
{
	va_list		ap;

	va_start(ap, str);
	ft_vprintf_fd(fd, str, ap);
	va_end(ap);
}

