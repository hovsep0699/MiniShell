/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_path_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:36:00 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:21 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_is_dir(char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) == 0)
	{
		if (S_ISDIR(path_stat.st_mode))
		{
			g_global_state.is_dir = 1;
			g_global_state.permission_status = 0;
			return (errno);
		}
		return (EXIT_SUCCESS);
	}
	return (errno);
}

char	*ft_get_prefix(char *path, char *path_exec)
{
	char	*prefix;

	prefix = ft_strdup(path);
	prefix = ft_gnl_strjoin(prefix, "/");
	prefix = ft_gnl_strjoin(prefix, path_exec);
	return (prefix);
}

int	ft_find_from_env(char **path, char *path_exec, t_hash_table *env)
{
	int			status;
	char		**paths;
	char		*prefix;
	size_t		i;

	i = 0;
	prefix = NULL;
	status = EXIT_SUCCESS;
	paths = ft_split(ft_get_env(env, "PATH"), ':');
	while (paths[i])
	{
		prefix = ft_get_prefix(paths[i], path_exec);
		status = access(prefix, F_OK | X_OK);
		if (!status)
		{
			free(*path);
			*path = prefix;
			status = EXIT_SUCCESS;
			break ;
		}
		i++;
	}
	ft_vecstrdel(&paths);
	return (status);
}
