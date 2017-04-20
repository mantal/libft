/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:42:43 by dlancar           #+#    #+#             */
/*   Updated: 2017/04/20 15:21:11 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterror.h"
#include "ftio.h"
#include "libft.h"
#include "ftnet.h"

#include <sys/select.h>
#include <sys/resource.h>

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

void		socket_select(t_socket *soc)
{
	int	i;
	int	r;

	FD_ZERO(&(soc->fd_read));
	FD_ZERO(&(soc->fd_write));
	i = 0;
	soc->nfds = 0;
	while (i < soc->fds_size)
	{
		if (soc->fds[i].type != SOC_FREE && i != STDOUT_FILENO
						&& i != STDERR_FILENO)
		{
			FD_SET(i, &(soc->fd_read));
			soc->nfds = i > soc->nfds ? i : soc->nfds;
		}
		i++;
	}
	r = select(soc->nfds + 1, &soc->fd_read, &soc->fd_write, NULL, NULL);
	if (r == -1)
		ft_error();
	else
		select_update(soc, r);
}
