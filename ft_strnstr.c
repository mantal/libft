/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:52:21 by dlancar           #+#    #+#             */
/*   Updated: 2013/11/27 18:51:02 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (!s1)
		return (NULL);
	if (!s2 || !*s2)
		return ((char*)s1);
	while (*s1 && n)
	{
		n--;
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
