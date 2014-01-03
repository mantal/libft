/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 16:59:08 by dlancar           #+#    #+#             */
/*   Updated: 2014/01/03 11:47:02 by dlancar          ###   ########.fr       */
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

int		ft_pow(int a, unsigned int n)
{
	if (n == 0)
		return (1);
	return (ft_pow(a, n - 1) * a);
}

