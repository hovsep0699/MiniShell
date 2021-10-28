/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:45:57 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/26 19:46:08 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring.h"
#include <stdio.h>

t_string	ft_string_default_constructor(void)
{
	t_string	str;

	str.data = NULL;
	str.erase = ft_string_erase;
	str.erase2 = ft_string_erase2;
	str.resize = ft_string_resize;
	str.erase_between = ft_string_erase_between;
	str.join = ft_string_join;
	str.join2 = ft_string_join2;
	str.substr = ft_ssubstr;
	str.insert = ft_string_insert;
	str.insert2 = ft_string_insert2;
	str.find = ft_string_find;
	str.find2 = ft_string_find2;
	str.find3 = ft_string_find3;
	str.rfind = ft_string_rfind;
	str.rfind2 = ft_string_rfind2;
	str.rfind3 = ft_string_rfind3;
	str.rfind4 = ft_string_rfind4;
	str.tolower = ft_t_stringolower;
	str.toupper = ft_t_stringolower;
	str.compare = ft_string_compare;
	str.compare2 = ft_string_compare2;
	return (str);
}

void	ft_string_erase2(t_string *str, size_t it, size_t len)
{
	char	*copy;
	size_t	index;
	size_t	copy_index;

	copy = (char *)malloc(sizeof(char) * str->size);
	index = 0;
	copy_index = 0;
	while (str->data[index])
	{
		if (index == it)
		{
			index += len;
			continue ;
		}
		copy[copy_index] = str->data[index];
		++copy_index;
		++index;
	}
	copy[++copy_index] = '\0';
	ft_strdel(&str->data);
	str->data = copy;
	str->size -= len;
}

void	ft_string_erase_between(t_string *str, size_t start, size_t end)
{
	char	*copy;
	size_t	tmp;

	if (start > end)
	{
		tmp = start;
		start = end;
		end = tmp;
	}
	if (!(start - end))
		return ;
	copy = (char *)ft_calloc(str->size, sizeof(char));
	ft_strncpy(copy, str->data, start);
	ft_strcat(copy, str->data + end);
	ft_strdel(&str->data);
	str->data = copy;
	str->size -= end - start + 1;
}

void	ft_string_insert(t_string *str, size_t index, t_string *str2)
{
	char	*new;
	size_t	size;

	size = ft_zero_byte_strlen(str->data) + ft_zero_byte_strlen(str2->data);
	new = (char *)ft_calloc(size + 1, sizeof(char));
	ft_strncpy(new, str->data, index + 1);
	ft_strcat(new, str2->data);
	ft_strcat(new, str->data + index);
	ft_strdel(&str->data);
	str->data = new;
	str->size = size;
}

void	ft_string_insert2(t_string *str, size_t index, char *str2)
{
	char	*new;
	size_t	size;

	size = ft_zero_byte_strlen(str->data) + ft_zero_byte_strlen(str2);
	new = (char *)ft_calloc(size + 1, sizeof(char));
	ft_strncpy(new, str->data, index + 1);
	ft_strcat(new, str2);
	ft_strcat(new, str->data + index);
	ft_strdel(&str->data);
	str->data = new;
	str->size = size;
}
