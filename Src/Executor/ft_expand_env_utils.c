/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_env_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:35:27 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:44 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_get_pattern(char *arg, size_t i, size_t *index_quot)
{
	char	*for_rep;

	if (arg[i + 1] == '$')
	{
		for_rep = ft_strdup("$$");
		++(*index_quot);
	}
	else if (arg[i + 1] == '?')
	{
		for_rep = ft_strdup("$?");
		++(*index_quot);
	}
	else
		for_rep = ft_substr(arg, i, (*index_quot - i));
	return (for_rep);
}

int	ft_ignore_symbol(char *str, char sym, size_t i)
{
	if (str && str[i])
	{
		++i;
		if (str[i] == '?')
			return (i);
		while (str[i] && str[i] != sym && !ft_isspace(str[i]) && \
			str[i] != '\'' && str[i] != '\"' && str[i] != '/')
			++i;
	}
	return (i);
}

size_t	ft_get_length(char *arg, size_t i, size_t start, t_symbol_table *table)
{
	if (arg[i] == '$')
		return (ft_strlen(ft_get_env(table->env, "$")));
	else if (arg[i] == '?')
		return (ft_strlen(ft_get_env(table->env, "?")));
	if (ft_variable_identifier(arg + start))
		return (ft_strlen(ft_get_env(table->env, arg + i)));
	return (ft_strlen(arg + start));
}

size_t	ft_copy_pattern(t_expand_token expand, t_symbol_table *table, \
						size_t start)
{
	if (expand.token[expand.index] == '$')
	{
		expand.size = ft_strlen(ft_get_env(table->env, "$"));
		ft_memmove(expand.for_rep, ft_get_env(table->env, "$"), expand.size);
		return (expand.size);
	}
	else if (expand.token[expand.index] == '?')
	{
		expand.size = ft_strlen(ft_get_env(table->env, "?"));
		ft_memmove(expand.for_rep, ft_get_env(table->env, "?"), expand.size);
		return (expand.size);
	}
	if (ft_variable_identifier(expand.token + start))
	{
		expand.size = ft_strlen(ft_get_env(table->env, \
						expand.token + expand.index));
		ft_memmove(expand.for_rep, \
		ft_get_env(table->env, expand.token + expand.index), expand.size);
		return (expand.size);
	}
	expand.size = ft_strlen(expand.token + start);
	ft_memmove(expand.for_rep, expand.token + start, expand.size);
	return (expand.size);
}

void	ft_remove_empty_args(t_command *command)
{
	char	*tmp;
	size_t	i;
	char	**args;

	i = 0;
	tmp = NULL;
	args = command->argument->arguments;
	while (command->argument && args && \
			args[i])
	{
		if (!ft_strlen(args[i]))
		{
			tmp = args[i];
			args[i] = args[i + 1];
			free(tmp);
		}
		++i;
	}
}
