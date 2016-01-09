/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:30:58 by dlancar           #+#    #+#             */
/*   Updated: 2015/12/08 14:36:16 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_fd(unsigned long n, int fd)
{
	char	res[100];
	int		i;

	i = 0;
	ft_bzero(&res, sizeof(res));
	ft_putstr_fd("0x", fd);
	while (TRUE)
	{
		res[i] = n % 16 >= 10 ? 'a' - 10 + n % 16 : '0' + n % 16;
		n /= 16;
		if (!n)
			break ;
		i++;
	}
	while (i >= 0)
		ft_putchar_fd(res[i--], fd);
}
