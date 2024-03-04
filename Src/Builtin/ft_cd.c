/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:49:00 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:13:42 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_cd_home(t_hash_table *env)
{
	char	*dest;

	dest = ft_get_env(env, "HOME");
	if (!dest)
	{
		ft_putendl_fd("cd: HOME is not set", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (chdir(dest) < 0)
	{
		perror("cd: ");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_cd_oldpwd(char *argument, t_hash_table *env)
{
	char	*dest;

	if (argument[1] == '\0')
	{
		dest = ft_get_env(env, "OLDPWD");
		if (!dest)
		{
			ft_putendl_fd("cd: OLDPWD is not set", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		else if (chdir(dest) < 0)
		{
			perror("cd: ");
			return (EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(argument, STDERR_FILENO);
		ft_putendl_fd(": invalid option", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_handle_cd_arguments(char *argument, t_hash_table *env)
{
	if (!argument)
		return (ft_cd_home(env));
	else if (argument[0] == '-')
		return (ft_cd_oldpwd(argument, env));
	else if (chdir(argument) < 0)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(argument, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_cd(t_command *command, t_symbol_table *table)
{
	char	*cwd;
	char	*oldcwd;

	oldcwd = getcwd(NULL, 0);
	if (command->argument && command->argument->arguments && \
		command->argument->arguments[0])
	{
		if (command->argument->arguments[1] && command->argument->arguments[2])
		{
			ft_putendl_fd("cd: too many arguments", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		if (ft_handle_cd_arguments(command->argument->arguments[1], table->env))
			return (EXIT_FAILURE);
	}
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("cd: ");
		return (errno);
	}
	ft_set_env(table->env, (t_hash_data){"OLDPWD", oldcwd, NORMAL});
	ft_set_env(table->env, (t_hash_data){"PWD", cwd, NORMAL});
	return (EXIT_SUCCESS);
}
