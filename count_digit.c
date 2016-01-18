/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 11:49:07 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/18 16:49:47 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digit(unsigned int n)
{
	return (count_digit_base(n, 10));
}

size_t	count_digit_base(unsigned int n, unsigned int base)
{
	unsigned int	res;

	res = 0;
	while (true)
	{
		res++;
		n /= base;
		if (!n)
			break ;
	}
	return (res);
}
