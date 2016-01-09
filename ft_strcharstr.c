/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:08:44 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 16:13:01 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcharstr(const char *s1, const char *s2)
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
