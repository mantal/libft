/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:52:21 by dlancar           #+#    #+#             */
/*   Updated: 2013/11/27 16:57:30 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*s3;
	unsigned int	i;

	i = 0;
	s3 = ft_strdup(s2);
	if (!s3)
		return (NULL);
	while (s1 && i < n)
	{
		((unsigned char*)s1)[i] = s3[i];
		i++;
	}
	free(s3);
	return (s1);
}
