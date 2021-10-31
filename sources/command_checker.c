/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:24:54 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/30 20:12:48 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_alloc_split_minishell(char const *s, char c, char exp, char exp2)
{
	size_t	i;
	size_t	total;
	int		exp_state;
	int		exp_state2;

	i = 0;
	total = 0;
	exp_state = 1;
	exp_state2 = 1;
	while (s[i])
	{
		exp_state = ft_qch(exp_state, exp_state2, s[i], exp);
		exp_state2 = ft_qch(exp_state2, exp_state, s[i], exp2);
		if (s[i++] == c && exp_state && exp_state2)
			total++;
	}
	return (total);
}

int	ft_count_quote_character(char charac, int *qu_exist, int *dqu_exist)
{
	if ((charac == CHAR_QUATES && *dqu_exist == 1) && *qu_exist == 1)
	{
		*qu_exist = 0;
		return (true);
	}
	else if ((charac == CHAR_QUATES && *dqu_exist == 1) && *qu_exist == 0)
	{
		*qu_exist = 1;
		return (true);
	}		
	else if ((charac == CHAR_DQUATES && *qu_exist == 1) && *dqu_exist == 1)
	{
		*dqu_exist = 0;
		return (true);
	}
	else if ((charac == CHAR_DQUATES && *qu_exist == 1) && *dqu_exist == 0)
	{
		*dqu_exist = 1;
		return (true);
	}
	return (false);
}

int	ft_count_quote(char *s)
{
	int		i;
	size_t	total;
	int		quoet_exist;
	int		dquoet_exist;

	i = 0;
	total = 0;
	quoet_exist = 1;
	dquoet_exist = 1;
	while (s[i])
	{
		if (ft_count_quote_character(s[i], &quoet_exist, &dquoet_exist))
			total++;
		else if (s[i] == '\\' && (quoet_exist != 0 || dquoet_exist != 0))
			total += 1;
		else if (s[i] == '$' && s[i + 1] == '?' && quoet_exist != 0)
			total += 2;
		else if (s[i] == '$' && quoet_exist != 0)
			total += ft_isalnum_str(s + i + 1, &i) + 1;
		else if (s[i] == '~' && quoet_exist != 0 && dquoet_exist != 0
			&& i == 0 && (s[i + 1] == '\0' || s[i + 1] == '/'))
			total++;
		i++;
	}
	return (total);
}

int	exec_in_function(char **arg, t_dict *dict, int count, char **envp_my)
{
	int	end_of_line;

	end_of_line = 0;
	while (dict->icom < count)
	{
		if (end_of_line >= dict->icom)
			end_of_line = ft_vecstr_search2(arg, ";", dict->icom);
		if (arg[dict->icom][0] == ';')
			return (ft_execendline(arg, dict, count, envp_my));
		else if ((!ft_strcmp(arg[dict->icom], ">>")
				|| !ft_strcmp(arg[dict->icom], "<<")
				|| arg[dict->icom][0] == '>' || arg[dict->icom][0] == '<'))
		{
			dict->icom = runfileutil(arg, dict, dict->icom);
			continue ;
		}
		else if (ft_strcmp(arg[dict->icom], "-n") == 0)
			dict->echo_option = 1;
		dict->data = ft_equal_strjoin(dict->data, dict, arg[dict->icom],
				(end_of_line == dict->icom || count - 1 == dict->icom));
		dict->icom++;
	}
	ft_search_side_func(dict)(dict, envp_my, arg, count);
	return (1);
}

int	system_command(char **list, t_dict *dict, char **env_my, int count)
{
	int		len;
	char	*lower_case;
	int		i;
	int		exeption;

	i = 0;
	while (dict->icom < count)
	{
		lower_case = ft_tolower_minishell(list[i], &len);
		ft_command_dict(lower_case, list[i], dict);
		dict->icom = dict->icom + 1;
		exec_in_function(list, dict, count, env_my);
		i = dict->icom;
		dict->last_command = dict->icom;
		ft_strdel(&lower_case);
	}
	return (1);
}
