/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 11:49:07 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 14:10:22 by dlancar          ###   ########.fr       */
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
	while (TRUE)
	{
		res++;
		n /= base;
		if (!n)
			break ;
	}
	return (res);
}
