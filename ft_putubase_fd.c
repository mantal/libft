/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:30:58 by dlancar           #+#    #+#             */
/*   Updated: 2015/12/08 15:37:08 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putubase_fd(unsigned long n, unsigned int base, int fd)
{
	char	res[42];
	int		i;

	i = 0;
	ft_bzero(&res, sizeof(res));
	ft_putstr_fd("0x", fd);
	while (TRUE)
	{
		res[i] = n % base >= 10 ? 'a' - 10 + n % base : '0' + n % base;
		n /= base;
		if (!n)
			break ;
		i++;
	}
	while (i >= 0)
		ft_putchar_fd(res[i--], fd);
}
