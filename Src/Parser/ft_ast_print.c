/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:12:18 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:16:02 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
/*
void	print_redirect(t_ast_node *redirect)
{
	t_redirect		*red;

	red = ft_ast_to_redirect(redirect);
	printf("REDIRECT { type: %d, token: %s, arg: %s", \
		redirect->token_type, redirect->token, red->argument);
}

void	print_argument(t_ast_node	*arg)
{
	size_t		i;
	t_argument	*argument;

	argument = ft_ast_to_argument(arg);
	printf("ARGUMENT { type: %d, token: %s", arg->token_type, arg->token);
	printf(", args = [ ");
	if (!argument->arguments || !argument->arguments[0])
		printf("null");
	else
	{
		i = 0;
		while (argument->arguments && argument->arguments[i])
		{
			printf("%s", argument->arguments[i]);
			++i;
			if (argument->arguments[i])
				printf(", ");
		}
	}
	printf(" ]");
}

void	print_command(t_ast_node *command, \
	char *prefix, int is_root, int is_left)
{
	char			*str;
	t_command		*cmd;
	t_ast_node		*args;
	t_ast_node		*red;
	t_shant_stack	*node;

	cmd = ft_ast_to_command(command);
	printf("COMMAND { type: %d, token: %s, fds: [in: %d, out: %d, err: %d]", \
		command->token_type, command->token, cmd->io.input, \
		cmd->io.output, cmd->io.error);
	args = ft_argument_to_ast_node(cmd->argument);
	red = ft_redirect_to_ast_node(cmd->redirect);
	if (is_root == 0)
	{
		if (is_left)
			printf(", L");
		else
			printf(", R");
	}
	printf(" } \n");
	char *str;
	if (is_left)
		str = ft_ast_strjoin(prefix, "│      ");
	else
		str = ft_ast_strjoin(prefix, "       ");
	node = cmd->base.subshell->top;
	while (node)
	{
		ft_ast_print(node->ast_node, str, 1, 0);
		node = node->next;
	}
	ft_ast_print(args, str, 1, 0);
	ft_ast_print(red, str, 0, 0);
	free(str);
}

void print_node_type(t_ast_node* node, char *prefix, int is_root, int is_left)
{
	switch (node->token_type)
	{
	case COMMAND:
		print_command(node, prefix, is_root, is_left);
		break;
	case ARGUMENT:
		print_argument(node);
		break;
	case REDIRECT:
		print_redirect(node);
		break;
	default:
		printf("AST_NODE { type: %d, token: %s", node->token_type, node->token);
		break;
	}
}

void ft_ast_print(t_ast_node *head, char *prefix, int is_left, int is_root)
{
	if (head != NULL)
	{
		printf("%s│\n%s", prefix, prefix);
		if (is_left || is_root)
		{
			printf("├───");
		}
		else
			printf("└───");
		print_node_type(head, prefix, is_root, is_left);
		if (head->token_type == COMMAND)
		{
			return;
		}
		if ( is_root == 0 )
		{
			if (is_left)
				printf(", L");
			else
				printf(", R");
		}
		printf(" } \n");
		char *str;
		if (is_left)
			str = ft_ast_strjoin(prefix, "│      ");
		else
			str = ft_ast_strjoin(prefix, "       ");
		
		t_shant_stack* node = head->subshell->top;
		while (node)
		{
			ft_ast_print(node->ast_node, str, 1, 0);
			node = node->next;
		}
		ft_ast_print(head->left, str, 1, 0);
		ft_ast_print(head->right, str, 0, 0);
		free(str);
	}
	else
	{
		printf("%s", prefix);
		if (is_left || is_root)
			printf("├───");
		else
			printf("└───");
		printf("AST_NODE { NULL");
		if ( is_root == 0 )
		{
			if (is_left)
				printf(", L");
			else
				printf(", R");
		}
		printf(" } \n");
	}
}
*/