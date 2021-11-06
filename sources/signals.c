/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:47:15 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/04 20:46:49 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	s_quit(int signum)
{
	(void)signum;
	if (g_signal.pid > 0 && !g_signal.heredoc)
	{
		ft_putstr_fd("Quit (core dumped)\n", 1);
		kill(g_signal.pid, SIGINT);
		g_signal.exit_status = 131;
	}
}

void	s_int(int signum)
{
	(void)signum;
	if (g_signal.heredoc && g_signal.pid == 0)
	{
		ft_putstr_fd("\b\b^C\b\b", 1);
		g_signal.exit_status = 1;
		exit(g_signal.exit_status);
	}
	if (g_signal.pid == -1)
	{
		ft_putstr_fd("\b\b\n", 2);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_signal.exit_status = 1;
	}
	else
	{
		ft_putstr_fd("\b\n", 2);
		rl_replace_line("", 0);
		if (g_signal.pid == -1)
			rl_on_new_line();
		rl_redisplay();
		g_signal.exit_status = 130;
	}
}

int	ft_process_signal(t_dict *lcmd)
{
	g_signal.pid = -1;
	signal(SIGINT, s_int);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
