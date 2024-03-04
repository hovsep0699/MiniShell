/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:34:58 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:15 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_restore_and_close(int here_fd, int stdio)
{
	dup2(stdio, STDIN_FILENO);
	rl_redisplay();
	close(stdio);
	close(here_fd);
}

int	ft_isquot(const char *end_of_file)
{
	if ((end_of_file && *end_of_file) && \
		(ft_strchr((char *)end_of_file, '\"') || \
		ft_strchr((char *)end_of_file, '\'')))
		return (1);
	else
		return (0);
}

size_t	ft_eof_length(char *end_of_file)
{
	size_t	i;
	size_t	eof_size;
	char	crrent;

	i = 0;
	eof_size = 0;
	while (end_of_file && end_of_file[i])
	{
		if (end_of_file[i] == '\'' || end_of_file[i] == '\"')
		{
			crrent = end_of_file[i++];
			while (end_of_file[i] != crrent)
			{
				++eof_size;
				++i;
			}
			if (end_of_file[i] == '\'' || end_of_file[i] == '\"')
				i++;
			continue ;
		}
		++eof_size;
		i++;
	}
	return (eof_size);
}

char	*ft_ignor_eof_quots(char *end_of_file)
{
	size_t	eof_size;
	char	*eof_key;

	eof_size = ft_eof_length(end_of_file);
	eof_key = (char *)malloc(sizeof(char) * (eof_size + 1));
	if (!eof_key)
		return (NULL);
	ft_fill_eof_str(end_of_file, eof_key);
	return (eof_key);
}

char	*ft_substr_c(char *line, char c)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	while (line && line[i] && line[i] != c)
		++i;
	start = i;
	if (line[i])
		++i;
	while (line && line[i] && line[i] != c && \
		!ft_isspace(line[i]) && line[i] != '\'' && \
		line[i] != '\"')
		++i;
	return (ft_substr(line, start, i - start));
}
