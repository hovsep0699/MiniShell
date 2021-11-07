/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:59:24 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/26 20:00:21 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring.h"
#include <stdio.h>

t_string	ft_string_copy_constructor(t_string *str)
{
	t_string	cstr;

	cstr = ft_string_default_constructor();
	cstr.data = ft_strdup(str->data);
	cstr.size = ft_zero_byte_strlen(str->data);
	return (cstr);
}

t_string	ft_string_constructor(char *str)
{
	t_string	string;

	string = ft_string_default_constructor();
	string.size = ft_zero_byte_strlen(str);
	string.data = ft_strdup(str);
	return (string);
}

void	ft_string_resize(t_string *str, size_t size)
{
	ft_realloc(str->data, size);
	ft_bzero(str->data + str->size, size - str->size + 1);
	str->size = size;
}

void	ft_string_erase(t_string *str, size_t it)
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
			++index;
			continue ;
		}
		copy[copy_index] = str->data[index];
		++index;
		++copy_index;
	}
	copy[++copy_index] = '\0';
	ft_strdel(&str->data);
	str->data = copy;
	--str->size;
}

int	ft_string_find(t_string *str, char c)
{
	int	index;

	index = -1;
	if (!c)
		return (ft_zero_byte_strlen(str->data));
	while (str->data[++index])
	{
		if (str->data[index] == c)
			return (index);
	}
	return (-1);
}
