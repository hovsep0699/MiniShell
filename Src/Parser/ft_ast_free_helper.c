/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_free_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 03:52:32 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:45 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_collect_ast_to_q(t_ast_node *tree, t_global_stack *q_node)
{
	if (!tree)
		return ;
	ft_push_shant_stack(q_node, tree);
	ft_collect_ast_to_q(tree->left, q_node);
	ft_collect_ast_to_q(tree->right, q_node);
}

void	ft_close_command_fd(t_io io)
{
	if (io.input > 2)
	{
		close(io.input);
		io.input = STDIN;
	}
	if (io.output > 2)
	{
		close(io.output);
		io.output = STDOUT;
	}
	if (io.error > 2)
	{
		close(io.error);
		io.error = STDERR;
	}
}
