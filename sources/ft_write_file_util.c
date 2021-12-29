/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_file_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:51:30 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/29 19:05:34 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	only_create_file(struct s_dict *dict)
{
	int	fd;

	if (dict->util_commant == DWRITE)
		fd = open(dict->name_file, O_CREAT, 0664);
	if (dict->util_commant == WRITE)
	{
		fd = open(dict->name_file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
		write(fd, "\0", 1);
	}
	ft_strdel(&dict->name_file);
	close(fd);
	return (fd);
}

void	ft_dwrite_child(char *check, int *p, t_dict *dict)
{
	char	*line;
	char	**chek_str;
	t_write	count_i;

	count_i.i = 0;
	ft_pipe_close(p[0]);
	chek_str = ft_split(check, '\n');
	count_i.count = ft_vecstrlen(chek_str);
	while (count_i.i < count_i.count)
	{
		while (true)
		{
			line = readline(">");
			if (ft_isnull(line, 1))
				continue ;
			line = ft_here_strjoin(line, dict);
			if (ft_strcmp(chek_str[count_i.i], line) == 0)
				break ;
			if (count_i.i + 1 == count_i.count)
				ft_norm_write_close(p[1], line);
			ft_strdel(&line);
		}
		count_i.i++;
	}
	ft_clean_dwrite(check, line, chek_str, p[1]);
}

void	ft_dwrite_parent(int id, int *p)
{
	ft_pipe_close(p[1]);
	dup2(p[0], STDIN_FILENO);
	waitpid(id, NULL, 0);
}
