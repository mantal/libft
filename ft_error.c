/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 19:04:53 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/29 17:34:26 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>


/*
** DISP_ERR -> call perror.
** FATAL_ERR -> call exit after an eventual call to perror.
** Return value is always NULL.
*/
void	*ft_error(t_flags flags)
{
	if (flags & DISP_ERR)
		perror(NULL);
	if (flags & FATAL_ERR)
		exit(EXIT_FAILURE);
	return (NULL);
}

