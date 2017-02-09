/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:31:47 by dlancar           #+#    #+#             */
/*   Updated: 2017/01/27 13:09:16 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

const char	*ft_strchar(const char *s1, const char *s2)
{
	const char	*temp;

	while (*s2)
	{
		if ((temp = ft_strchr(s1, *s2)))
			return (temp);
		s2++;
	}
	return (NULL);
}
