/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:52:35 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:50 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_global_tree	*ft_init_ast_tree(void)
{
	t_global_tree	*tree;

	tree = (t_global_tree *)malloc(sizeof(t_global_tree));
	if (!tree)
		return (NULL);
	tree->ast_node = NULL;
	tree->tree_size = 0;
	return (tree);
}

t_ast_node	*ft_create_ast_node(t_token *token)
{
	t_ast_node	*new_node;

	new_node = (t_ast_node *)malloc(sizeof(t_ast_node));
	if (!new_node)
		return (NULL);
	new_node->token_type = token->type;
	new_node->parent = NULL;
	new_node->token = ft_strdup(token->token);
	new_node->quate_type = 0;
	new_node->left = NULL;
	new_node->subshell = ft_init_shant_stack();
	new_node->right = NULL;
	return (new_node);
}

size_t	ft_ast_len(t_ast_node *root)
{
	size_t	left;
	size_t	right;

	if (!root)
		return (0);
	left = 0;
	right = 0;
	left = ft_ast_len(root->left);
	right = ft_ast_len(root->right);
	return (left + right + 1);
}

void	ft_init_ast_node(t_ast_node *node, t_token *token)
{
	if (!node)
		return ;
	node->token_type = token->type;
	node->parent = NULL;
	node->token = ft_strdup(token->token);
	node->quate_type = 0;
	node->left = NULL;
	node->subshell = ft_init_shant_stack();
	node->right = NULL;
}

char	*ft_ast_strjoin(char *s1, char *s2)
{
	char		*new_str;
	size_t		f_index;
	size_t		s_index;

	f_index = 0;
	s_index = 0;
	new_str = (char *)malloc(sizeof(char) * \
			(ft_gnl_strlen(s1) + (ft_gnl_strlen(s2) + 1)));
	if (!new_str)
		return (NULL);
	if (s1)
		while (s1[f_index])
			new_str[s_index++] = s1[f_index++];
	f_index = 0;
	if (s2)
		while (s2[f_index])
			new_str[s_index++] = s2[f_index++];
	new_str[s_index] = '\0';
	return (new_str);
}
