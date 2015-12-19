/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:42:54 by dlancar           #+#    #+#             */
/*   Updated: 2015/12/19 11:53:58 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <stddef.h>

typedef struct	s_iomap
{
	void	*p;
	size_t	size;
}				t_iomap;

int		ft_open(const char *path, int oflag, ...);
int		ft_close(int fd);

char	*io_map_file(int fd, int prot);
int		io_unmap_file(char *p);

#endif
