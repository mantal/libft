/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 12:07:51 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/20 16:01:55 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcommand.h"
#include "libft.h"
#include "ftstring.h"
#include "ftio.h"

const t_command	*command_get(const t_command *commands, const char *cmd)
{
	unsigned long	i;

	i = 0;
	while (commands[i].name != NULL)
	{
		if (ft_strcmp(commands[i].name, cmd) == 0)
			return (&commands[i]);
		i++;
	}
	return (NULL);
}

void			command_print_usage(const t_command *cmd)
{
	ft_printf("Usage: /%s %s.\n", cmd->name, cmd->usage);
}

int				command_execute(const t_command *commands, const char *cmd,
				void *data)
{
	t_array			*args;
	const t_command	*command;
	int				r;

	args = ft_strsplit(cmd, ' ');
	if (!args || args->size == 0)
		return (-1);
	command = command_get(commands, *(char **)array_get(args, 0));
	if (command == NULL)
		return (-1);
	if ((int)args->size - 1 < command->args_min
		|| ((int)args->size - 1 > command->args_max && command->args_max >= 0))
	{
		command_print_usage(command);
		return (-1);
	}
	r = command->exec(args, data);
	array_free(args);
	return (r);
}
