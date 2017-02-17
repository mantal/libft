/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 15:51:52 by dlancar           #+#    #+#             */
/*   Updated: 2015/04/14 15:12:47 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <error.h>
#include "net.h"

#include <unistd.h>
#include <stdlib.h>

int		def_accept(t_socket *soc, int cs)
{
	char	*temp;
	int		r;

	cs = socket_on_accept(soc, cs);
	ft_printf("%d joined the channel.\n", cs);
	for (int i = 0; i < soc->fds_size; i++)
	{
		if (soc->fds[i].type == SOC_CLIENT && i != cs)
		{
			r = ft_asprintf(&temp, "%d joined the channel.\n", cs);
			socket_send_msg(soc, i, temp, r);
			free(temp);
		}
	}
	return (cs);
}

int		def_recv(t_socket *soc, int cs)
{
	char	*temp;
	int		r;

	ft_printf("[%d]: ", cs);
	write(STDOUT, soc->fds[cs].buff_read.tab, soc->fds[cs].buff_read.size);
	for (int i = 0; i < soc->fds_size; i++)
	{
		if (soc->fds[i].type == SOC_CLIENT && i != cs)
		{
			array_add(&soc->fds[cs].buff_read, "\0");
			r = ft_asprintf(&temp, "[%d]: %s\n", cs, soc->fds[cs].buff_read);
			socket_send_msg(soc, i, temp, r);
			free(temp);
		}
	}
	return (cs);
}

int		def_read(t_socket *soc, int cs)
{
	char	*temp;
	int		r;

	if (soc->fds[cs].type != SOC_LOCAL)
		return (socket_on_read(soc, cs));
	r = socket_read(cs, soc->fds[cs].buff_read.tab, SOC_BUFF_SIZE, soc);
	((char *)soc->fds[cs].buff_read.tab)[r - 1] = '\0';
	r = ft_asprintf(&temp, "[SERVER]: %s\n", cs, soc->fds[cs].buff_read);
	for (int i = 0; i < soc->fds_size; i++)
	{
		if (soc->fds[i].type == SOC_CLIENT)
			socket_send_msg(soc, i, temp, r);
	}
	free(temp);
	return (cs);
}

int		def_err(t_socket *soc, int cs)
{
	char	*temp;
	int		r;

	close(cs);
	socket_clean_fd(&soc->fds[cs]);
	array_add(&soc->fds[cs].buff_read, "\0");
	r = ft_asprintf(&temp, "%d left the channel.\n", cs);
	ft_printf("%s", temp);
	for (int i = 0; i < soc->fds_size; i++)
	{
		if (soc->fds[i].type == SOC_CLIENT && i != cs)
		{
			socket_send_msg(soc, i, temp, r);
		}
	}
	free(temp);
	return (cs);
}

int		main(int argc, char **argv)
{
	t_socket	*socket;

	if (argc < 2)
		return (0);

	socket_set_default_read(def_read);
	socket_set_default_accept(def_accept);
	socket_set_default_receive(def_recv);
	socket_set_default_error(def_err);

	socket = socket_create();
	socket_bind(socket, ft_atoi(argv[1]));
	socket_listen(socket);
	while (1 != 2)
	{
		socket_select(socket);
	}
	close(socket->fd);
	return (0);
}
