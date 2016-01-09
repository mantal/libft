/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:42:54 by dlancar           #+#    #+#             */
/*   Updated: 2015/12/11 15:45:57 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <fcntl.h>

int		ft_open(const char *path, int oflag, ...);
int		ft_close(int fd);

#endif
