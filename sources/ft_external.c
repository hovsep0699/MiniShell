/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_external.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:45:07 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/06 16:54:39 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// for expand macros

/*
static int w_int(int status)
{
	return (*(int *)&(status));
}

static int w_status(int status)
{
	return (w_int(status) & 0177);
}
static bool if_exited(int status)
{
	return (w_status(status) == 0);
}

static int get_exit_status(int status)
{
	return ((w_int(status) >> 8) & 0x000000ff);
}
*/

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
		ind++;
	}
	return (split_path);
}

char	**ft_ret_data(char *data)
{
	char	**data_sp;

	if (data != NULL)
		data_sp = ft_split(data, '\'');
	else
		data_sp = ft_vecstrinit(1);
	return (data_sp);
}

void	ft_exec_abs(t_dict *dic, char **envp, char **data, char **data_sp)
{
	char	**av;
	char	*tmp_path;

	tmp_path = ft_strdup(data[dic->last_command]);
	av = av_ret(tmp_path, data_sp);
	execve(tmp_path, av, envp);
	ft_vecstrdel(&av);
	ft_strdel(&tmp_path);
}

void	ft_ext_child(t_dict *dic, char **envp, char **data)
{
	//printf("dicdata: %s\n", dic->data);
	char	**av;
	char	*tmp_path;
	char	**sp_p;
	char	**data_sp;

	dic->j = 0;
	sp_p = get_path(dic);
	data_sp = ft_ret_data(dic->data);
	ft_exec_abs(dic, envp, data, data_sp);
	while (dic->j < dic->i)
	{
		tmp_path = ft_strdup(sp_p[dic->j]);
		tmp_path = ft_realloc_strjoin(tmp_path, data[dic->last_command]);
		av = av_ret(tmp_path, data_sp);
		execve(tmp_path, av, envp);
		ft_vecstrdel(&av);
		ft_strdel(&tmp_path);
		dic->j++;
	}
	ft_putstr_fd("command not found\n", 2);
	g_signal.exit_status = COMMAND_NOT_FOUND;
	ft_vecstrdel(&sp_p);
	ft_vecstrdel(&av);
	exit(g_signal.exit_status);
}

int	ft_external(t_dict *dict, char **envp, char **data, int count)
{
	int		fd[2];
	pid_t	ret_fork;
	int		i;
	int		status;

//printf("\n%i %i %i %i\n",dict->icom - dict->last_command, dict->icom, dict->last_command,dict->fr_command);
	signal(SIGQUIT, s_quit);
	ret_fork = fork();
	g_signal.pid = ret_fork;
	if (ret_fork < 0)
	{
		ft_putendl_fd(strerror(errno), 2);
		g_signal.exit_status = errno;
		return (errno);
	}
	dict->is_parent = ret_fork;
	if (ret_fork == CHILD_PROC)
		ft_ext_child(dict, envp, data);
	else
		waitpid(ret_fork, &status, 0);
	if (WIFEXITED(status))
		g_signal.exit_status = WEXITSTATUS(status);
	return (g_signal.exit_status);
}
