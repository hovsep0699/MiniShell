/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:18:13 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:47 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_free_redirect(t_redirect *redirect)
{
	t_ast_node		*tmp;
	t_ast_node		*tmp_next;
	t_shant_stack	*sub_shell;

	if (!redirect)
		return ;
	tmp = ft_redirect_to_ast_node(redirect);
	while (tmp)
	{
		sub_shell = tmp->subshell->top;
		while (sub_shell)
		{
			ft_free_tree(sub_shell->ast_node);
			sub_shell = sub_shell->next;
		}
		ft_free_shant_stack(tmp->subshell);
		tmp_next = tmp->left;
		free(tmp->token);
		free(ft_ast_to_redirect(tmp)->argument);
		free(ft_ast_to_redirect(tmp));
		tmp = tmp_next;
	}
}

void	ft_free_arguments(t_argument *argument)
{
	t_shant_stack	*sub_shell;

	if (!argument)
		return ;
	sub_shell = ft_argument_to_ast_node(argument)->subshell->top;
	while (sub_shell)
	{
		ft_free_tree(sub_shell->ast_node);
		sub_shell = sub_shell->next;
	}
	ft_free_shant_stack(argument->base.subshell);
	ft_vecstrdel(&argument->arguments);
	free(argument->base.token);
	free(argument);
}

void	ft_free_command(t_command *command)
{
	ft_free_redirect(command->redirect);
	ft_free_arguments(command->argument);
	ft_close_command_fd(command->io);
	free(command->base.token);
	free(command);
	command = NULL;
}

void	ft_free_ast_node(t_ast_node **ast_node)
{
	free((*ast_node)->token);
	free(*ast_node);
}

void	ft_free_tree(t_ast_node *tree)
{
	t_ast_node		*tmp_node;
	t_global_stack	*q_node;
	t_shant_stack	*sub_shell;

	q_node = ft_init_shant_stack();
	ft_collect_ast_to_q(tree, q_node);
	while (q_node->size)
	{
		tmp_node = q_node->top->ast_node;
		sub_shell = tmp_node->subshell->top;
		while (sub_shell)
		{
			ft_free_tree(sub_shell->ast_node);
			sub_shell = sub_shell->next;
		}
		ft_free_shant_stack(tmp_node->subshell);
		if (tmp_node->token_type == COMMAND)
			ft_free_command(ft_ast_to_command(tmp_node));
		else
			ft_free_ast_node(&tmp_node);
		ft_pop_shant_stack(q_node);
	}
	ft_free_shant_stack(q_node);
}
