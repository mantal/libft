/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 19:04:53 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/30 15:24:57 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
** DISP_ERR -> call perror.
** FATAL_ERR -> call exit after an eventual call to perror.
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
	return (NULL);
}

