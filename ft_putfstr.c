/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:16:27 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/06 11:51:06 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfstr(const char *s1, const void *arg)
{
	while (*s1)
	{
		if (*s1 == '%')
		{
			s1++;
			if (*s1 == '%')
				ft_putchar('%');
			else if (*s1 == 'c')
				ft_putchar(*((char*)arg));
			else if (*s1 == 's')
				ft_putstr((char*)arg);
			else if (*s1 == 'd')
				ft_putnbr(*((int*)arg));
		}
		else
			ft_putchar(*s1);
		s1++;
	}
}

