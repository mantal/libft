/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:56:05 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 14:13:55 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble_fd(int fd, double d)
{
	int		i;

	i = 0;
	ft_putint_fd((int)d, fd);
	ft_putchar_fd('.', fd);
	d -= (int)d;
	while (i++ < 6)
		d *= 10;
	ft_putint_fd(d, fd);
}
