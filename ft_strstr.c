/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 09:41:47 by dlancar           #+#    #+#             */
/*   Updated: 2013/11/27 14:13:53 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;

	if (!s2 || !*s2)
		return ((char*)s1);
	while (*s1)
	{
		i = 0;
		while (s1[i] == s2[i])
		{
			i++;
			if (!s2[i])
				return ((char*)s1);
		}
		s1++;
	}
	return (NULL);
}
