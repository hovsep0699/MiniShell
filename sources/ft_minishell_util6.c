/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_util6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:21:25 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/07 13:00:43 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	runfileutil_bu(char **argum, t_dict *dict, int i)
{
	int count;

	count = ft_vecstrlen(argum);
	if (ft_strcmp(argum[i], ">>") == 0)
		dict->type_command = DDWRITE;
	else if (ft_strcmp(argum[i], "<<") == 0)
		dict->fr_command = FDREAD;
	else if (argum[i][0] == '>')
		dict->type_command = WWRITE;
	else if (argum[i][0] == '<')
		dict->fr_command = FREAD;
	if (count > dict->icom + 1 && dict->fr_command != FDREAD)
		dict->fname_file
			= ft_equal_strjoin(dict->fname_file, dict, argum[i + 1], 1);
	else if (count > dict->icom + 1 && (dict->type_command != DDWRITE || \
	dict->type_command != WWRITE || dict->fr_command != FFREAD))
		dict->fname_file
			= ft_equal_strjoin(dict->fname_file, dict, argum[i + 1], 1);
	i += 2;
	return (i);
}

int	ft_write_bu(struct s_dict *dict, char **envp, char **data, int count)
{
	int		fd;
	char	*name_file;

	if(syntax_error(dict->fname_file) == 0)
		return (2);
	fd = open(dict->fname_file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		errno_print(strerror(errno));
		g_signal.exit_status = errno;
		return (g_signal.exit_status);
	}
	close(fd);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_read_bu(struct	s_dict *dict, char **envp, char **data, int count)
{
	int	fd;

	dict->fr_command = FNONE;
	if(syntax_error(dict->fname_file) == 0)
		return (2);
	fd = open(dict->fname_file, O_RDONLY);
	if (dict->fname_file == NULL)
	{
		g_signal.exit_status = 258;
		close(fd);
		return (g_signal.exit_status);
	}
	if (fd == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		g_signal.exit_status = errno;
		return (g_signal.exit_status);
	}
	if ((dup2(fd, STDIN_FILE)) < 0)
		strerror(errno);
	ft_search_side_func(dict)(dict, envp, data, count);
	close(fd);
	ft_fd_open(dict);
	g_signal.exit_status = 0;
	return (1);
}

int	ft_dwrite_bu(struct s_dict *dict, char **envp, char **data, int count)
{
	int	fd;

	if(syntax_error(dict->fname_file) == 0)
		return (2);
	fd = open(dict->fname_file, O_CREAT | O_WRONLY | O_APPEND, 0664);
	if (fd == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		g_signal.exit_status = errno;
		return (g_signal.exit_status);
	}
	close(fd);
	g_signal.exit_status = 0;
	return (1);
}

int	ft_dread_bu(struct s_dict *dict, char **envp, char **data, int count)
{
	char	*check_str;
	int		p[2];
	int		id;

	dict->fr_command = FNONE;
	if(syntax_error(dict->fname_file) == 0)
		return (2);
	check_str = NULL;
	check_str = ft_strdup(dict->fname_file);
	ft_strdel(&dict->fname_file);
	pipe(p);
	id = fork();
	signal(SIGQUIT, SIG_IGN);
	g_signal.heredoc = 1;
	g_signal.pid = id;
	if (id == 0)
		ft_dwrite_child(check_str, p, dict);
	else
		ft_dwrite_parent(id, p);
	g_signal.heredoc = 0;
	if (g_signal.exit_status != 130)
		ft_search_side_func(dict)(dict, envp, data, count);
	ft_fd_open(dict);
	return (1);
}
