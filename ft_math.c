/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 16:59:08 by dlancar           #+#    #+#             */
/*   Updated: 2014/05/09 12:55:28 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int		ft_pow(int a, unsigned int n)
{
	int		res;

	res = 1;
	while (n--)
		res *= a;
	return (res);
}

t_uint	ft_sqrt(t_uint n)
{
	unsigned long int	res;

	res = 0;
	while (res * res < n)
		res++;
	if (n - (res - 1) * (res - 1) < n - res * res)
		return (res - 1);
	return ((t_uint)res);
}

double	ft_sqrt_d(t_uint n)
{
	double	res;
	t_uint	s;

	if (!n)
		return (0);
	s = ft_sqrt(n);
	res = (s * s) * ((s * s) + 6 * n) + (n * n);
	res /= (4 * s) * ((s * s) + n);
	return (res);
}
