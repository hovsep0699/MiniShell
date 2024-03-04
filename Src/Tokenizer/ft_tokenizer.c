/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:04:57 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:18:08 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_ignore_quots(char *str, char quot, size_t i)
{
	if (str && str[i])
	{
		++i;
		while (str[i] && str[i] != quot)
			++i;
	}
	return (i);
}

t_list_token	*ft_tokenize_string_space(char *input)
{
	int				type;
	char			*token;
	t_list_token	*list;

	type = 0;
	list = ft_init_list();
	token = ft_tokenize_with_space(input, &type);
	while (token != NULL)
	{
		ft_push_back(list, type, token);
		token = ft_tokenize_with_space(NULL, &type);
	}
	return (list);
}

void	ft_tokenize_helper(t_tokenize_wrapper *wrapper, char *delims)
{
	wrapper->token = ft_tokenize_with_delims(wrapper->head->token, \
											delims, &wrapper->type);
	while (wrapper->token)
	{
		if (wrapper->type != MTEXT && wrapper->type)
		{
			if (*wrapper->token)
				ft_push_back(wrapper->list, TEXT, wrapper->token);
			wrapper->tmp_token = ft_get_type(\
							ft_get_type_map(wrapper->type));
			ft_push_back(wrapper->list, \
				ft_get_type_map(wrapper->type), wrapper->tmp_token);
			free(wrapper->tmp_token);
		}
		else if (wrapper->type)
			ft_push_back(wrapper->list, \
				ft_get_type_map(wrapper->type), wrapper->token);
		wrapper->token = ft_tokenize_with_delims(NULL, \
								delims, &wrapper->type);
	}
}

t_list_token	*ft_tokenize(char *input, char *delims)
{
	t_tokenize_wrapper	wrapper;

	wrapper.type = 0;
	wrapper.list = ft_init_list();
	wrapper.space_list = ft_tokenize_string_space(input);
	wrapper.head = wrapper.space_list->head;
	while (wrapper.head)
	{
		wrapper.tmp = wrapper.head->next;
		ft_tokenize_helper(&wrapper, delims);
		free(wrapper.head->token);
		free(wrapper.head);
		wrapper.head = wrapper.tmp;
	}
	free(wrapper.space_list);
	return (wrapper.list);
}
