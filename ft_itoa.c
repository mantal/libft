/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:55:46 by dlancar           #+#    #+#             */
/*   Updated: 2017/04/20 15:19:40 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"
#include "libft.h"
#include <stdint.h>

static int64_t	get(int64_t n)
{
	int	m;

	m = 0;
	if (n == 0)
		return (0);
	while (n >= 10)
	{
		n /= 10;
		m++;
	}
	return (m);
}

char			*ft_itoa(int32_t n)
{
	t_array	res;
	int64_t	exp;
	int64_t	tmp;
	int64_t	number;

	array_init(&res, sizeof(char), 1);
	number = n;
	if (number < 0)
	{
		number *= -1;
		array_add(&res, "-");
	}
	exp = 1 * ft_pow(10, get(number));
	while (exp > 0)
	{
		tmp = number / (double)exp;
		array_add(&res, (char[]) { '0' + tmp });
		number -= tmp * exp;
		exp /= 10;
	}
	return (res.tab);
}
