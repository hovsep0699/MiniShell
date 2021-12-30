/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:46:59 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/30 15:18:28 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_write_file(struct s_dict *dict, char **envp, char **data, int count)
{
	int		fd;
	mode_t	mode;

	mode = S_IWUSR | S_IRUSR | S_IROTH | S_IRGRP;
	dict->util_commant = NONE;
	if (syntax_error(dict->name_file) == 0)
		return (2);
	if (g_signal.is_read == 1)
		return (0);
	fd = open(dict->name_file, O_CREAT | O_WRONLY | O_TRUNC | O_SYNC, mode);
	if (fd == -1)
	{
		errno_print(strerror(errno));
		g_signal.exit_status = errno;
		return (g_signal.exit_status);
	}
	if ((dup2(fd, STDOUT_FILENO)) < 0)
		errno_print(strerror(errno));
	create_norm_fix_func2(data, dict, count, envp);
	close(fd);
	ft_fd_open(dict);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_read_file(struct	s_dict *dict, char **envp, char **data, int count)
{
	int	fd;

	dict->util_commant = NONE;
	if (syntax_error(dict->name_file) == 0)
		return (2);
	fd = open(dict->name_file, O_RDONLY);
	if (dict->name_file == NULL)
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
	if ((dup2(fd, STDIN_FILENO)) < 0)
		strerror(errno);
	create_norm_fix_func2(data, dict, count, envp);
	close(fd);
	ft_fd_open(dict);
	g_signal.exit_status = 0;
	return (1);
}

int	ft_dwrite_file(struct s_dict *dict, char **envp, char **data, int count)
{
	int		fd;
	mode_t	mode;

	mode = S_IWUSR | S_IRUSR | S_IROTH | S_IRGRP;
	dict->util_commant = NONE;
	if (syntax_error(dict->name_file) == 0)
		return (2);
	fd = open(dict->name_file, O_CREAT | O_WRONLY | O_APPEND | O_SYNC, mode);
	if (fd == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		g_signal.exit_status = errno;
		return (g_signal.exit_status);
	}
	if ((dup2(fd, STDOUT_FILENO)) < 0)
		ft_putendl_fd(strerror(errno), 2);
	create_norm_fix_func2(data, dict, count, envp);
	close(fd);
	ft_fd_open(dict);
	g_signal.exit_status = 0;
	return (1);
}

int	ft_dread_file(struct s_dict *dict, char **envp, char **data, int count)
{
	char	*check_str;
	int		p[2];
	int		id;

	dict->util_commant = NONE;
	if (syntax_error(dict->data) == 0)
		return (2);
	check_str = NULL;
	check_str = ft_strdup(dict->data);
	ft_strdel(&dict->data);
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
		create_norm_fix_func2(data, dict, count, envp);
	ft_fd_open(dict);
	return (1);
}
