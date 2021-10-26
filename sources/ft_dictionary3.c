/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:44:40 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/24 12:44:42 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_data_int(char *key, dictionary_t *command)
{
	int	key_len;
	int	dict_len;
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (key[j] && key[j] != '=')
		j++;
	key_len = ft_strlen(key);
	if (j == key_len)
		return (-1);
	while (command != NULL)
	{
		dict_len = ft_strlen(command->key);
		if (j == dict_len && ft_strncmp(key, command->key, j) == 0)
			return (i);
		command = command->next;
		i++;
	}
	return (-1);
}

void	change_item(char *new_item, int key_index, dictionary_t *dict)
{
	int	len_new_item;
	int	j;

	j = 0;
	while (new_item[j] && new_item[j] != '=')
		j++;
	len_new_item = ft_zero_byte_strlen(new_item);
	if (j == len_new_item)
		j = 0;
	else
		j++;
	while (key_index != 0)
	{
		dict = dict->next;
		key_index--;
	}
	ft_strdel(&dict->item);
	dict->item = ft_strdup(new_item + j);
}

void	ft_dictionaryadd_back(dictionary_t **lst, dictionary_t *new)
{
	dictionary_t	*ptr;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = ft_dictionarylast(*lst);
	new->next = ptr->next;
	ptr->next = new;
}

void	ft_dictionary_del_key(dictionary_t *del_stack)
{
	ft_memdel((void **)&del_stack->key);
	ft_memdel((void **)&del_stack->item);
	ft_memdel((void **)&del_stack);
}