/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 16:59:08 by dlancar           #+#    #+#             */
/*   Updated: 2014/01/03 14:31:34 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int				ft_round(double d)
{
	if ((long int)d == 0)
		return (0);
	if (d > 0)
	{
		if (d - (long int)d > 0.5)
			return ((long int)d + 1);
		return (d);
	}
	if (d - (long int)d > 0.5)
		return ((long int)d - 1);
	return ((long int)d);
}

int				ft_pow(int a, unsigned int n)
{
	if (n == 0)
		return (1);
	return (ft_pow(a, n - 1) * a);
}

/*
** Return the nearest perfect square to n.
** The behaviour is undefinined when n approach to UINT_MAX
*/
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

double			ft_sqrt_d(t_uint n)
{
	double	res;
	t_uint	s;

	if (!n)
		return (0);
	s = ft_sqrt(n);
	res = (s * s) * ((s * s) + 6 * n) + (n * n);
	res /= (4 * s) * ((s *s) + n);
	return (res);
}

