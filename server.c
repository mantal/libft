/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:42:43 by dlancar           #+#    #+#             */
/*   Updated: 2015/03/19 16:42:53 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>
#include <libft.h>
#include <sys/select.h>
#include <sys/resource.h>

#include "net.h"

void	server_select(t_socket *soc)
{
	int	i;

	FD_ZERO(&(soc->fd_read));
	FD_ZERO(&(soc->fd_write));
	i = -1;
	soc->nfds = 0;
	while (++i < soc->fds_size)
	{
		if (soc->fds[i].type != SOC_FREE)
		{
			FD_SET(i, &(soc->fd_read));
			if (ft_strlen(soc->fds[i].buff_write) > 0)
			{
				FD_SET(i, &soc->fd_write);
			}
			soc->nfds = i > soc->nfds ? i : soc->nfds;
		}
	}
	soc->select_r = select(soc->nfds + 1, &soc->fd_read,
			&soc->fd_write, NULL, NULL);
	if (soc->select_r < 0)
		ft_perror();
}

void	server_update(t_socket *soc)
{
	int		i;

	i = -1;
	while (soc->select_r > 0 && ++i < soc->fds_size)
	{
		if (FD_ISSET(i, &soc->fd_read) && soc->fds[i].on_read)
			soc->fds[i].on_read(soc, i);
		if (FD_ISSET(i, &soc->fd_write) && soc->fds[i].on_write)
			soc->fds[i].on_write(soc, i);
		if (FD_ISSET(i, &soc->fd_read) || FD_ISSET(i, &soc->fd_write))
			soc->select_r--;
	}
}
