/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:38:06 by dlancar           #+#    #+#             */
/*   Updated: 2013/11/27 18:51:26 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
char	*ft_strrchr(const char *s, int c)
{
	char	*target;

	target = NULL;
	if (!s)
		return (target);
	while (*s)
	{
		if (*s == c)
			target = (char*)s;
		s++;
	}
	if (!c)
		target = (char*)s;
	return (target);
}
