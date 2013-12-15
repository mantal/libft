/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:48:45 by dlancar           #+#    #+#             */
/*   Updated: 2013/11/25 18:16:21 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	is_useless(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strtrim(const char *s)
{
	char	*res;
	char	*temp;

	if (!s)
		return (ft_strnew(1));
	while (is_useless(*s))
		s++;
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	temp = ft_strchr(res, '\0');
	while (is_useless(*temp))
		temp--;
	return (ft_strsub(res, 0, temp - res));
}
