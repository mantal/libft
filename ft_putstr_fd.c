/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:38:06 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:56:04 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include "ftstring.h"
#include <unistd.h>

void	ft_putstr_fd(int fd, const char *s)
{
	if (!s)
		write(fd, "(null)", 6);
	else
		write(fd, s, ft_strlen(s));
}
