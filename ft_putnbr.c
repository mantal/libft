/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:48:45 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/22 18:37:04 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	unsigned long int	exp;
	unsigned int		temp;
	float				f;

	if (!(temp = n) && n < 0)
	{
		temp = -n;
		write(STDOUT, "-", 1);
	}
	if (n == 0)
	{
		write(STDOUT, "0", 1);
		return ;
	}
	exp = 1;
	while (temp >= exp)
		exp *= 10;
	exp /= 10;
	while (exp >= 1)
	{
		f = temp / exp;
		ft_putchar((long int)f + '0');
		temp -= ((long int)f) * exp;
		exp /= 10;
	}
}
