/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_fix_errors2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:54:54 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/29 19:55:45 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signals_print(char *copy)
{
	if (*rl_line_buffer)
		printf("\b\b\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	if (!*copy)
	{
		printf("  \b\b");
		printf("\n");
		printf(SHELL_PROMPT);
	}
	g_signal.exit_status = 1;
}

void	ft_clean_dwrite(char *check, char *line, char **chek_str, int p)
{
	ft_vecstrdel(&chek_str);
	ft_strdel(&check);
	ft_strdel(&line);
	ft_pipe_close(p);
	exit(0);
}

void	ft_norm_write_close(int p, char *line)
{
	write(p, line, ft_zero_byte_strlen(line));
	write(p, "\n", 1);
}

void	create_norm_fix_func2(char **arg, t_dict *dict, int count, char **envp)
{
	t_cmd_func	cmd;

	cmd = ft_search_builtin_func(dict);
	cmd(dict, envp, arg, count);
}
