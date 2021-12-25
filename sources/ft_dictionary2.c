/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:44:26 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/06 13:52:16 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dictionary	*ft_dict_mem(int index_item, int index)
{
	t_dictionary	*ptr;

	ptr = (t_dictionary *)ft_memalloc(sizeof(t_dictionary));
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

t_dictionary	*ft_dictionary_create(char *items)
{
	t_dictone	dict;

	dict.index_item = 1;
	dict.len_items = ft_strlen(items);
	dict.index = ft_find_element(items);
	if (dict.index == -1)
		dict.ptr->item = NULL;
		printf("start -%i %s	\n",dict.index, items);
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
	if (dict.len_items != dict.index && dict.index != -1)
		ft_joins_dict(items, dict.index + 1, ft_strlen(items), dict.ptr->item);
	return (dict.ptr);
}

t_dictionary	*ft_dictionarylast(t_dictionary *lst)
{
	t_dictionary	*ptr;

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

char	*find_data(char *key, t_dictionary *dict)
{
	int	klen;
	int	dlen;

	klen = 0;
	while (ft_isalnum(*(key + klen)))
		klen++;
	while (dict != NULL)
	{
		dlen = ft_zero_byte_strlen(dict->key);
		if (klen == dlen && !ft_strncmp(key, dict->key, dlen))
		{
			if (!dict->item || dict->item[0] == '\0')
				return (NULL);
			else
				return (dict->item);
		}
		dict = dict->next;
	}
	return (NULL);
}
