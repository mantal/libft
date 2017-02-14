/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcommand.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 12:08:51 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/14 16:23:46 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTCOMMAND_H
# define FTCOMMAND_H

# include "libft.h"

typedef struct	s_command
{
	char	*name;
	char	*usage;
	char	*help;
	int		args_min;
	int		args_max;
	int		(*exec)(t_array *, void *);
}				t_command;

const t_command	*command_get(const t_command *commands, const char *cmd);
void			command_print_usage(const t_command *cmd);
int				command_execute(const t_command *commands, const char *cmd,
				void *data);

#endif
