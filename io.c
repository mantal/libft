/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:35:16 by dlancar           #+#    #+#             */
/*   Updated: 2015/12/11 15:44:36 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "error.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_open(const char *path, int oflag, ...)
{
	va_list	ap;
	int		r;

	va_start(ap, oflag);
	r = open(path, oflag, ap);
	if (r < 0)
	{
		ft_error();
		return (r);
	}
	return (r);
}

int		ft_close(int fd)
{
	if (close(fd) < 0)
	{
		ft_error();
		return (-1);
	}
	return (0);
}
