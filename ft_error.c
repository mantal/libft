/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 19:04:53 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 17:05:30 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ftio.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

t_flags		error_opt(t_flags flags)
{
	static t_flags	err_flags = ERR_DISP_AUTO | ERR_FATAL;

	if (flags == ERR_GET)
		return (err_flags);
	err_flags = flags;
	return (err_flags);
}

int			ft_error(void)
{
	t_flags		flags;

	flags = error_opt(ERR_GET);
	if (flags & ERR_DISP_PERROR)
		perror(NULL);
	else if (flags & ERR_DISP_AUTO)
		ft_perror();
	if (flags & ERR_FATAL)
		exit(EXIT_FAILURE);
	return (0);
}

int			ft_error_msg(const char *msg, ...)
{
	va_list		ap;
	t_flags		flags;

	flags = error_opt(ERR_GET);
	va_start(ap, msg);
	ft_vprintf(msg, ap);
	va_end(ap);
	if (flags & ERR_FATAL)
		exit(EXIT_FAILURE);
	return (0);
}

int			ft_perror(void)
{
	if (errno > 106)
		errno = 0;
	ft_printf_fd(STDERR, "Error : %s.\n", sys_errlist[errno]);
	return (0);
}
