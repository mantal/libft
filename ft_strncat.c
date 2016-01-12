/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:52:21 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:29:32 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	size;

	size = ft_strlen(s1);
	ft_memcpy(s1 + size, s2, n);
	s1[size + n + 1] = '\0';
	return (s1);
}
