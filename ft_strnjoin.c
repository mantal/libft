/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 10:28:00 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:31:20 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftstring.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t n)
{
	char	*res;

	res = ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_bzero(res, sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strncat(res, s2, n);
	return (res);
}
