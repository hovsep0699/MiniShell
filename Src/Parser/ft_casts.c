/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:46:03 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:16:14 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_ast_node	*ft_command_to_ast_node(t_command *cmd)
{
	return ((t_ast_node *)cmd);
}

t_ast_node	*ft_redirect_to_ast_node(t_redirect *rd)
{
	return ((t_ast_node *)rd);
}

t_ast_node	*ft_argument_to_ast_node(t_argument *arg)
{
	return ((t_ast_node *)arg);
}
