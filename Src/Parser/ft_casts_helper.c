/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casts_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 03:51:28 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:16:11 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_command	*ft_ast_to_command(t_ast_node *ast)
{
	return ((t_command *)ast);
}

t_argument	*ft_ast_to_argument(t_ast_node *ast)
{
	return ((t_argument *)ast);
}

t_redirect	*ft_ast_to_redirect(t_ast_node *ast)
{
	return ((t_redirect *)ast);
}
