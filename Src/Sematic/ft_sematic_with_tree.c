/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sematic_with_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:41:20 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:17:01 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_status_codes	ft_callback(t_status_codes code, \
		t_callback callback, t_ast_node *node)
{
	if (!code)
		return (callback(node));
	return (code);
}

t_status_codes	ft_validate_operator(t_ast_node *node)
{
	if (!node)
		return (SUCCESS_CODE);
	if (!node->left || !node->right)
		return (MISSING_TOKEN);
	return (SUCCESS_CODE);
}

t_status_codes	ft_validate_empty(t_ast_node *node)
{
	if (!node)
		return (SUCCESS_CODE);
	if (!node->left && !node->right)
		return (EMPTY_SUBSHELL);
	return (SUCCESS_CODE);
}

t_status_codes	ft_sematic_with_tree(t_ast_node *root)
{
	t_shant_stack	*node;
	t_status_codes	status;

	status = SUCCESS_CODE;
	if (!root)
		return (SUCCESS_CODE);
	if (root->token_type == ROOT)
		return (ft_sematic_with_tree(root->left));
	if (root->token_type == COMMAND)
		status = ft_callback(status, ft_validate_command, root);
	else if (root->token_type == REDIRECT)
		status = ft_callback(status, ft_validate_redirect, root);
	else if (ft_isoperator(root->token_type))
		status = ft_callback(status, ft_validate_operator, root);
	status = ft_callback(status, ft_validate_subshell, root);
	node = root->subshell->top;
	while (node)
	{
		status = ft_callback(status, ft_validate_empty, node->ast_node);
		status = ft_callback(status, ft_sematic_with_tree, node->ast_node);
		node = node->next;
	}
	status = ft_callback(status, ft_sematic_with_tree, root->left);
	status = ft_callback(status, ft_sematic_with_tree, root->right);
	return (status);
}
