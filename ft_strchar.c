/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:31:47 by dlancar           #+#    #+#             */
/*   Updated: 2015/10/12 16:35:23 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the position of the first occurence of s2 in s1. Return NULL if s1
** has no common character with s2.
*/
char	*ft_strchar(const char *s1, const char *s2)
{
	char	*temp;

	while (*s2)
	{
		if ((temp = ft_strchr(s1, *s2)))
			return (temp);
		s2++;
	}
	return (NULL);
}
