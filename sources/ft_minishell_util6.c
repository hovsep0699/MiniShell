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
	if (ft_strcmp(argum[i], ">>") == 0)
		dict->type_command = DDWRITE;
	else if (ft_strcmp(argum[i], "<<") == 0)
		dict->type_command = DDREAD;
	else if (argum[i][0] == '>')
		dict->type_command = WWRITE;
	else if (argum[i][0] == '<')
		dict->type_command = RREAD;
	if (dict->type_command != DDREAD)
		dict->name_file
			= ft_equal_strjoin(dict->name_file, dict, argum[i + 1], 1);
	else if (dict->type_command != DDWRITE || \
	dict->type_command != WWRITE || dict->type_command != RREAD)
		dict->data
			= ft_equal_strjoin(dict->data, dict, argum[i + 1], 1);
	i += 2;
	return (i);
}

int	ft_write_bu(struct s_dict *dict, char **envp, char **data, int count)
{
	int		fd;
	char	*name_file;

	fd = open(dict->name_file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
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
	int		fd;
	char	c;
	int		ret_int;

	fd = open(dict->name_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		g_signal.exit_status = errno;
		return (g_signal.exit_status);
	}
	while (true)
	{
		ret_int = read(fd, &c, 1);
		if (ret_int == -1)
			return (write_ernno(strerror(errno), errno, fd));
		if (ret_int == 0)
			break ;
		write(1, &c, 1);
	}
	ft_putchar('\n');
	close(fd);
	g_signal.exit_status = 0;
	return (1);
}

int	ft_dwrite_bu(struct s_dict *dict, char **envp, char **data, int count)
{
	int	fd;

	fd = open(dict->name_file, O_CREAT | O_WRONLY | O_APPEND, 0664);
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
	int		id;

	check_str = NULL;
	check_str = ft_strdup(dict->data);
	ft_strdel(&dict->data);
	id = fork();
	signal(SIGQUIT, SIG_IGN);
	g_signal.heredoc = 1;
	g_signal.pid = id;
	if (id == 0)
		ft_dbu_child(check_str);
	else
		waitpid(id, NULL, 0);
	g_signal.heredoc = 0;
	return (1);
}
