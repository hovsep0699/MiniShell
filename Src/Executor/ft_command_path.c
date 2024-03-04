/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:28:01 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:24 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_is_relative_or_abs(char *path, char *path_exec)
{
	int	status;

	status = EXIT_SUCCESS;
	if (ft_is_dir(path))
		return (errno);
	status = access (path_exec, F_OK);
	if (status == -1)
	{
		g_global_state.permission_status = errno;
		return (errno);
	}
	status = access (path_exec, X_OK);
	if (status == -1)
	{
		g_global_state.permission_status = errno;
		return (errno);
	}
	return (EXIT_SUCCESS);
}

int	ft_search_path_dispatch(char *path_exec, t_command *command, \
							t_hash_table *env)
{
	if (path_exec[0] == '/')
		return (ft_is_relative_or_abs(command->argument->arguments[0], \
										path_exec + 1));
	else if (!ft_strncmp(path_exec, "./", 2))
		return (ft_is_relative_or_abs(command->argument->arguments[0], \
										path_exec + 2));
	else if (!ft_strncmp(path_exec, "../", 3))
		return (ft_is_relative_or_abs(command->argument->arguments[0], \
										path_exec + 3));
	return (ft_find_from_env(&command->argument->arguments[0], \
										path_exec, env));
}

int	ft_command_path(t_command *command, t_hash_table *env)
{
	char	*path_exec;
	int		status;

	status = EXIT_SUCCESS;
	path_exec = ft_strdup(command->argument->arguments[0]);
	status = ft_search_path_dispatch(path_exec, command, env);
	free(path_exec);
	if (ft_is_dir(command->argument->arguments[0]))
		return (errno);
	if (status)
	{
		g_global_state.permission_status = errno;
		return (errno);
	}
	return (EXIT_SUCCESS);
}

int	ft_variable_identifier(char *ident)
{
	int	i;

	i = 1;
	if (!ident[i] || ident[i] == '\"' || ident[i] == '\'')
		return (0);
	if (ft_isdigit(ident[i]))
		return (0);
	while (ident && ident[i])
	{
		if (!(ft_isalnum(ident[i]) || ident[i] == '_'))
			return (0);
		++i;
	}
	return (1);
}
