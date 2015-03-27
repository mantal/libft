/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:51:24 by dlancar           #+#    #+#             */
/*   Updated: 2015/03/27 11:51:30 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NET_H
# define NET_H

# include <sys/socket.h>

# define SOC_FREE   0
# define SOC_CLIENT 1
# define SOC_SERVER 2
# define SOC_LOCAL  3

# define SOC_BACKLOG 64

# define SOC_BUFF_SIZE 2048

typedef struct	s_fd
{
	int		type;
	char	buff_read[SOC_BUFF_SIZE + 1];
	char	buff_write[SOC_BUFF_SIZE + 1];
	int		(*on_read)();
	int		(*on_write)();
}				t_fd;

typedef struct	s_socket
{
	fd_set	fd_read;
	fd_set	fd_write;
	int		nfds;
	t_fd	*fds;
	int		fds_size;
	int		port;
	int		fd;
}				t_socket;

t_socket		*socket_create(void);
t_socket		*socket_connect(t_socket *soc, const char *host_name, int port);
t_socket		*socket_bind(t_socket *soc, int port);
t_socket		*socket_listen(t_socket *soc);
void			socket_select(t_socket *soc);

void			socket_clean_fd(t_fd *fd);

int				socket_accept(t_socket *soc, int cs);

void			socket_set_default_accept(int (*def_accept)());
void			socket_set_default_read(int (*def_read)());
void			socket_set_default_write(int (*def_write)());

extern int	(*g_default_accept)(t_socket *, int);
extern int	(*g_default_read)();
extern int	(*g_default_write)();

#endif
