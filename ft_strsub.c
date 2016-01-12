/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:27:08 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:51:35 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*res;

	s += start;
	res = ft_malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res = ft_strncpy(res, s, len);
	res[len] = '\0';
	return (res);
}
