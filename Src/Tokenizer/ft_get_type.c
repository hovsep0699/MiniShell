/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:54:37 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:17:39 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_is_command_type(t_token_type type)
{
	return (type == OPBREK || type == CLBREK || \
			type == COMMAND || type == SUBSHELL);
}

char	*ft_get_redirect_type(t_token_type type)
{
	if (type == READ)
		return (ft_strdup("<"));
	else if (type == APPEND)
		return (ft_strdup(">>"));
	else if (type == WRITE)
		return (ft_strdup(">"));
	else if (type == HEREDOC)
		return (ft_strdup("<<"));
	return (ft_strdup("Unknown"));
}

char	*ft_get_operator_type(t_token_type type)
{
	if (type == OR)
		return (ft_strdup("||"));
	else if (type == AND)
		return (ft_strdup("&&"));
	else if (type == JOB)
		return (ft_strdup("&"));
	else if (type == SEMI)
		return (ft_strdup(";"));
	else if (type == SEMITWO)
		return (ft_strdup(";;"));
	else if (type == PIPE)
		return (ft_strdup("|"));
	return (ft_strdup("Unknown"));
}

char	*ft_get_command_type(t_token_type type)
{
	if (type == OPBREK)
		return (ft_strdup("("));
	else if (type == CLBREK)
		return (ft_strdup(")"));
	else if (type == SUBSHELL)
		return (ft_strdup("SubShell"));
	else if (type == COMMAND)
		return (ft_strdup("Command"));
	return (ft_strdup("Unknown"));
}

char	*ft_get_type(t_token_type type)
{
	if (ft_is_redirect_type(type))
		return (ft_get_redirect_type(type));
	else if (ft_is_operator_type(type))
		return (ft_get_operator_type(type));
	else if (ft_is_command_type(type))
		return (ft_get_command_type(type));
	return (ft_strdup("Unknown"));
}
