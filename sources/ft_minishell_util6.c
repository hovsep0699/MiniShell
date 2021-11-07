/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_util6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:21:25 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/07 11:41:29 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	runfileutil_bu(char **argum, t_dict *dict, int i)
{
	if (ft_strcmp(argum[i], ">>") == 0)
		dict->type_command = DDWRITE;
	else if (ft_strcmp(argum[i], "<<") == 0)
		dict->type_command = DDREAD;
	else if (argum[i][0] == '>')
		dict->type_command = WWRITE;
	else if (argum[i][0] == '<')
		dict->type_command = RREAD;
	if (dict->type_command != DDREAD)
		dict->name_file
			= ft_equal_strjoin(dict->name_file, dict, argum[i + 1], 1);
	else if (dict->type_command == DDWRITE || \
	dict->type_command == WWRITE || dict->type_command == RREAD)
		dict->data
			= ft_equal_strjoin(dict->data, dict, argum[i + 1], 1);
	i += 2;
	return (i);
}
