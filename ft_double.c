/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:53:06 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/08 15:18:11 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int		ft_round(double d)
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

double	ft_trunc(double d, unsigned int p)
{
	double			temp;
	double			res;
	unsigned int	i;

	i = 0;
	res = (long long int)d;
	d -= (long long int)d;
	while (i < p)
	{
		temp = d * 10;
		temp = (long long int)temp;
		temp /= ft_pow(10, i + 1);
		d *= 10;
		d -= (long long int)d;
		res += temp;
		i++;
	}
	return (res);
}
