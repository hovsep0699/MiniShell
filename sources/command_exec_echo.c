/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:16:26 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/04 20:56:51 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_echo(t_dict *dict, char **envp, char **data, int count)
{
	write(1, dict->data, ft_zero_byte_strlen(dict->data));
	if (dict->echo_option != 1)
		write(1, "\n", 1);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_exit(t_dict *dict, char **envp_my, char **data, int count)
{
	int		exit_status;
	bool	is_error;

	dict->i = 0;
	is_error = false;
	if (!dict->data)
		g_signal.exit_status = 0;
	else
	{
		while (dict->data[dict->i] && ft_isspace(dict->data[dict->i]))
			++dict->i;
		if (!dict->data[dict->i])
			is_error = true;
		else
			is_error = ft_exit_status(dict);
		if (dict->data[dict->i] && !is_error)
			is_error = true;
		if (is_error)
			ft_putcommanderror(dict);
		else
			g_signal.exit_status = ft_atoi(dict->data);
	}
	ft_vecstrdel(&data);
	ft_dict_destructor(dict);
	exit(g_signal.exit_status);
}

int	ft_go_home(t_dict *command_shablon)
{
	int	err;

	if (find_data("HOME", command_shablon->variable_dic) == NULL)
	{
		ft_putstr_fd("Home not found\n", 2);
		g_signal.exit_status = 1;
		return (1);
	}
	err = chdir(find_data("HOME", command_shablon->variable_dic));
	if (err == -1)
	{
		g_signal.exit_status = err;
		ft_putendl_fd(strerror(errno), 2);
		return (errno);
	}
	change_item(find_data("PWD", command_shablon->variable_dic),
		find_data_int("OLDPWD=", command_shablon->variable_dic),
		command_shablon->variable_dic);
	change_item(find_data("HOME", command_shablon->variable_dic),
		find_data_int("PWD=", command_shablon->variable_dic),
		command_shablon->variable_dic);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_cd(t_dict *command_shablon, char **envp, char **data, int count)
{
	int		err;
	int		end;
	char	new_path[PATH_MAX];

	if (!command_shablon->data)
		return (ft_go_home(command_shablon));
	err = chdir(command_shablon->data);
	if (err == -1)
	{
		g_signal.exit_status = err;
		ft_putendl_fd(strerror(errno), 2);
		return (errno);
	}
	getcwd(new_path, PATH_MAX);
	change_item(find_data("PWD", command_shablon->variable_dic),
		find_data_int("OLDPWD=", command_shablon->variable_dic),
		command_shablon->variable_dic);
	change_item(new_path, find_data_int("PWD=", command_shablon->variable_dic),
		command_shablon->variable_dic);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_pwd(t_dict *command_shablon, char **envp_my, char **data, int count)
{
	ft_putstr_fd(find_data("PWD", command_shablon->variable_dic), 1);
	ft_putchar('\n');
	return (0);
}
