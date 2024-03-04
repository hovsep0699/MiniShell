/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_balanced.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:55:10 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:17:29 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_block_performer(char *input, int *quotes_qount, \
		int *index, char c)
{
	(*quotes_qount)++;
	*index = ft_ignore_quots(input, input[*index], *index);
	if (input[*index])
		if (input[*index] == c)
			(*quotes_qount)++;
	(*index)++;
}

static int	ft_is_quota_balanc(char *input)
{
	int	i;
	int	single_quotes;
	int	double_quotes;

	i = 0;
	single_quotes = 0;
	double_quotes = 0;
	if (input == NULL)
		return (1);
	while (input && input[i])
	{
		if (input[i] == '\'')
		{
			ft_block_performer(input, &single_quotes, &i, '\'');
			continue ;
		}
		else if (input[i] == '\"')
		{
			ft_block_performer(input, &double_quotes, &i, '\"');
			continue ;
		}
		i++;
	}
	return ((single_quotes % 2 == 0) && (double_quotes % 2 == 0));
}

static int	ft_is_balanc(char *line)
{
	int		i;
	int		balanced;
	t_stack	*stack;

	stack = ft_initialize_stack();
	i = 0;
	while (line && line[i])
	{
		if (line[i] == '(')
			ft_push_stack(stack, '(');
		else if (line[i] == ')')
		{
			if (ft_pop_stack(stack) != '(')
			{
				ft_free_stack(stack);
				free(stack);
				return (0);
			}
		}
		i++;
	}
	balanced = ft_is_empty(stack);
	ft_free_stack(stack);
	free(stack);
	return (balanced);
}

int	ft_balanced(char *line)
{
	if (!ft_is_balanc(line))
	{
		ft_panic_shell("minishell: ", "unexpected EOF \
				while looking for matching `('");
		return (2);
	}
	else if (!ft_is_quota_balanc(line))
	{
		ft_panic_shell("minishell: ", "unexpected EOF \
				while looking for matching `\'\'");
		return (2);
	}
	return (EXIT_SUCCESS);
}
