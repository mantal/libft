/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:21:57 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/01 17:40:47 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include "term.h"
#include <stdarg.h>

int		g_ftio_logsfd = STDERR_FILENO;
int		g_ftio_verbose_level = FTIO_INFO;

bool	debug(const char *s, ...)
{
	va_list	ap;

	if (g_ftio_verbose_level < FTIO_DEBUG)
		return (false);
	va_start(ap, s);
	ft_vprintf_fd(g_ftio_logsfd, s, ap);
	va_end(ap);
	return (true);
}

bool	verbose(const char *s, ...)
{
	va_list	ap;

	if (g_ftio_verbose_level < FTIO_VERBOSE)
		return (false);
	va_start(ap, s);
	ft_vprintf_fd(g_ftio_logsfd, s, ap);
	va_end(ap);
	return (true);
}

bool	info(const char *s, ...)
{
	va_list	ap;

	if (g_ftio_verbose_level < FTIO_INFO)
		return (false);
	va_start(ap, s);
	ft_vprintf_fd(g_ftio_logsfd, s, ap);
	va_end(ap);
	return (true);
}

bool	warning(const char *s, ...)
{
	va_list	ap;

	if (g_ftio_verbose_level < FTIO_WARNING)
		return (false);
	va_start(ap, s);
	ft_printf_fd(g_ftio_logsfd, YELLOW);
	ft_vprintf_fd(g_ftio_logsfd, s, ap);
	ft_printf_fd(g_ftio_logsfd, RESET);
	va_end(ap);
	return (true);
}

bool	error(const char *s, ...)
{
	va_list	ap;

	if (g_ftio_verbose_level < FTIO_ERROR)
		return (false);
	va_start(ap, s);
	ft_printf_fd(g_ftio_logsfd, RED);
	ft_vprintf_fd(g_ftio_logsfd, s, ap);
	ft_printf_fd(g_ftio_logsfd, RESET);
	va_end(ap);
	return (true);
}
