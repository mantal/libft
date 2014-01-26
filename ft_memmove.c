/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:52:21 by dlancar           #+#    #+#             */
/*   Updated: 2014/01/26 18:05:00 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char			*s3;
	unsigned int	i;

	i = 0;
	s3 = ft_malloc(n);
	if (!s3)
		return (NULL);
	ft_memcpy(s3, s2, n);
	while (i < n)
	{
		((char *)s1)[i] = s3[i];
		i++;
	}
	free(s3);
	return (s1);
}
