/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putubase_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:30:58 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 14:14:41 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putubase_fd(int fd, unsigned long n, unsigned int base)
{
	char	res[42];
	int		i;

	i = 0;
	ft_bzero(&res, sizeof(res));
	while (TRUE)
	{
		res[i] = n % base >= 10 ? 'a' - 10 + n % base : '0' + n % base;
		n /= base;
		if (!n)
			break ;
		i++;
	}
	while (i >= 0)
		ft_putchar_fd(fd, res[i--]);
}
