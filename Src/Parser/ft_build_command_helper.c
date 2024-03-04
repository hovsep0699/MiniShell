/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_command_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:37:21 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:16:05 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_command	*ft_create_command(t_argument *argument, \
				t_redirect *redirect, t_ast_node base)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	command->argument = argument;
	command->redirect = redirect;
	command->base = base;
	command->io = ft_init_io();
	return (command);
}

t_argument	*ft_create_argument(char **argument, t_ast_node base)
{
	t_argument	*command;

	command = malloc(sizeof(t_argument));
	command->arguments = argument;
	command->base = base;
	return (command);
}

t_redirect	*ft_create_redirect(char *file_name, t_ast_node base, \
											t_redirect_side side)
{
	t_redirect	*redirect;

	redirect = (t_redirect *)malloc(sizeof(t_redirect));
	if (file_name != NULL)
		redirect->argument = ft_strdup(file_name);
	else
		redirect->argument = NULL;
	redirect->base = base;
	redirect->side = side;
	return (redirect);
}

void	ft_push_redirect(t_command *command, char *file_name, \
						t_token_type type, t_redirect_side side)
{
	char		*tmp;
	t_token		token;
	t_ast_node	base_node;
	t_ast_node	*tmp_node;
	t_redirect	*new;

	if (!command)
		return ;
	tmp = ft_get_type(type);
	ft_init_token(&token, type, tmp);
	ft_init_ast_node(&base_node, &token);
	free(tmp);
	new = ft_create_redirect(file_name, base_node, side);
	if (command->redirect == NULL)
	{
		command->redirect = new;
		return ;
	}
	tmp_node = ft_redirect_to_ast_node(command->redirect);
	while (tmp_node && tmp_node->left)
		tmp_node = tmp_node->left;
	tmp_node->left = ft_redirect_to_ast_node(new);
	new->base.parent = tmp_node;
}

void	ft_handle_args(t_list_token *list, char **args)
{
	t_token	*token;
	size_t	i;

	i = 0;
	token = list->head;
	while (token && ft_iscommand(token->type))
	{
		if (ft_is_breckets(token->type))
		{
			token = ft_skip_subshell(token);
			if (!token || !ft_iscommand(token->type))
				break ;
		}
		if (token->type == TEXT && (token->prev == NULL || \
			!ft_is_redirection(token->prev->type)))
		{
			args[i] = ft_strdup(token->token);
			++i;
		}
		token = token->next;
	}
}
