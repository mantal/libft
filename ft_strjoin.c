/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 09:40:24 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:54:27 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;

	res = ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_bzero(res, sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	ft_strcat(ft_strcat(res, s1), s2);
	return (res);
}
