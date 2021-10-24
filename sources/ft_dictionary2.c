/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:44:26 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/24 12:44:30 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

dictionary_t	*ft_dict_mem(int index_item, int index)
{
	dictionary_t	*ptr;

	ptr = (dictionary_t *)ft_memalloc(sizeof(dictionary_t));
	if (ptr == NULL)
		return (NULL);
	ptr->key = (char *)ft_calloc(index, sizeof(char));
	if (ptr->key == NULL)
	{
		ft_memdel((void **)&ptr);
		return (NULL);
	}
	ptr->item = (char *)ft_calloc(index_item, sizeof(char));
	if (ptr == NULL)
	{
		ft_memdel((void **)&ptr->key);
		ft_memdel((void **)&ptr);
		return (NULL);
	}
	return (ptr);
}

dictionary_t	*ft_dictionary_create(char *items)
{
	t_dictone	dict;

	dict.index_item = 1;
	dict.len_items = ft_strlen(items);
	dict.index = ft_find_element(items);
	if (dict.index == -1)
		return (NULL);
	if (ft_isdigit(items[0]) == 1)
	{
		export_error(items);
		return (NULL);
	}
	if (dict.index == (-1))
		dict.index = dict.len_items;
	else
		dict.index_item = dict.len_items - dict.index;
	dict.ptr = ft_dict_mem(dict.index_item, dict.index);
	if (dict.ptr == NULL)
		return (NULL);
	dict.ptr->next = NULL;
	ft_joins_dict(items, 0, dict.index, dict.ptr->key);
	dict.ptr->key[dict.index] = '\0';
	if (dict.len_items != dict.index)
		ft_joins_dict(items, dict.index + 1, ft_strlen(items), dict.ptr->item);
	return (dict.ptr);
}

dictionary_t	*ft_dictionarylast(dictionary_t *lst)
{
	dictionary_t	*ptr;

	ptr = lst;
	if (lst == NULL)
		return (0);
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

int	find_equal_part(char *str)
{
	int	key_len;
	int	dict_len;
	int	final_len;

	key_len = 0;
	while (str[key_len] && ft_isalnum(str[key_len]))
		key_len++;
	if (ft_isalnum(str[key_len]))
		return ((key_len));
	return (-1);
}

char	*find_data(char *key, dictionary_t *command)
{
	int	klen;
	int	dlen;

	klen = 0;
	while (ft_isalnum(*(key + klen)))
		klen++;
	while (command != NULL)
	{
		dlen = ft_zero_byte_strlen(command->key);
		if (klen == dlen && ft_strncmp(key, command->key, dlen) == 0 )
		{
			if (command->item[0] == '\0')
				return (NULL);
			else
				return (command->item);
		}
		command = command->next;
	}
	return (NULL);
}
