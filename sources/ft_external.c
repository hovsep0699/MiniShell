/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_external.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:45:07 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/24 13:45:31 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(t_dict *dictioanry)
{
	char	**split_path;
	char	*path;
	int		ind;

	ind = 0;
	path = find_data("PATH", dictioanry->variable_dic);
	split_path = ft_strsplit(path, ':');
	dictioanry->i = ft_vecstrlen(split_path);
	while (ind < dictioanry->i)
	{
		split_path[ind] = ft_realloc_strjoin(split_path[ind], "/");
		dictioanry->i++;
	}
	return (split_path);
}

void	ft_ext_child(t_dict *dictioanry, char **envp, char **data)
{
	int		j;
	char	**av;
	char	*tmp_path;
	char	**sp_p;

	j = 0;
	sp_p = get_path(dictioanry);
	av = ft_vecstrinit(3);
	while (j < dictioanry->i)
	{
		tmp_path = ft_strdup(sp_p[j]);
		tmp_path = ft_realloc_strjoin(tmp_path, data[dictioanry->last_command]);
		ft_strdel(&av[0]);
		ft_strdel(&av[1]);
		av[0] = ft_strdup(tmp_path);
		av[1] = ft_strdup(dictioanry->data);
		execve(tmp_path, av, envp);
		j++;
	}
	ft_putstr_fd("asd: command not found\n", 2);
	g_signal.exit_status = COMMAND_NOT_FOUND;
	ft_vecstrdel(&sp_p);
	ft_vecstrdel(&av);
	exit(g_signal.exit_status);
}

int	ft_external(t_dict *dictioanry, char **envp, char **data, int count)
{
	int		fd[2];
	pid_t	ret_fork;
	int		i;

	signal(SIGQUIT, s_quit);
	ret_fork = fork();
	g_signal.pid = ret_fork;
	dictioanry->is_parent = ret_fork;
	if (ret_fork == CHILD_PROC)
		ft_ext_child(dictioanry, envp, data);
	else
	{
		waitpid(ret_fork, NULL, 0);
		g_signal.exit_status = errno;
	}
	return (g_signal.exit_status);
}
