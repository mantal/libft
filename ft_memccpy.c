/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:18:58 by dlancar           #+#    #+#             */
/*   Updated: 2017/01/27 13:04:11 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*dst;
	const unsigned char	*src;
	unsigned char		x;

	dst = (unsigned char *)s1;
	src = (const unsigned char *)s2;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*dst++ = *src++) == x)
			return (dst);
		i++;
	}
	return (NULL);
}
