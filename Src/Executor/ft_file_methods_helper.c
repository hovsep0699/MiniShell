/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_methods_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:36:35 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:53 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_file_mode	ft_init_mode(t_token_type type)
{
	t_file_mode	mode;

	if (type == WRITE)
		mode = (t_file_mode){.is_heredoc = 0, .is_input = 0, \
		.access_mode = W_OK, .mode = WRITE, \
		.open_mode = O_TRUNC | O_WRONLY | O_CREAT};
	else if (type == READ)
		mode = (t_file_mode){.is_heredoc = 0, .is_input = 1, \
		.access_mode = R_OK, .mode = READ, .open_mode = O_RDONLY};
	else if (type == APPEND)
		mode = (t_file_mode){.is_heredoc = 0, .is_input = 0, \
		.access_mode = R_OK | W_OK, .mode = APPEND, \
		.open_mode = O_APPEND | O_WRONLY | O_CREAT};
	else if (type == HEREDOC)
		mode = (t_file_mode){.is_heredoc = 1, \
		.is_input = 1, .mode = HEREDOC};
	else
		mode = (t_file_mode){0, 0, 0, 0, 0};
	return (mode);
}

int	ft_open_file_type_mode(t_redirect *redirect, t_process_info *info, \
							t_vector *fd_vector, t_file_mode modes)
{
	int	fd;

	fd = -1;
	if (redirect->base.token_type == modes.mode)
	{
		fd = ft_open_with_mode(redirect, modes, info);
		if (g_global_state.heredoc_signal != -1)
		{
			if (fd != -1)
				close(fd);
			return (-1);
		}
		if (modes.is_input && info->command->io.input < fd)
			info->command->io.input = fd;
		else if (!modes.is_input && info->command->io.output < fd)
			info->command->io.output = fd;
		else
			ft_push_arrey(fd_vector, fd);
	}
	return (fd);
}

int	ft_open_with_mode(t_redirect *redirect, t_file_mode modes, \
						t_process_info *info)
{
	int	fd;

	fd = -1;
	if (modes.is_heredoc)
		fd = ft_open_heredoc(redirect, info->table->env);
	else
	{
		fd = open(redirect->argument, modes.open_mode, 0664);
		if (access(redirect->argument, modes.access_mode) == -1)
		{
			g_global_state.permission_status = errno;
			close(fd);
			fd = -1;
			return (fd);
		}
	}
	return (fd);
}
