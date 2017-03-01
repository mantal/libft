/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 19:04:53 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/28 11:55:47 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterror.h"
#include "ftio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

t_flags	g_error_flags = ERR_DISP_AUTO | ERR_EXIT;

int			ft_error(void)
{
	if (g_error_flags & ERR_DISP_PERROR)
		perror(NULL);
	else if (g_error_flags & ERR_DISP_AUTO)
		ft_derror(STDOUT_FILENO, NULL);
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
	if (msg == NULL)
		ft_printf_fd(fd, "Error : %s\n", g_error_flags & ERR_DISP_AUTO ?
						ft_strerror(errno) : strerror(errno));
	else
		ft_vprintf_fd(fd, msg, ap);
	va_end(ap);
	if (g_error_flags & ERR_EXIT)
		exit(EXIT_FAILURE);
	if (g_error_flags & ERR_FORCE_CRASH)
		__builtin_trap();
	return (0);
}

const char	*ft_strerror(int errnum)
{
	extern const char	*const sys_errlist[];

	if (errno > sys_nerr)
		return (EINVAL);
	return (sys_errlist[errnum]);
}
