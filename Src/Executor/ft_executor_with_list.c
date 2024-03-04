/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor_with_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:54:14 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:34 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_restore_std_io(t_io io)
{
	dup2(io.input, STDIN_FILENO);
	close(io.input);
	dup2(io.output, STDOUT_FILENO);
	close(io.output);
	dup2(io.error, STDERR_FILENO);
	close(io.error);
}

int	ft_handle_external(t_process_info *info)
{
	int		status;
	pid_t	pid;

	status = EXIT_SUCCESS;
	info->env = ft_convert_env_to_args(info->table->env, 1, 0);
	g_global_state.permission_status = SUCCESS_CODE;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		ft_handle_child_process(info, 0);
	else
		ft_restore_std_io(info->io);
	return (status);
}

int	ft_handle_builtin(t_function_callback biltin_func, t_process_info *info, \
						t_vector *fd_vector)
{
	(void)fd_vector;
	if (g_global_state.heredoc_signal != -1)
	{
		ft_restore_std_io(info->io);
		tcsetattr(STDIN_FILENO, TCSANOW, &g_global_state.orig_termios);
		return (g_global_state.heredoc_signal + 128);
	}
	if (g_global_state.permission_status != SUCCESS_CODE)
	{
		ft_panic_shell("minishell: ", \
			strerror(g_global_state.permission_status));
		return (g_global_state.permission_status);
	}
	ft_handle_redirect_ios(info->command->io);
	info->status = biltin_func(info->command, info->table);
	ft_restore_std_io(info->io);
	return (info->status);
}

int	ft_executor_with_list(t_process_info *info)
{
	t_vector			fd_vector;
	t_function_callback	biltin_func;

	g_global_state.argument = ft_get_last_arg(info->command);
	g_global_state.permission_status = SUCCESS_CODE;
	ft_expand_env(info->command, info->table);
	g_global_state.is_dir = 0;
	if (!info->command->argument->arguments)
		biltin_func = NULL;
	else
		biltin_func = ft_get_function(info->table->function, \
						info->command->argument->arguments[0]);
	if (biltin_func)
	{
		info->is_builtin = 1;
		return (ft_handle_builtin(biltin_func, info, &fd_vector));
	}
	return (ft_handle_external(info));
}
