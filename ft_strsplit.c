/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:20:49 by dlancar           #+#    #+#             */
/*   Updated: 2014/05/09 12:58:42 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array		*ft_strsplit(const char *s, char c)
{
	t_array	*res;
	char	*temp;

	res = array_new(100, 10, sizeof(char *), PTR);
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (res);
		temp = ft_strndup(s, ft_strclen(s, c));
		if (!temp)
		{
			array_free(&res);
			return (NULL);
		}
		array_add(res, temp);
		s += ft_strclen(s, c);
	}
	return (res);
}
