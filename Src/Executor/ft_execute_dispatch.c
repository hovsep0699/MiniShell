/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_dispatch.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:35:02 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:32 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_dispatch_list_part(t_container cont, t_process_info *info)
{
	t_vector	fd_vector;

	info->pipe_count = 0;
	info->command = cont.command;
	ft_init_arrey(&fd_vector, 0);
	ft_open_file(info, &fd_vector);
	if (g_global_state.heredoc_signal == -1)
		info->status = ft_executor_with_list(info);
}

void	ft_dispatch_tree_part(t_container cont, t_process_info *info)
{
	g_global_state.is_tree = 1;
	ft_open_all_fd(cont.tree->ast_node, info);
	if (g_global_state.heredoc_signal == -1)
	{
		info->pipe_count = ft_pipe_count_tree(cont.tree->ast_node);
		info->pipe_fd = ft_open_pipe_fd(info->pipe_count);
		ft_execute_part(cont.tree->ast_node, info, &info->pipe_iter);
	}
}

void	ft_dispatch_container(t_container cont, t_process_info *info)
{
	info->pipe_iter = 0;
	info->io = cont.fd;
	info->table = cont.table;
	ft_init_arrey(&info->pipe_fd, 0);
	if (cont.exec_type == LIST)
		ft_dispatch_list_part(cont, info);
	else
		ft_dispatch_tree_part(cont, info);
}
