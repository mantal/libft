/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 16:31:12 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/08 14:16:23 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include "libft.h"

t_array		*ft_strsplitstr(const char *s, const char *s1)
{
	t_array		*res;
	int			i;
	char		*temp;

	res = array_new(sizeof(char *), PTR);
	i = 0;
	while (*s)
	{
		while (*s && ft_strchr(s1, *s))
			s++;
		while (s[i] && !ft_strchr(s1, s[i]))
			i++;
		if (!*s)
			return (res);
		temp = ft_strndup(s, i);
		if (!temp)
		{
			array_free(res);
			return (NULL);
		}
		array_add(res, temp);
		s += i;
		i = 0;
	}
	return (res);
}
