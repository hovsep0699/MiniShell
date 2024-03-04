/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor_with_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:53:59 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:36 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	ft_pipe_count_tree(t_ast_node *tree)
{
	size_t	count_left;
	size_t	count_right;

	count_right = 0;
	count_left = 0;
	if (!tree)
		return (0);
	if (tree->token_type == PIPE)
	{
		count_left = ft_pipe_count_tree(tree->left);
		count_right = ft_pipe_count_tree(tree->right);
		return (count_left + count_right + 1);
	}
	count_left = ft_pipe_count_tree(tree->left);
	count_right = ft_pipe_count_tree(tree->right);
	return (count_left + count_right);
}

void	ft_execute_part(t_ast_node *tree, t_process_info *info, \
						size_t *pipe_iter)
{
	if (!tree)
		return ;
	ft_execute_part(tree->left, info, pipe_iter);
	if (tree->token_type == PIPE)
	{
		ft_open_process_for_pipe(tree, info, pipe_iter);
		return ;
	}
	ft_execute_part(tree->right, info, pipe_iter);
}

void	ft_handle_child_process(t_process_info *info, int is_pipe)
{
	t_function_callback	builtin_func;

	rl_catch_signals = 0;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	g_global_state.permission_status = 0;
	ft_handle_redirect_ios(info->command->io);
	builtin_func = ft_handle_pipe_builtins(is_pipe, info);
	if (!builtin_func && info->command->argument && \
		info->command->argument->arguments && \
		info->command->argument->arguments[0])
		ft_handle_external_command(info->command, info->table, info->env.table);
	exit(EXIT_SUCCESS);
}

int	ft_execute_command(t_process_info *info)
{
	int		status;
	pid_t	pid;

	status = EXIT_SUCCESS;
	g_global_state.is_dir = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_global_state.orig_termios);
	signal(SIGINT, SIG_IGN);
	g_global_state.permission_status = SUCCESS_CODE;
	info->env = ft_convert_env_to_args(info->table->env, 1, 0);
	ft_expand_env(info->command, info->table);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		ft_handle_child_process(info, 1);
	else if (info->command->base.parent && \
			info->command->base.parent->parent && \
			info->command->base.parent->parent->token_type != ROOT)
		ft_restore_std_io(info->io);
	return (status);
}
