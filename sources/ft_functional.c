/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:45:24 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/24 12:45:25 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_func	ft_search_builtin_func(t_dict *lcmd)
{
	int	index;

	index = -1;
	while (++index < MAX_BUILTIN_FUNCS)
	{
		if (lcmd->type_command == lcmd->functions[index].name)
			return (lcmd->functions[index].function);
	}
	return (NULL);
}

t_cmd_func	ft_search_side_func(t_dict *lcmd)
{
	int	index;

	index = -1;
	while (++index < MAX_SIDE_FUNCS)
	{
		if (lcmd->util_commant == lcmd->side_functions[index].name
			&& lcmd->util_commant != NONE)
			return (lcmd->side_functions[index].function);
	}
	return (ft_search_builtin_func(lcmd));
}
