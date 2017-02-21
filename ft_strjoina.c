/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoina.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:43:49 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/21 14:48:02 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

char	*ft_strjoina(const char **s)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] != NULL)
	{
		len += ft_strlen(s[i]);
		i++;
	}
	len++;
	res = ft_malloc(len * sizeof(char));
	ft_bzero(res, len * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ft_strcat(res, s[i]);
		i++;
	}
	return (res);
}
