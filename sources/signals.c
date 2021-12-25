/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:47:15 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/06 20:06:39 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	s_quit(int signum)
{
	(void)signum;
	if (g_signal.pid > 0 && !g_signal.heredoc)
	{
		printf("Quit (core dumped)\n");
		// ft_putstr_fd("Quit (core dumped)\n", 1);
		kill(g_signal.pid, SIGINT);
		g_signal.exit_status = 131;
	}
}

void	s_int(int signum)
{
	(void)signum;
	// printf("test: %x           \n\n", *rl_line_buffer);
	char *copy = ft_strdup(rl_line_buffer);
	if (g_signal.heredoc && g_signal.pid == 0)
	{
		printf(TEXT_GREEN);
		printf("\b\b^C\b\b");
		// ft_putstr_fd("\b\b^C\b\b", 1);
		g_signal.exit_status = 1;
		exit(g_signal.exit_status);
	}
	if (g_signal.pid == -1)
	{
		printf(TEXT_GREEN);
		if (*rl_line_buffer)
			printf("\b\b\n");
		// ft_putstr_fd("\b\b\n", 2);
		// printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		if (!*copy)
		{
			// printf("here\n");
			printf("  \b\b");
			printf("\n");
			printf(TEXT_GREEN);
			printf("Minishell$> ");
			printf(TEXT_WHITE);
		}
		// printf("Minishell$> ");
		// printf("hi\n");
		g_signal.exit_status = 1;
	}
	else
	{
		printf(TEXT_GREEN);
		printf("\b\n");
		// ft_putstr_fd("\b\n", 2);
		rl_replace_line("", 0);
		if (g_signal.pid == -1)
			rl_on_new_line();
		rl_redisplay();
		g_signal.exit_status = 130;
	}
	ft_strdel(&copy);
}

int	ft_process_signal(t_dict *lcmd)
{
	g_signal.pid = -1;
	signal(SIGINT, s_int);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}

int	ft_print_error(int errnum, t_pipe *pips, char **str)
{
	int	id;
	int	pip_ret;

	pip_ret = pipe(pips->fd);
	id = fork();
	if (id < 0 || pip_ret < 0)
	{
		ft_putendl_fd(strerror(errno), 2);
		g_signal.exit_status = errno;
		ft_vecstrdel(&str);
		return (-1);
	}
	return (id);
}

int	ft_iszero(int end, int count)
{
	if (end == 0)
		return (count);
	else
		return (end);
}
