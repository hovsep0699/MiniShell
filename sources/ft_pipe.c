/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:46:14 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/06 16:46:15 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe_close(int fd)
{
	if (fd > 0)
		close(fd);
}

char	*ft_child(char *pipe_l, t_pipe pips, t_dict *dict, char **str)
{
	dup2(pips.fd[0], STDIN_FILENO);
	dict->change_fd_in = pips.fd[0];
	ft_pipe_close(pips.fd[1]);
	if (pips.i == pips.len - 1)
		dict->isparrent = 1;
	else
		dict->isparrent = 0;
	pipe_l = ft_strdup(str[pips.i]);
	ft_vecstrdel(&str);
	ft_pipe_close(pips.fd[0]);
	return (pipe_l);
}

void	ft_first(t_pipe pips, t_dict *dict)
{
	dup2(pips.fd[1], STDOUT_FILENO);
	dict->change_fd_out = pips.fd[1];
	ft_pipe_close(pips.fd[0]);
	dict->isparrent = 0;
	ft_pipe_close(pips.fd[1]);
}

char	*ft_retpipe(char **str, t_pipe pips, char *pipe_line)
{
	pipe_line = ft_strdup(str[pips.i]);
	ft_vecstrdel(&str);
	return (pipe_line);
}

char	*ft_pipe(t_dict *dict, char *data)
{
	char	**str;
	t_pipe	pips;
	char	*pipe_line;
	pid_t	id;

	pips.i = 0;
	str = ft_split_vache(data, '|');
	pips.len = ft_vecstrlen(str);
	if (pips.len <= 1)
		return (ft_retpipe(str, pips, pipe_line));
	pips.i = pips.len;
	while (pips.i > 1)
	{
		pips.i--;
		id = ft_print_error(errno, &pips, str);
		if (id < 0)
			return (NULL);
		if (id > 0)
			return (ft_child(pipe_line, pips, dict, str));
		if (pips.i > 0)
			ft_first(pips, dict);
	}
	pipe_line = ft_strdup(str[0]);
	ft_vecstrdel(&str);
	return (pipe_line);
}
