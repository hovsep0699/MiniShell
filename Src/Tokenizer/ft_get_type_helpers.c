/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:38:02 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:17:34 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_is_redirect_type_map(int type)
{
	return (type == MREAD || type == MWRITE || \
			type == MAPPEND || type == MHEREDOC);
}

int	ft_is_operator_type_map(int type)
{
	return (type == MOR || type == MAND || type == MJOB || \
		type == MSEMI || type == MSEMITWO || type == MPIPE);
}

int	ft_is_command_type_map(int type)
{
	return (type == MOPBREK || type == MCLBREK || \
								type == MTEXT);
}

int	ft_is_redirect_type(t_token_type type)
{
	return (type == READ || type == WRITE || \
			type == APPEND || type == HEREDOC);
}

int	ft_is_operator_type(t_token_type type)
{
	return (type == OR || type == AND || type == JOB || \
		type == SEMI || type == SEMITWO || type == PIPE);
}
