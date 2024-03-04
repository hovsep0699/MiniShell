/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:37:42 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:17:18 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_init_global_state(void)
{
	g_global_state.is_tree = 0;
	g_global_state.last_in = -1;
	g_global_state.heredoc_signal = -1;
	g_global_state.permission_status = 0;
	rl_catch_signals = 0;
	g_global_state.is_dir = 0;
	rl_signal_event_hook = &ft_sig;
	tcgetattr(STDIN_FILENO, &g_global_state.orig_termios);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, ft_sigquit_handler);
	ft_init_history(&g_global_state.history, 0);
}

void	ft_start_shell(char *line, t_list_token **list, t_container *container)
{
	*list = ft_tokenize(line, SEPARATORS);
	*container = ft_parser(*container, *list);
	if (container->exit_status == SUCCESS_CODE)
		ft_executor(container->table, *container);
	else
	{
		close(container->fd.error);
		close(container->fd.input);
		close(container->fd.output);
		ft_update_env_exit(*container, container->table);
	}
}

void	ft_free_container_dispatch(t_container container)
{
	if (container.exec_type == LIST)
		ft_free_command(container.command);
	else
	{
		ft_free_tree(container.tree->ast_node);
		free(container.tree);
	}
}

void	ft_handle_status(char *line, t_list_token	**list, \
						t_container *container)
{
	container->exit_status = ft_balanced(line);
	if (container->exit_status)
	{
		ft_update_env_exit(*container, container->table);
		free(line);
		return ;
	}
	ft_start_shell(line, list, container);
	ft_free_container_dispatch(*container);
	ft_free_list(*list);
	free(line);
}

void	ft_main_loop(t_container *container)
{
	char			*line;
	t_list_token	*list;

	list = NULL;
	while (1)
	{
		rl_done = 0;
		g_global_state.minishell_signal = SIGNORMAL;
		line = ft_get_line();
		if (!line)
			exit(0);
		if (!(*line))
		{
			free(line);
			continue ;
		}
		ft_handle_status(line, &list, container);
	}
}
