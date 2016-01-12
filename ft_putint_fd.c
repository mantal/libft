/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:48:45 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:05:39 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"

void	ft_putint_fd(int fd, int n)
{
	unsigned long int	exp;
	unsigned int		temp;
	float				f;

	if (!(temp = n) && n < 0)
	{
		temp = -n;
		ft_putchar_fd(fd, '-');
	}
	if (n == 0)
	{
		ft_putchar_fd(fd, '0');
		return ;
	}
	exp = 1;
	while (temp >= exp)
		exp *= 10;
	exp /= 10;
	while (exp >= 1)
	{
		f = temp / exp;
		ft_putchar_fd(fd, (long int)f + '0');
		temp -= ((long int)f) * exp;
		exp /= 10;
	}
}
