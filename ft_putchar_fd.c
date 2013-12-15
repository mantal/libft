/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:17:03 by dlancar           #+#    #+#             */
/*   Updated: 2013/11/22 11:17:04 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(_WIN32) || defined(__WIN32__)
 #include <io.h>
#else
 #include <unistd.h>
#endif

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
