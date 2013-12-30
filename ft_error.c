/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 19:04:53 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/30 15:52:05 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
** Supported flags :
** ERR_DISP  -> call perror.
** ERR_FATAL -> call exit(EXIT_FAILURE) after an eventual call to perror.
** Return value is always NULL.
*/
void	*ft_error(t_flags flags)
{
	if (flags & ERR_DISP)
		perror(NULL);
	if (flags & ERR_FATAL)
		exit(EXIT_FAILURE);
	return (NULL);
}

/*
** Supported errors :
** ERR_MALLOC -> memory allocation error.
** ERR_FORK   -> fork error.
** Supported flags :
** ERR_FATAL  -> call exit(EXIT_FAILURE) after display error message.
** msg is a formated string.
** If flags is non-nul, msg and additionals parameters are ignored.
** Return value is always NULL.
*/
void	*ft_error_msg(const char *msg, t_flags flags, ...)
{
	va_list	ap;

	va_start(ap, flags);
	if (*msg)
		ft_vprintf(msg, ap);
	else if (flags & ERR_MALLOC)
		ft_putendl("Error : can not allocate memory.");
	else if (flags & ERR_FORK)
		ft_putendl("Error : can not fork process.");
	va_end(ap);
	if (flags & ERR_FATAL)
		exit(EXIT_FAILURE);
	return (NULL);
}

