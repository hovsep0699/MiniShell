/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:44:40 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/06 20:24:50 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_data_int(char *key, t_dictionary *command)
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
	// printf("\n %d %d\n", j, key_len);
	while (command != NULL)
	{
		// printf("\nkey: %s\n", command->key);
		dict_len = ft_strlen(command->key);
		if (j == dict_len && ft_strncmp(key, command->key, j) == 0)
			return (i);
		command = command->next;
		i++;
	}
	return (-1);
}

void	change_item(char *new_item, int key_index, t_dictionary *dict)
{
	int	len_new_item;
	int	j;

	j = 0;
	if (new_item)
	{
		while (new_item[j] && new_item[j] != '=')
			j++;
		len_new_item = ft_zero_byte_strlen(new_item);

		if (j == len_new_item)
			return ;
		else
			j++;
	}
	while (key_index != 0)
	{
		dict = dict->next;
		key_index--;
	}
	ft_strdel(&dict->item);
	if (new_item)
		dict->item = ft_strdup(new_item + j);
	else
		dict->item = NULL;
}

void	ft_dictionaryadd_back(t_dictionary **lst, t_dictionary *new)
{
	t_dictionary	*ptr;

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

void	ft_dictionary_del_key(t_dictionary *del_stack)
{
	ft_memdel((void **)&del_stack->key);
	ft_memdel((void **)&del_stack->item);
	ft_memdel((void **)&del_stack);
}
