/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:27:08 by dlancar           #+#    #+#             */
/*   Updated: 2014/01/17 19:45:34 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*res;

	s += start;
	res = (char *)ft_malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res = ft_strncpy(res, s, len);
	res[len] = '\0';
	return (res);
}
