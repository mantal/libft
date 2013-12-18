/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:20:34 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/18 15:44:48 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_put_base(unsigned int n, unsigned int base, t_bool upper)
{
	if (base > 10)
	{
		n -= 10;
		if (upper)
			ft_putchar(n + 'A');
		else
			ft_putchar(n + 'a');
	}
	else
		ft_putchar(n + '0');
}

void	ft_putint_base(unsigned int n, unsigned int base)
{
	t_array	*res;
	t_uint	temp;
	int		i;
	
	res = array_new_c(5, 5, sizeof(unsigned int), UINT);
	while (n)
	{
		temp = n % base;
		array_add(res, &temp);
		n /= base;
	}
	i = res->size;
	if (i == 0)
		ft_putchar('0');
	while (i--)
		ft_put_base(((unsigned int*)res->tab)[i], base, TRUE);
	array_free(&res);
}

/*
** Put the n in the base base, if base > 10, lower letter will be use.
*/
void	ft_putint_base_l(unsigned int n, unsigned int base)
{
	t_array	*res;
	t_uint	temp;
	int		i;
	
	res = array_new_c(5, 5, sizeof(unsigned int), UINT);
	while (n)
	{
		temp = n % base;
		array_add(res, &temp);
		n /= base;
	}
	i = res->size;
	if (i == 0)
		ft_putchar('0');
	while (i--)
		ft_put_base(((unsigned int*)res->tab)[i], base, TRUE);
	array_free(&res);
}

