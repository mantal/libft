/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:55:46 by dlancar           #+#    #+#             */
/*   Updated: 2015/04/08 14:50:56 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** TODO : remove defines and include <limits.h>
*/
#define INT_MIN -2147483648
#define INT_MAX 2147483647

static void		set(int *a, int *b, int a_val, int b_val)
{
	*a = a_val;
	*b = b_val;
}

static void		ft_setintchar(char **a, int *b, char *a_val, int b_val)
{
	*a = a_val;
	*b = b_val;
}

static void		ft_init(int *n, int *neg, int *exp, int *size)
{
	set(exp, size, 1, 0);
	*neg = *n < 0 ? 1 : 0;
	*n *= *neg ? -1 : 1;
	while (*n >= *exp && *n < INT_MAX)
		set(exp, size, *exp * 10, *size + 1);
	*exp = *n ? *exp / 10 : *exp;
	*size += (*neg || !*n) ? 1 : 0;
}

char			*ft_itoa(int n)
{
	int		exp;
	int		size;
	int		neg;
	float	f;
	char	*res;

	ft_init(&n, &neg, &exp, &size);
	if (!(res = (n == INT_MIN ? ft_strdup("-2147483648") :
				(char *)ft_malloc(sizeof(char) * (size + 1))))
		|| (res && n == INT_MIN)
		|| !(res = n == INT_MAX ? ft_strdup("2147483647") : res)
		|| (res && n == INT_MAX))
		return (res);
	res[size] = '\0';
	if (neg)
		*res++ = '-';
	while (exp >= 1)
	{
		f = (float)(n / exp);
		set((int *)res, &n, ((int)f) + '0', n - ((int)f) * exp);
		ft_setintchar(&res, &exp, res + 1, exp / 10);
	}
	return (res - size);
}
