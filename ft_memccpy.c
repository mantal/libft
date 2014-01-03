/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:18:58 by dlancar           #+#    #+#             */
/*   Updated: 2014/01/03 11:45:11 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
** WARNING: This function may not work.
*/

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dst;
	unsigned char	*src;
	unsigned char	x;

	dst = (unsigned char*)s1;
	src = (unsigned char*)s2;
	x = (unsigned char)c;
	i = 0;
	if (!s1 || !s2 || !n)
		return (NULL);
	while (i < n)
	{
		if ((*dst++ = *src++) == x)
			return (dst);
		i++;
	}
	return (NULL);
}

