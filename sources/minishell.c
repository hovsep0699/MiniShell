/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:03:42 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/06 18:55:43 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_signal	g_signal;

int	exec_inout(char *line, char **envp, t_dict *last_command)
{
	char	**command;
	char	*tmp_line;
	char	*pipe_line;
	int		count;

	ft_default_set(last_command);
	pipe_line = ft_pipe(last_command, line);
	tmp_line = enter_split_sapce(&pipe_line);
	command = ft_split(tmp_line, ' ');
	count = ft_vecstrlen(command);
	system_command(command, last_command, envp, count);
	ft_pipe_close(last_command->change_fd_in);
	ft_pipe_close(last_command->change_fd_out);
	ft_fd_open(last_command);
	if (last_command->isparrent == 0)
		exit(0);
	ft_strdel(&tmp_line);
	ft_strdel(&pipe_line);
	ft_vecstrdel(&command);
	return (1);
}

char	*replace_str(char *curr_path)
{
	char	*path;
	int		j;
	int		i;

	i = 0;
	j = 0;
	path = (char *)ft_calloc(ft_zero_byte_strlen(curr_path) + 1, sizeof(char));
	if (path == NULL)
		return (NULL);
	while (curr_path[i])
	{
		path[j] = curr_path[i];
		++i;
		++j;
	}
	return (path);
}

int	quote_check(char *s, char exp, char exp2)
{
	int static		exp_state;
	int static		exp_state2;
	t_quote_check	quote_check;

	exp_state = 1;
	exp_state2 = 1;
	quote_check.pipe_problem = 1;
	quote_check.flag_caharacter = 0;
	quote_check.i = 0;
	while (s[quote_check.i])
	{
		exp_state = ft_qch(exp_state, exp_state2, s[quote_check.i], exp);
		exp_state2 = ft_qch(exp_state2, exp_state, s[quote_check.i], exp2);
		if (s[quote_check.i++] == '|' && exp_state2 && exp_state)
			quote_check.pipe_problem++;
	}
	if (!(exp_state && exp_state2))
		printf("quote ERROR\n");
	else if ((ft_strlen(s) > 0 && s[quote_check.i - 1] == '|') || s[0] == '|')
		printf("Pipe Error\n");
	return (exp_state2 && exp_state && !((ft_strlen(s) > 0 && s[quote_check.i - 1] == '|') || s[0] == '|'));
}

void	ft_setenv(char **envp, char *key, char *value)
{
	t_string	str;
	t_string	env_key;
	int			key_index;

	env_key = ft_string_constructor(key);
	env_key.resize(&env_key, env_key.size + 1);
	env_key.data[env_key.size - 1] = '=';
	key_index = ft_vecstr_search2(envp, env_key.data, 0);
	str = ft_string_constructor(envp[key_index]);
	str.erase_between(&str, env_key.size + 1, str.size);
	str.join2(&str, value);
	ft_strcpy(envp[key_index], str.data);
	ft_string_destructor(&str);
	ft_string_destructor(&env_key);
}

int	main(int argv, char **args, char **envp)
{
	t_dict	lcmd;

	lcmd = ft_dict_constructor();
	lcmd.variable_dic = ft_env_copy(envp);
	set_default_gloabl();
	while (true)
	{
		printf(TEXT_GREEN);
		ft_fd_open(&lcmd);
		ft_process_signal(&lcmd);
		lcmd.line = readline("Minishell$> \033[0m");
		// printf(TEXT_WHITE);
		if (ft_isnull(lcmd.line, 0))
			continue ;
		// if (ft_zero_byte_strlen(lcmd.line) > 0)
			add_history(lcmd.line);
		if (quote_check(lcmd.line, CHAR_QUATES, CHAR_DQUATES) == 0)
		{
			ft_strdel(&lcmd.line);
			continue ;
		}
		
		exec_inout(lcmd.line, envp, &lcmd);
		ft_pipe_close(lcmd.change_fd_in);
		ft_pipe_close(lcmd.change_fd_out);
		ft_strdel(&lcmd.line);
	}
	ft_dict_destructor(&lcmd);
	return (0);
}
