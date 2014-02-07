/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 19:04:53 by dlancar           #+#    #+#             */
/*   Updated: 2014/02/07 13:09:14 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
** This function set the options use by ft_error and ft_error_msg.
** Use ERR_GET to get current flags.
** Available display :
** * ERR_DISP_NONE   -> No display.
** * ERR_DISP_PERROR -> Display is done by the system perror function.
** * ERR_DISP_AUTO   -> Display sys_errlist[errno] (usually produce the same
** *                    output as perror).
** Other flags :
** * ERR_FATAL       -> Call exit(EXIT_FAILURE) instead of return.
** ERR_DISP_AUTO and ERR_FATAL are set by default.
*/
t_flags		error_opt(t_flags flags)
{
	static t_flags	err_flags = ERR_DISP_AUTO | ERR_FATAL;

	if (flags == ERR_GET)
		return (err_flags);
	err_flags = flags;
	return (err_flags);
}

/*
** Return value is always NULL.
*/
void	*ft_error(void)
{
	t_flags		flags;

	flags = error_opt(ERR_GET);
	if (flags & ERR_DISP_PERROR)
		perror(NULL);
	else if (flags & ERR_DISP_AUTO)
	{
		if (errno > 106)
			errno = 0;
		ft_printf("Error : %s.\n", sys_errlist[errno]);
	}
	if (flags & ERR_FATAL)
		exit(EXIT_FAILURE);
	return (NULL);
}

/*
** msg is a formated string.
** Return value is always NULL.
*/
void	*ft_error_msg(const char *msg, ...)
{
	va_list		ap;
	t_flags		flags;

	flags = error_opt(ERR_GET);
	va_start(ap, msg);
	ft_vprintf(msg, ap);
	va_end(ap);
	if (flags & ERR_FATAL)
		exit(EXIT_FAILURE);
	return (NULL);
}

