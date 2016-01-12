/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:38:06 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:22:22 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char*)s);
}
