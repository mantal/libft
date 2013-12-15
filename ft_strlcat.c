/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:38:06 by dlancar           #+#    #+#             */
/*   Updated: 2013/11/27 18:46:23 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	it;
	unsigned int	res;
	unsigned int	j;

	j = 0;
	it = ft_strlen(dst);
	res = ft_strlen(src) + it;
	if (size <= it || !size || !dst || !src)
		return (size + (res - it));
	while (it < size)
		dst[it++] = src[j++];
	dst[--it] = '\0';
	return (res);
}
