/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:48:45 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:53:05 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include "libft.h"

static bool	is_useless(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (true);
	return (false);
}

char		*ft_strtrim(const char *s)
{
	char		*temp;

	while (is_useless(*s))
		s++;
	if (!*s)
		return (ft_strdup(""));
	temp = ft_strchr(s, '\0') - 1;
	while (is_useless(*temp))
		temp--;
	return (ft_strsub(s, 0, temp - s + 1));
}
