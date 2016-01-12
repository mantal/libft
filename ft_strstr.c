/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:08:44 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:51:21 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*temp;

	temp = (char *)s2;
	while (*s1)
	{
		while (*s2)
		{
			if (*s1 == *s2)
				return ((char *)s2);
			s2++;
		}
		s2 = temp;
		s1++;
	}
	return (NULL);
}
