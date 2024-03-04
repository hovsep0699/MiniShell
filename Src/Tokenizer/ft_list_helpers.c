/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:05:12 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:17:41 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_list_token	*ft_sublist(t_token *start, t_token *end)
{
	t_list_token	*list;

	list = ft_init_list();
	while (start != end)
	{
		ft_push_back(list, start->type, start->token);
		start = start->next;
	}
	return (list);
}

t_token	*ft_find_list(t_token_type type, t_token *start)
{
	t_token	*token;

	token = start;
	while (token)
	{
		if (token->type == type)
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*ft_find_close_list(t_token *open_brac)
{
	int		count;
	t_token	*node;

	if (!open_brac)
		return (NULL);
	node = open_brac->next;
	count = 1;
	while (node)
	{
		if (node->type == OPBREK)
			++count;
		else if (node->type == CLBREK)
		{
			--count;
			if (0 == count)
				return (node);
		}
		node = node->next;
	}
	return (NULL);
}
