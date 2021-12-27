/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:06:56 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/07 13:02:47 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	write_ernno(char *str_errno, int errno_cod, int fd)
{
	errno_print(str_errno);
	g_signal.exit_status = errno_cod;
	close(fd);
	return (errno_cod);
}

void	ft_dbu_child(char *check)
{
	char	*line;
	char	*newchar;

	newchar = NULL;
	while (true)
	{
		line = readline(">");
		if (ft_isnull(line, 1))
			continue ;
		if (ft_strcmp(check, line) == 0)
			break ;
		newchar = ft_realloc_strjoin(newchar, line);
		newchar = ft_realloc_strjoin(newchar, "\n");
		ft_strdel(&line);
	}
	ft_strdel(&check);
	ft_strdel(&line);
	ft_strdel(&newchar);
	exit(0);
}

void	ft_dbu_parent(int id, int *p)
{
	waitpid(id, NULL, 0);
}
