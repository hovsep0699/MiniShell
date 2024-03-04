/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:21:12 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:39 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_get_signal_exit(int status, int *is_signaled, t_exec_type type)
{
	int	sig;

	(void)type;
	sig = 0;
	signal(SIGINT, sigint_handler);
	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (WTERMSIG(status) == SIGPIPE)
			status = WEXITSTATUS(status);
		else
			status = 128 + WTERMSIG(status);
		rl_catch_signals = 0;
		g_global_state.minishell_signal = SIGCHILD;
		if (sig != SIGPIPE)
			ft_child_sigint(sig);
		*is_signaled = 1;
	}
	else if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}

int	ft_get_exit_status(size_t pipe_count, t_process_info *info, \
						t_exec_type type)
{
	int		status;
	size_t	i;
	int		is_signaled;

	status = EXIT_SUCCESS;
	if (info->is_builtin)
		return (info->status);
	is_signaled = 0;
	i = 0;
	while (i < pipe_count + 1)
	{
		wait(&status);
		if (!is_signaled)
			status = ft_get_signal_exit(status, &is_signaled, type);
		++i;
	}
	return (status);
}

void	ft_update_env_exit(t_container cont, t_symbol_table *table)
{
	char	*status;

	status = ft_itoa(cont.exit_status);
	ft_set_env(table->env, (t_hash_data){"?", status, HIDDEN});
	if (g_global_state.argument)
	{
		ft_set_env(table->env, \
		(t_hash_data){"_", g_global_state.argument, VENV});
		g_global_state.argument = NULL;
	}
	free(status);
}

void	ft_executor(t_symbol_table *table, t_container cont)
{
	int				status;
	t_process_info	info;
	size_t			i;

	status = EXIT_SUCCESS;
	info.is_builtin = 0;
	ft_dispatch_container(cont, &info);
	if (g_global_state.heredoc_signal == -1)
	{
		i = 0;
		while (i < info.pipe_fd.size)
		{
			close(info.pipe_fd.arr[i]);
			++i;
		}
		status = ft_get_exit_status(info.pipe_count, &info, cont.exec_type);
	}
	else
		status = 128 + g_global_state.heredoc_signal;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_global_state.orig_termios);
	cont.exit_status = status;
	ft_update_env_exit(cont, table);
	g_global_state.heredoc_signal = -1;
}
