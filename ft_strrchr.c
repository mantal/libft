/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:38:06 by dlancar           #+#    #+#             */
/*   Updated: 2017/01/27 13:07:30 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

const char	*ft_strrchr(const char *s, int c)
{
	const char	*target;

	target = NULL;
	if (!s)
		return (target);
	while (*s)
	{
		if (*s == c)
			target = s;
		s++;
	}
	if (!c)
		target = s;
	return (target);
}
