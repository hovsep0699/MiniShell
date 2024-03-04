/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_env_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:36:17 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:41 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	ft_size_variable_env(char *arg, t_symbol_table *symbol_table)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	if (arg[i] == '$')
	{
		start = i;
		++i;
		return (ft_get_length(arg, i, start, symbol_table));
	}
	return (0);
}

void	ft_count_replace_len_helper(t_expand_token *expand, \
									t_symbol_table *table)
{
	expand->index_quot = ft_ignore_symbol(expand->token, \
						expand->token[expand->index], expand->index);
	expand->for_rep = ft_get_pattern(expand->token, \
				expand->index, &expand->index_quot);
	expand->size += ft_size_variable_env(expand->for_rep, table);
	free(expand->for_rep);
	expand->index = expand->index_quot;
}

size_t	ft_count_replace_len(char *arg, t_symbol_table *table, \
							t_expand_type isexpand)
{
	t_expand_token	expand;

	expand.index = 0;
	expand.size = 0;
	expand.token = arg;
	while (expand.token && expand.token[expand.index])
	{
		if (isexpand && (expand.token[expand.index] == '\'' || \
			expand.token[expand.index] == '\"'))
		{
			ft_handle_exp_quotes(&expand, table);
			continue ;
		}
		else if (expand.token[expand.index] == '$')
		{
			ft_count_replace_len_helper(&expand, table);
			continue ;
		}
		++expand.size;
		++expand.index;
	}
	return (expand.size);
}

size_t	ft_vulue_variable_env(char *arg, char *expand, \
							t_symbol_table *symbol_table)
{
	t_expand_token	exp;
	size_t			i;
	size_t			len;
	size_t			start;

	i = 0;
	len = 0;
	start = 0;
	exp.token = arg;
	exp.for_rep = expand;
	if (arg[i] == '$')
	{
		start = i;
		++i;
		exp.index = i;
		exp.size = len;
		return (ft_copy_pattern(exp, symbol_table, start));
	}
	return (0);
}

void	ft_replace_pattern_part(char *expand, t_expand_token *exp, \
							t_symbol_table *table)
{
	char	*tmp;
	size_t	len;

	++exp->index;
	exp->for_rep = ft_substr(exp->token, exp->index, \
					(exp->index_quot - exp->index));
	tmp = ft_count_replace(exp->for_rep, table, EXPAND);
	len = ft_strlen(tmp);
	ft_memmove(expand + exp->size, tmp, len);
	free(tmp);
	exp->size += len;
	free(exp->for_rep);
	exp->index = exp->index_quot + 1;
}
