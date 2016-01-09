/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 15:50:48 by dlancar           #+#    #+#             */
/*   Updated: 2015/04/14 14:05:23 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <error.h>
#include "net.h"

#include <unistd.h>
#include <stdlib.h>

int		def_read(t_socket *soc, int cs)
{
	int		r;
	char	buff[SOC_BUFF_SIZE];

	if (soc->fds[cs].type != SOC_LOCAL)
		socket_on_read(soc, cs);
	else
	{
		r = socket_read(cs, &buff, SOC_BUFF_SIZE, soc);
		socket_send_msg(soc, cs, buff, r);
	}
	return (cs);
}

int		def_receive(t_socket *soc, int cs)
{
	write(STDOUT, soc->fds[cs].buff_read.tab, soc->fds[cs].buff_read.size);
	soc->fds[cs].buff_read.size = 0;
	return (cs);
}

int		def_err(t_socket *soc, int cs)
{
	if (soc->fds[cs].type == SOC_SERVER)
	{
		ft_printf("Connection to server lost.\n");
		close(soc->fd);
		exit(0);
	}
	close(cs);
	socket_clean_fd(&soc->fds[cs]);
	return (cs);
}

int		main(int argc, char **argv)
{
	t_socket	*socket;

	if (argc < 3)
	{
		ft_printf("Usage: client <host> <port>");
		return (0);
	}
	socket_set_default_read(def_read);
	socket_set_default_receive(def_receive);
	socket_set_default_error(def_err);
	socket = socket_create();
	socket_connect(socket, argv[1], ft_atoi(argv[2]));
	while (1 != 2)
	{
		socket_select(socket);
	}
	close(socket->fd);
	return (0);
}
