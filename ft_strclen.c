/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:31:47 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:23:16 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	res;

	res = 0;
	if (!s)
		return (res);
	while (*s && *s != c)
	{
		res++;
		s++;
	}
	return (res);
}
