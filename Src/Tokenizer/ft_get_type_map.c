/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:37:54 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:17:37 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token_type	ft_get_redirect_type_map(int type)
{
	if (type == MREAD)
		return (READ);
	else if (type == MAPPEND)
		return (APPEND);
	else if (type == MWRITE)
		return (WRITE);
	else if (type == MHEREDOC)
		return (HEREDOC);
	return (NNULL);
}

t_token_type	ft_get_operator_type_map(int type)
{
	if (type == MOR)
		return (OR);
	else if (type == MAND)
		return (AND);
	else if (type == MJOB)
		return (JOB);
	else if (type == MSEMI)
		return (SEMI);
	else if (type == MSEMITWO)
		return (SEMITWO);
	else if (type == MPIPE)
		return (PIPE);
	return (NNULL);
}

t_token_type	ft_get_command_type_map(int type)
{
	if (type == MOPBREK)
		return (OPBREK);
	else if (type == MCLBREK)
		return (CLBREK);
	else if (type == MTEXT)
		return (TEXT);
	return (NNULL);
}

t_token_type	ft_get_type_map(int type)
{
	if (ft_is_redirect_type_map(type))
		return (ft_get_redirect_type_map(type));
	else if (ft_is_operator_type_map(type))
		return (ft_get_operator_type_map(type));
	else if (ft_is_command_type_map(type))
		return (ft_get_command_type_map(type));
	return (NNULL);
}
