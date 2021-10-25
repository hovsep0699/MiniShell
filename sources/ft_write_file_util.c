/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_file_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:51:30 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/25 19:24:13 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	only_create_file(char *file_name, struct s_dict *dict)
{
	int	fd;
	int	len;

	dict->name_file = ft_equal_strjoin("", dict, file_name, 1);
	fd = open("", O_CREAT, 0777);
	close(fd);
	return (fd);
}

void	ft_dwrite_child(char *check, int *p)
{
	char	*line;

	ft_pipe_close(p[0]);
	while (true)
	{
		line = readline(">");
		if (ft_strcmp(check, line) == 0)
			break ;
		write(p[1], line, ft_zero_byte_strlen(line));
		write(p[1], "\n", 1);
		ft_strdel(&line);
	}
	ft_strdel(&check);
	ft_strdel(&line);
	ft_pipe_close(p[1]);
	exit(1);
}

void	ft_dwrite_parent(int id, int *p)
{
	ft_pipe_close(p[1]);
	dup2(p[0], STDIN_FILENO);
	waitpid(id, NULL, 0);
}
