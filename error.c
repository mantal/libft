/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 19:04:53 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/23 12:20:44 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterror.h"
#include "ftio.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

t_flags	g_error_flags = ERR_DISP_AUTO | ERR_EXIT;

int			ft_error(void)
{
	if (g_error_flags & ERR_DISP_PERROR)
		perror(NULL);
	else if (g_error_flags & ERR_DISP_AUTO)
		ft_perror();
	if (g_error_flags & ERR_EXIT)
		exit(EXIT_FAILURE);
	if (g_error_flags & ERR_FORCE_CRASH)
		__builtin_trap();
	return (0);
}

int			ft_error_msg(const char *msg, ...)
{
	va_list	ap;

	va_start(ap, msg);
	ft_vprintf(msg, ap);
	va_end(ap);
	if (g_error_flags & ERR_EXIT)
		exit(EXIT_FAILURE);
	if (g_error_flags & ERR_FORCE_CRASH)
		__builtin_trap();
	return (0);
}

int			ft_derror(int fd, const char *msg, ...)
{
	va_list	ap;

	va_start(ap, msg);
	ft_vprintf_fd(fd, msg == NULL ? ft_strerror(errno) : msg, ap);
	va_end(ap);
	if (g_error_flags & ERR_EXIT)
		exit(EXIT_FAILURE);
	if (g_error_flags & ERR_FORCE_CRASH)
		__builtin_trap();
	return (0);
}

int			ft_perror(void)
{
	extern const char	*const sys_errlist[];

	if (errno > 106)
		errno = 0;
	ft_printf_fd(STDERR_FILENO, "Error : %s.\n", sys_errlist[errno]);
	return (0);
}

const char	*ft_strerror(int errnum)
{
	return (sys_errlist[errnum]);
}
