/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_util3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:45:56 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/07 12:39:38 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_command_dict(char *lcase, char *ucase, t_dict *dict, char **list)
{
	if (ft_strcmp(lcase, "echo") == 0)
		dict->type_command = ECHO;
	else if (ft_strcmp(lcase, "pwd") == 0)
		dict->type_command = PWD;
	else if (ft_strcmp(lcase, "env") == 0)
		dict->type_command = ENV;
	else if (ft_strcmp(ucase, "exit") == 0)
		dict->type_command = EXIT;
	else if (ft_strcmp(lcase, "export") == 0)
		dict->type_command = EXPORT;
	else if (ft_strcmp(lcase, "unset") == 0)
		dict->type_command = UNSET;
	else if (ft_strcmp(lcase, "cd") == 0)
		dict->type_command = CD;
	else if ((!ft_strcmp(lcase, ">>")
			|| !ft_strcmp(lcase, "<<")
			|| !ft_strcmp(lcase, ">") || !ft_strcmp(lcase, "<")))
		dict->icom = runfileutil_bu(list, dict, dict->icom) - 1;
	else
		dict->type_command = UNDEFINED;
}

int	ft_exit_status(t_dict *dict)
{
	dict->i = ft_set_index(dict->data, dict->i);
	// printf("test i %c\n",dict->data[dict->i]);
	// printf("hello\n");
	printf("exit\n");
	if (!ft_isdigit(dict->data[dict->i - 1]))
		return 1;
	if (dict->data[dict->i] || dict->i != ft_zero_byte_strlen(dict->data))
		return (2);
	while (dict->data[++dict->i])
		if (ft_isspace(dict->data[dict->i]))
			break ;
	return (0);
}

void	ft_putcommanderror(t_dict *dict, int errnum)
{
	ft_putstr_fd("minishell: exit: ", 2);
	if (errnum == 1)
	{
		ft_putstr_fd(dict->data, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
	}
	else
		ft_putstr_fd("too many arguments\n", 2);
	g_signal.exit_status = COMMAND_NOT_FOUND;
}

int	ft_dict_init(t_dict *dict, int end_index, char *str)
{
	t_dictionary	*tmp;

	if (export_check(str, ft_strlen(str)) || str[0] == '=')
	{
		ft_putstr_fd("Not a valid identifier\n", 2);
		return (++end_index);
	}
	dict->i = find_data_int(str, dict->variable_dic);
	if (dict->i == -1)
	{
		tmp = ft_dictionary_create(str);
		if (tmp == NULL)
		{
			tmp = NULL;
			end_index++;
			return (end_index);
		}
		ft_dictionaryadd_back(&(dict->variable_dic), tmp);
	}
	else
		change_item(str, dict->i, dict->variable_dic);
	tmp = NULL;
	end_index++;
	return (end_index);
}
