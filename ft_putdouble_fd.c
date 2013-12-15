/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:56:05 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/11 15:43:49 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble_fd(double d, int fd)
{
	int		i;

	i = 0;
	ft_putnbr_fd((int)d, fd);
	ft_putchar_fd('.', fd);
	d-= (int)d;
	while (i++ < 6)
		d *= 10;
	ft_putnbr_fd(d, fd);
}
