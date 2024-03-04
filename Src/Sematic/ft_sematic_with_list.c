/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sematic_with_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:39:37 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:16:58 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_status_codes	ft_sematic_with_list(t_command *cmd)
{
	return (ft_validate_command(ft_command_to_ast_node(cmd)));
}
