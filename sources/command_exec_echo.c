/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:16:26 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/06 15:51:39 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_echo(t_dict *dict, char **envp, char **data, int count)
{
	// printf("%s", dict->data);
	ft_putstr(dict->data);
	if (dict->echo_option != 1)
		printf("\n");
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_exit(t_dict *dict, char **envp_my, char **data, int count)
{
	int		exit_status;
	int		errnum;

	// dup2(STDIN_FILENO, dict->fd[0]);
	// close(dict->fd[0]);
	// dup2(STDOUT_FILENO, dict->fd[1]);
	// close(dict->fd[1]);
	printf("exit\n");
	dict->i = 0;
	errnum = 0;
	if (!dict->data)
		g_signal.exit_status = 0;
	else
	{
		while (dict->data[dict->i] && ft_isspace(dict->data[dict->i]))
			++dict->i;
		errnum = ft_exit_status(dict);
		if (dict->data[dict->i] && !errnum)
			errnum = 1;
		if (errnum)
			ft_putcommanderror(dict, errnum);
		else
			g_signal.exit_status = ft_atoi(dict->data);
	}
	if (errnum < 2)
	{
		ft_vecstrdel(&data);
		ft_dict_destructor(dict);
		while (ft_range(g_signal.exit_status, 0, 255))
		{
			if (g_signal.exit_status < 0)
				g_signal.exit_status += 256;
			else
				g_signal.exit_status -= 256;
		}
		exit (g_signal.exit_status);
	}
	g_signal.exit_status = 1;
	return (1);
}

int	ft_go_home(t_dict *command_shablon)
{
	int	err;

	if (find_data("HOME", command_shablon->variable_dic) == NULL)
	{
		ft_putstr_fd("sh: Home not found\n", 2);
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

int	ft_cd(t_dict *dict, char **envp, char **data, int count)
{
	int		err;
	int		end;
	char	new_path[PATH_MAX];
	DIR		*current_directory;
	struct dirent *dp;

	if (!dict->data)
		return (ft_go_home(dict));
	if (dict->data[0] == '-' && ft_ret_end(dict) == 0)
		return (1);
	dict->data = ft_strtrim(dict->data, " ");
	dict->data = ft_realloc_strjoin(dict->data, "/");
	current_directory = opendir(dict->data);
	if (!current_directory)
	{
		g_signal.exit_status = 1;
		ft_putendl_fd("sh: cd: No such file or directory", 2);
		return (1);
	}
	dp = readdir(current_directory);
	if (!dp)
	{
		g_signal.exit_status = 1;
		ft_putendl_fd("sh: cd: No such file or directory", 2);
		return (1);
	}
	err = chdir(dict->data);
	if (err < 0)
	{
		g_signal.exit_status = err;
		ft_putendl_fd(strerror(errno), 2);
		return (errno);
	}
	getcwd(new_path, PATH_MAX);
	change_item(find_data("PWD", dict->variable_dic),
		find_data_int("OLDPWD=", dict->variable_dic),
		dict->variable_dic);
	change_item(new_path, find_data_int("PWD=", dict->variable_dic),
		dict->variable_dic);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_pwd(t_dict *dict, char **envp_my, char **data, int count)
{
	ft_putstr_fd(find_data("PWD", dict->variable_dic), 1);
	ft_putchar('\n');
	return (0);
}
