/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:00:08 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:29 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sigint_handler(int signum)
{
	(void)signum;
	if (g_global_state.minishell_signal == SIGNORMAL)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_sigquit_handler(int signum)
{
	(void)signum;
	if (g_global_state.minishell_signal == SIGCHILD)
	{
		rl_replace_line("", 0);
		rl_done = 1;
	}
}

void	ft_child_sigint(int num)
{
	(void)num;
	if (g_global_state.heredoc_signal == -1)
	{
		if (num == SIGQUIT)
			ft_putstr_fd("Quit", STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		rl_on_new_line();
	}
}

void	ft_heredoc_signal(int num)
{
	if (num == SIGINT)
	{
		g_global_state.heredoc_signal = num;
		g_global_state.minishell_signal = SIGHEREDOC;
		rl_catch_signals = 0;
		ft_putstr_fd("\n", STDERR_FILENO);
		rl_pending_input = 0;
		RL_UNSETSTATE (RL_STATE_INPUTPENDING);
		if (*rl_deprep_term_function)
			(*rl_deprep_term_function)();
		close(STDIN_FILENO);
	}
}

int	ft_sig(void)
{
	return (0);
}
