/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:28:23 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:18 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_fill_eof_str(char *end_of_file, char *eof_key)
{
	size_t	i;
	size_t	j;
	char	current;

	i = 0;
	j = 0;
	while (end_of_file && end_of_file[i])
	{
		if (end_of_file[i] == '\'' || end_of_file[i] == '\"')
		{
			current = end_of_file[i++];
			while (end_of_file[i] != current)
				eof_key[j++] = end_of_file[i++];
			if (end_of_file[i] == '\'' || end_of_file[i] == '\"')
				i++;
			continue ;
		}
		eof_key[j++] = end_of_file[i];
		i++;
	}
	eof_key[j++] = '\0';
}

void	ft_hendle_env_variable(char **line, t_hash_table *env)
{
	char	dellim;
	char	*start_env;
	char	*token_env;
	char	*value;

	dellim = '$';
	token_env = NULL;
	start_env = ft_strchr(*line, dellim);
	while (start_env)
	{
		token_env = ft_substr_c(start_env, dellim);
		if (!*token_env)
			value = ft_get_env(env, token_env);
		else
			value = ft_get_env(env, token_env + 1);
		if (value)
			ft_replace_all(line, token_env, value);
		if (*start_env)
			start_env = ft_strchr(start_env + 1, dellim);
		else
			start_env = NULL;
	}
}

void	ft_handle_eof(size_t i, char *end_of_file)
{
	if (g_global_state.heredoc_signal == -1)
	{
		ft_putstr_fd("minishell: warning: here-document at line ", \
						STDOUT_FILENO);
		ft_putnbr_fd(i, STDOUT_FILENO);
		ft_putstr_fd(" delimited by end-of-file: (wanted `", STDOUT_FILENO);
		ft_putstr_fd(end_of_file, STDOUT_FILENO);
		ft_putendl_fd("')", STDOUT_FILENO);
	}
}

void	ft_handle_heredoc(int here_fd, char *end_of_file, \
							t_hash_table *env, int flag)
{
	char	*line;
	int		stdio;
	size_t	i;

	i = 1;
	stdio = dup(STDIN_FILENO);
	signal(SIGINT, ft_heredoc_signal);
	while (1)
	{
		line = readline(">");
		if (!line)
		{
			ft_handle_eof(i, end_of_file);
			break ;
		}
		if (!ft_strcmp(line, end_of_file))
			break ;
		if (!flag)
			ft_hendle_env_variable(&line, env);
		ft_putstr_fd(line, here_fd);
		ft_putstr_fd("\n", here_fd);
		free(line);
		++i;
	}
	ft_restore_and_close(here_fd, stdio);
}

int	ft_open_heredoc(t_redirect	*red, t_hash_table *env)
{
	int		here_fd;
	int		flag;
	char	*filename;
	char	*end_of_file;

	flag = 0;
	filename = ft_generate_filename();
	here_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
	end_of_file = ft_ignor_eof_quots(red->argument);
	signal(SIGINT, ft_heredoc_signal);
	signal(SIGQUIT, SIG_IGN);
	if (ft_isquot(red->argument))
		flag = 1;
	ft_handle_heredoc(here_fd, end_of_file, env, flag);
	if (g_global_state.heredoc_signal == -1)
		here_fd = open(filename, O_RDONLY, 0666);
	else
		here_fd = -1;
	free(end_of_file);
	unlink(filename);
	free(filename);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, ft_sigquit_handler);
	return (here_fd);
}
