/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:43:03 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/20 18:06:09 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fterror.h"
#include "ftio.h"
#include "net.h"

#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <netinet/in.h>

#ifdef __linux__
# include <sys/resource.h>
#endif

int			(*g_default_accept)	(t_socket *, int) = socket_accept;
int			(*g_default_read)() = NULL;
int			(*g_default_write)() = NULL;

typedef struct protoent	t_protoent;
typedef struct rlimit	t_rlimit;

t_socket	*socket_create(void)
{
	t_socket	*res;
	t_protoent	*proto;
	t_rlimit	rlimit;
	int			i;

	res = ft_malloc(sizeof(t_socket));
	proto = getprotobyname("tcp");
	res->fd = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	if ((i = 0) || res->fd < 0 || getrlimit(RLIMIT_NOFILE, &rlimit) < 0)
	{
		free(res);
		ft_error();
		return (NULL);
	}
	res->nfds = 0;
	res->fds = ft_malloc(rlimit.rlim_cur * sizeof(t_fd));
	res->fds_size = rlimit.rlim_cur;
	while (i < res->fds_size)
		socket_init_fd(&(res->fds[i++]));
	res->fds[res->fd].type = SOC_SERVER;
	res->fds[res->fd].on_read = g_default_accept;
	res->fds[STDIN].type = SOC_LOCAL;
	res->fds[STDOUT].type = SOC_LOCAL;
	res->fds[STDERR].type = SOC_LOCAL;
	return (res);
}

t_socket	*socket_bind(t_socket *soc, int port)
{
	struct sockaddr_in	addr;

	ft_memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	if (bind(soc->fd, (const struct sockaddr*)&addr, sizeof(struct sockaddr_in))
			< 0)
	{
		ft_error();
		return (NULL);
	}
	soc->port = port;
	return (soc);
}

t_socket	*socket_connect(t_socket *soc, const char *host, int port)
{
	struct sockaddr_in	addr;
	struct hostent		*server;

	server = gethostbyname(host);
	if (!server)
	{
		ft_error();
		return (NULL);
	}
	ft_memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	ft_memcpy(server->h_addr_list[0], &addr.sin_addr.s_addr, server->h_length);
	addr.sin_port = htons(port);
	if (connect(soc->fd, (const struct sockaddr*)&addr,
				sizeof(struct sockaddr_in)) < 0)
	{
		ft_error();
		return (NULL);
	}
	soc->fds[soc->fd].on_read = g_default_read;
	soc->port = port;
	return (soc);
}

t_socket	*socket_listen(t_socket *soc)
{
	if (listen(soc->fd, SOC_BACKLOG) < 0)
	{
		ft_error();
		return (NULL);
	}
	return (soc);
}

int			socket_accept(t_socket *soc, int cs)
{
	struct sockaddr_in	addr;
	socklen_t			addr_len;
	int					res;

	(void)cs;
	addr_len = sizeof(struct sockaddr_in);
	res = accept(soc->fd, (struct sockaddr*)&addr, &addr_len);
	if (res < 0)
	{
		ft_error();
		return (-1);
	}
	socket_clean_fd(&(soc->fds[res]));
	soc->fds[res].type = SOC_CLIENT;
	return (res);
}
