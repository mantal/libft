/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:38:06 by dlancar           #+#    #+#             */
/*   Updated: 2013/11/27 18:42:57 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#if defined(_WIN32) || defined(__WIN32__)
 #include <io.h>
#else
 #include <unistd.h>
#endif

void	ft_putstr(const char *s)
{
	if (!s)
		write(STDOUT, "(null)", 6);
	else
		write(STDOUT, s, ft_strlen(s));
}
