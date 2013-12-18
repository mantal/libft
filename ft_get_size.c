/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:27:16 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/17 12:35:11 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_get_size(int n)
{
	unsigned int	res;
	double			d;
	
	res = 0;
	d = (n > 0) ? (double)n : -((double)n);
	if (n == 0)
		return (1);
	while ((long int)d > 0)
	{
		d /= 10;
		res++;
	}
	if (n < 0)
		res++;
	return (res);
}

