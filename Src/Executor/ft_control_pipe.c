/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:58:30 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:27 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_ast_node	*ft_ast_left_most(t_ast_node *ast_node)
{
	if (!ast_node || ast_node->token_type == PIPE)
		return (NULL);
	if (ast_node->right)
		return (ast_node->right);
	return (ast_node);
}

int	ft_open_process_for_pipe(t_ast_node *tree, t_process_info *info, \
								size_t *pipe_iter)
{
	t_ast_node	*ast_node;

	if (*pipe_iter <= info->pipe_fd.size / 2)
	{
		ast_node = ft_ast_left_most(tree->left);
		if (ast_node)
		{
			info->command = ft_ast_to_command(ast_node);
			info->pipe_iter = *pipe_iter;
			ft_execute_command(info);
			g_global_state.argument = ft_get_last_arg(info->command);
			(*pipe_iter)++;
		}
		info->command = ft_ast_to_command(tree->right);
		info->pipe_iter = *pipe_iter;
		ft_execute_command(info);
		g_global_state.argument = ft_get_last_arg(info->command);
		(*pipe_iter)++;
	}
	return (0);
}
