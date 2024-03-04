/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_pipes_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:36:27 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:29 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_hendle_pipe(t_vector *pipe_fd, size_t pipe_iter, t_io io)
{
	size_t	i;

	i = 0;
	if (pipe_iter != 0 && io.input == STDIN_FILENO)
		dup2(pipe_fd->arr[(pipe_iter - 1) * 2], STDIN_FILENO);
	if (pipe_iter != pipe_fd->size / 2 && io.output == STDOUT_FILENO)
		dup2(pipe_fd->arr[(pipe_iter * 2) + 1], STDOUT_FILENO);
	while (i < pipe_fd->size)
		close(pipe_fd->arr[i++]);
}

void	ft_handle_redirect_ios(t_io io)
{
	if (io.input != STDIN_FILENO)
	{
		dup2(io.input, STDIN_FILENO);
		close(io.input);
	}
	if (io.output != STDOUT_FILENO)
	{
		dup2(io.output, STDOUT_FILENO);
		close(io.output);
	}
	if (io.error != STDERR_FILENO)
	{
		dup2(io.error, STDERR_FILENO);
		close(io.error);
	}
}

char	*ft_get_last_arg(t_command *command)
{
	size_t	i;

	i = 0;
	if (!command || !command->argument || !command->argument->arguments || \
		!command->argument->arguments[0])
		return (NULL);
	while (command->argument->arguments[i])
		++i;
	return (ft_strdup(command->argument->arguments[i - 1]));
}

void	ft_handle_external_command(t_command *command, t_symbol_table *table, \
									char **env)
{
	int	status;

	status = ft_command_path(command, table->env);
	if (g_global_state.is_dir)
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		ft_panic_shell(command->argument->arguments[0], " Is a directory");
		exit(g_global_state.permission_status);
	}
	if (g_global_state.permission_status)
	{
		ft_panic_shell("minishell: ", \
		strerror(g_global_state.permission_status));
		exit(g_global_state.permission_status);
	}
	if (!status)
		execve(command->argument->arguments[0], \
				command->argument->arguments, env);
	else if (status != 126)
		ft_panic_shell(command->argument->arguments[0], ": command not found");
	exit(status);
}

t_function_callback	ft_handle_pipe_builtins(int is_pipe, t_process_info	*info)
{
	t_function_callback	builtin_func;

	builtin_func = NULL;
	if (is_pipe)
	{
		ft_hendle_pipe(&info->pipe_fd, info->pipe_iter, info->command->io);
		if (!info->command->argument->arguments)
			builtin_func = NULL;
		else
			builtin_func = ft_get_function(info->table->function, \
							info->command->argument->arguments[0]);
		if (builtin_func)
			exit(builtin_func(info->command, info->table));
	}
	return (builtin_func);
}
