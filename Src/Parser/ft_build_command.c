/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:47:24 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:16:09 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**ft_get_argument_args(size_t count, t_list_token *list)
{
	char	**args;

	args = NULL;
	if (count)
	{
		args = malloc(sizeof(char *) * (count + 1));
		args[count] = NULL;
		ft_handle_args(list, args);
	}
	return (args);
}

size_t	ft_get_argument_part(t_list_token *lsit)
{
	size_t			i;
	t_token			*token;

	i = 0;
	token = lsit->head;
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
			++i;
		token = token->next;
	}
	return (i);
}

void	ft_handle_argument(t_list_token *lsit, t_command *command)
{
	size_t			count;
	t_ast_node		base;
	t_token			arg;
	char			**args;

	args = NULL;
	count = ft_get_argument_part(lsit);
	if (count)
		args = ft_get_argument_args(count, lsit);
	ft_init_token(&arg, ARGUMENT, ft_strdup("ARGUMENT"));
	ft_init_ast_node(&base, &arg);
	free(arg.token);
	command->argument = ft_create_argument(args, base);
}

void	ft_handle_redirect(t_list_token *list, t_command *command)
{
	t_token				*token;
	t_redirect_side		side;

	token = list->head;
	side = PREV_BRACE;
	while (token && ft_iscommand(token->type))
	{
		if (ft_is_breckets(token->type))
		{
			token = ft_skip_subshell(token);
			if (!token || !ft_iscommand(token->type))
				break ;
			side = NEXT_BRACE;
		}
		if (ft_is_redirection(token->type))
		{
			if (token->next != NULL && token->next->type == TEXT)
				ft_push_redirect(command, token->next->token, \
											token->type, side);
			else
				ft_push_redirect(command, NULL, token->type, side);
		}
		token = token->next;
	}
}

t_command	*ft_handle_command(t_list_token *list)
{
	t_ast_node	base;
	t_token		temp_node;
	t_command	*command;

	ft_init_token(&temp_node, COMMAND, ft_strdup("COMMAND"));
	ft_init_ast_node(&base, &temp_node);
	command = ft_create_command(NULL, NULL, base);
	ft_handle_redirect(list, command);
	ft_handle_subshell(list, command);
	ft_handle_argument(list, command);
	ft_remove_command_redirect(list);
	free(temp_node.token);
	return (command);
}
