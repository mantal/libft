/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:42:43 by dlancar           #+#    #+#             */
/*   Updated: 2015/10/12 18:00:02 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>
#include <libft.h>
#include <sys/select.h>
#include <sys/resource.h>

#include "net.h"

static void	select_update(t_socket *soc, int r);

void		socket_select(t_socket *soc)
{
	int	i;
	int	r;

	FD_ZERO(&(soc->fd_read));
	FD_ZERO(&(soc->fd_write));
	i = -1;
	soc->nfds = 0;
	while (++i < soc->fds_size)
	{
		if (soc->fds[i].type != SOC_FREE && i != STDOUT)
		{
			FD_SET(i, &(soc->fd_read));
			if (ft_strlen(soc->fds[i].buff_write) > 0)
				FD_SET(i, &soc->fd_write);
			soc->nfds = i > soc->nfds ? i : soc->nfds;
		}
	}
	r = select(soc->nfds + 1, &soc->fd_read, &soc->fd_write, NULL, NULL);
	if (r < 0)
		;
	select_update(soc, r);
}

static void	select_update(t_socket *soc, int r)
{
	int		i;

	i = 0;
	while (r > 0 && i < soc->fds_size)
	{
		if (FD_ISSET(i, &soc->fd_read) && soc->fds[i].on_read)
			soc->fds[i].on_read(soc, i);
		if (FD_ISSET(i, &soc->fd_write) && soc->fds[i].on_write)
			soc->fds[i].on_write(soc, i);
		if (FD_ISSET(i, &soc->fd_read) || FD_ISSET(i, &soc->fd_write))
			r--;
		i++;
	}
}
