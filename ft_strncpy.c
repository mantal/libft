/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:38:06 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:30:07 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftstring.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int	size;

	if (!s1 || !s2)
		return (s1);
	size = ft_strlen(s2);
	if (size >= n)
		ft_memcpy(s1, s2, n);
	else
	{
		ft_memcpy(s1, s2, size);
		ft_memset(s1 + size, '\0', n - size);
	}
	return (s1);
}
