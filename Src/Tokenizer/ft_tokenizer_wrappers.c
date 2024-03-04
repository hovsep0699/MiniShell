/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer_wrappers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:37:58 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:18:05 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_tokenize_delim_util(t_tokenize_wrap *wrap, int *type)
{
	if (wrap->token_start[wrap->index] && wrap->token_start[wrap->index + 1] && \
		wrap->token_start[wrap->index] == wrap->token_start[wrap->index + 1] && \
		!ft_is_breckets(ft_get_type_map(wrap->token_start[wrap->index])))
	{
		wrap->is_one_sym = 0;
		*type = -wrap->token_start[wrap->index];
	}
	else
	{
		wrap->is_one_sym = 1;
		*type = wrap->token_start[wrap->index];
	}
	wrap->token_start[wrap->index] = '\0';
	if (!wrap->is_one_sym)
		++wrap->index;
	wrap->next_token = wrap->token_start + wrap->index + 1;
}

int	ft_tokenize_delim_helper(t_tokenize_wrap *wrap, char *delim, int *type)
{
	wrap->is_one_sym = 0;
	while (wrap->token_start[wrap->index])
	{
		if (ft_strchr(delim, wrap->token_start[wrap->index]))
		{
			ft_tokenize_delim_util(wrap, type);
			return (1);
		}
		else
			*type = MTEXT;
		++wrap->index;
	}
	return (0);
}

char	*ft_tokenize_with_delims(char *str, char *delim, int *type)
{
	static char		*next_token;
	t_tokenize_wrap	wrapper;

	if (str)
		next_token = str;
	if (!next_token)
		return (NULL);
	wrapper.token_start = next_token;
	wrapper.next_token = next_token;
	wrapper.index = 0;
	*type = MNNULL;
	if (wrapper.token_start[wrapper.index] == '\"' || \
		wrapper.token_start[wrapper.index] == '\'')
	{
		*type = MTEXT;
		wrapper.index = ft_ignore_quots(wrapper.token_start, \
						wrapper.token_start[wrapper.index], 0);
	}
	if (ft_tokenize_delim_helper(&wrapper, delim, type))
	{
		next_token = wrapper.next_token;
		return (wrapper.token_start);
	}
	next_token = NULL;
	return (wrapper.token_start);
}

int	ft_tokenize_space_helper(t_tokenize_wrap *wrapper, int *type)
{
	while (wrapper->token_start[wrapper->index])
	{
		if (ft_isspace(wrapper->token_start[wrapper->index]))
		{
			*type = MTEXT;
			wrapper->token_start[wrapper->index] = '\0';
			++wrapper->index;
			while (wrapper->token_start[wrapper->index] && \
					ft_isspace(wrapper->token_start[wrapper->index]))
				++wrapper->index;
			if (!wrapper->token_start[wrapper->index])
				wrapper->next_token = NULL;
			else
				wrapper->next_token = wrapper->token_start + wrapper->index;
			return (1);
		}
		++wrapper->index;
	}
	return (0);
}

char	*ft_tokenize_with_space(char *expr, int *type)
{
	t_tokenize_wrap	wrapper;
	static char		*next_token;

	if (expr)
		next_token = expr;
	if (!next_token)
		return (NULL);
	wrapper.index = 0;
	wrapper.next_token = next_token;
	wrapper.token_start = next_token;
	*type = NNULL;
	if (wrapper.token_start[wrapper.index] == '\"' || \
		wrapper.token_start[wrapper.index] == '\'')
	{
		*type = MTEXT;
		wrapper.index = ft_ignore_quots(wrapper.token_start, \
						wrapper.token_start[wrapper.index], 0);
	}
	if (ft_tokenize_space_helper(&wrapper, type))
	{
		next_token = wrapper.next_token;
		return (wrapper.token_start);
	}
	next_token = NULL;
	return (wrapper.token_start);
}
