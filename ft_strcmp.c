/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 09:41:47 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:23:33 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && s2)
		return (-*s2);
	else if (!s2 && s1)
		return (*s1);
	else if (!s1 && !s2)
		return (0);
	if (!*s2)
		return (*s1);
	while (*s1 && *s2)
	{
		if (*s1++ != *s2++)
			return (*--s1 - *--s2);
	}
	return (*s1 - *s2);
}
