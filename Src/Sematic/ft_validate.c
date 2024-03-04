/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:08:58 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:17:09 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_status_codes	ft_validate_command(t_ast_node *node)
{
	t_command		*cmd;
	t_redirect		*redirect;
	t_argument		*argument;
	t_ast_node		*reds;
	t_status_codes	status;

	if (!node)
		return (SUCCESS_CODE);
	status = SUCCESS_CODE;
	cmd = ft_ast_to_command(node);
	redirect = cmd->redirect;
	argument = cmd->argument;
	if (argument && argument->arguments && cmd->base.subshell->size)
		return (MISSING_OPERATOR);
	if (redirect && redirect->side == PREV_BRACE && cmd->base.subshell->size)
		return (MISSING_OPERATOR);
	reds = &redirect->base;
	while (reds)
	{
		status = ft_callback(status, ft_validate_redirect, reds);
		reds = reds->left;
	}
	return (status);
}

t_status_codes	ft_validate_redirect(t_ast_node *node)
{
	t_redirect	*redirect;

	if (!node)
		return (SUCCESS_CODE);
	redirect = ft_ast_to_redirect(node);
	if (!redirect->argument)
		return (UNEXPECTED_REDIRECT);
	return (SUCCESS_CODE);
}

t_status_codes	ft_validate_subshell(t_ast_node *node)
{
	if (!node)
		return (SUCCESS_CODE);
	if (node->subshell->size > 1)
		return (MISSING_OPERATOR);
	return (SUCCESS_CODE);
}
