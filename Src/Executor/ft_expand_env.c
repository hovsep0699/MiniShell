/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:24:26 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:47 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_handle_exp_quotes(t_expand_token *exp, t_symbol_table *table)
{
	exp->index_quot = ft_ignore_quots(exp->token, \
				exp->token[exp->index], exp->index);
	if (exp->token[exp->index] == '\'')
	{
		exp->size += exp->index_quot - exp->index - 1;
		exp->index = exp->index_quot + 1;
	}
	else
	{
		++exp->index;
		exp->for_rep = ft_substr(exp->token, exp->index, \
		(exp->index_quot - exp->index));
		exp->size += ft_count_replace_len(exp->for_rep, table, EXPAND);
		free(exp->for_rep);
		exp->index = exp->index_quot + 1;
	}
}

void	ft_replace_pattern(char *expand, t_expand_token *exp, \
							t_symbol_table *table)
{
	exp->index_quot = ft_ignore_quots(exp->token, \
						exp->token[exp->index], exp->index);
	if (exp->token[exp->index] == '\'')
	{
		ft_memmove(expand + exp->size, (exp->token + exp->index + 1), \
					exp->index_quot - exp->index - 1);
		exp->size += exp->index_quot - exp->index - 1;
		exp->index = exp->index_quot + 1;
	}
	else
		ft_replace_pattern_part(expand, exp, table);
}

int	ft_handle_replace_exp(char *expand, t_symbol_table *table, \
					t_expand_token *exp, t_expand_type isexpand)
{
	if (isexpand && (exp->token[exp->index] == '\'' || \
		exp->token[exp->index] == '\"'))
	{
		ft_replace_pattern(expand, exp, table);
		return (1);
	}
	else if (exp->token[exp->index] == '$')
	{
		exp->index_quot = ft_ignore_symbol(exp->token, \
						exp->token[exp->index], exp->index);
		exp->for_rep = ft_get_pattern(exp->token, exp->index, &exp->index_quot);
		exp->size += ft_vulue_variable_env(exp->for_rep, \
					expand + exp->size, table);
		free(exp->for_rep);
		exp->index = exp->index_quot;
		return (1);
	}
	return (0);
}

char	*ft_count_replace(char *arg, t_symbol_table *table, \
							t_expand_type isexpand)
{
	t_expand_token	exp;
	char			*expand;

	exp.token = arg;
	exp.size = 0;
	exp.index = 0;
	exp.index_quot = 0;
	expand = ft_calloc(ft_count_replace_len(arg, \
					table, isexpand) + 1, sizeof(char));
	while (exp.token && exp.token[exp.index])
	{
		if (ft_handle_replace_exp(expand, table, &exp, isexpand))
			continue ;
		expand[exp.size] = exp.token[exp.size];
		++exp.size;
		++exp.index;
	}
	return (expand);
}

void	ft_expand_env(t_command *command, t_symbol_table *table)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (command->argument && command->argument->arguments && \
		command->argument->arguments[0])
	{
		while (command->argument && command->argument->arguments && \
				command->argument->arguments[i])
		{
			tmp = ft_count_replace(command->argument->arguments[i], \
						table, NOEXPAND);
			free(command->argument->arguments[i]);
			command->argument->arguments[i] = tmp;
			++i;
		}
		ft_remove_empty_args(command);
	}
}
