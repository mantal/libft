/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 16:59:08 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/08 15:20:07 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int				ft_pow(int a, unsigned int n)
{
	int		res;

	res = 1;
	while (n--)
		res *= a;
	return (res);
}

unsigned int	ft_sqrt(unsigned int n)
{
	unsigned long int	res;

	res = 0;
	while (res * res < n)
		res++;
	if (n - (res - 1) * (res - 1) < n - res * res)
		return (res - 1);
	return ((unsigned int)res);
}

double			ft_sqrt_d(unsigned int n)
{
	double			res;
	unsigned int	s;

	if (!n)
		return (0);
	s = ft_sqrt(n);
	res = (s * s) * ((s * s) + 6 * n) + (n * n);
	res /= (4 * s) * ((s * s) + n);
	return (res);
}
