/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:16:26 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/29 21:58:21 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_echo(t_dict *dict, char **envp, char **data, int count)
{
	(void)envp;
	(void)data;
	(void)count;
	ft_putstr(dict->data);
	if (dict->echo_option != 1)
		ft_putchar('\n');
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_exit(t_dict *dict, char **envp_my, char **data, int count)
{
	int		errnum;

	(void)envp_my;
	(void)count;
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
	create_exit_norm_error(errnum, data, dict);
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
	change_item_dict(find_data("PWD", command_shablon->variable_dic),
		find_data_int("OLDPWD=", command_shablon->variable_dic),
		command_shablon->variable_dic);
	change_item_dict(find_data("HOME", command_shablon->variable_dic),
		find_data_int("PWD=", command_shablon->variable_dic),
		command_shablon->variable_dic);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_cd(t_dict *dict, char **envp, char **data, int count)
{
	int				err;
	char			new_path[PATH_MAX];
	int				ret;

	count = ft_zero_byte_strlen(*data);
	(void)envp;
	if (!dict->data)
		return (ft_go_home(dict));
	ret = create_cd_norm_error(dict);
	if (ret)
		return (1);
	err = chdir(dict->data);
	if (err < 0)
		ft_print_cd(err);
	getcwd(new_path, PATH_MAX);
	change_item_dict(find_data("PWD", dict->variable_dic),
		find_data_int("OLDPWD=", dict->variable_dic),
		dict->variable_dic);
	change_item_dict(new_path, find_data_int("PWD=", dict->variable_dic),
		dict->variable_dic);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_pwd(t_dict *dict, char **envp_my, char **data, int count)
{
	(void)envp_my;
	(void)data;
	(void)count;
	ft_putstr_fd(find_data("PWD", dict->variable_dic), 1);
	ft_putchar('\n');
	return (0);
}
