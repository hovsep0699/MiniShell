/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:48:42 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/26 19:54:04 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring.h"
#include <stdio.h>

int	ft_string_rfind4(t_string *str, char c, int start)
{
	int	index;

	index = start;
	if (!c)
		return (ft_zero_byte_strlen(str->data));
	while (str->data[--index])
	{
		if (str->data[index] == c)
			return (index);
	}
	return (-1);
}

int	ft_string_find2(t_string *str, char *needle)
{
	int	h_index;
	int	n_index;

	h_index = 0;
	if (!needle || !*needle)
		return (-1);
	while (str->data[h_index])
	{
		n_index = 0;
		if (str->data[h_index] == needle[n_index])
		{
			while (str->data[h_index + n_index] == needle[n_index])
			{
				if (needle[n_index + 1] == '\0')
					return (h_index);
				++n_index;
			}
		}
		++h_index;
	}
	return (-1);
}

int	ft_string_find3(t_string *str, t_string *needle)
{
	return (ft_string_find2(str, needle->data));
}

int	ft_string_rfind(t_string *str, char c)
{
	int	index;

	index = str->size;
	if (!c)
		return (ft_zero_byte_strlen(str->data));
	while (str->data[--index])
	{
		if (str->data[index] == c)
			return (index);
	}
	return (-1);
}

int	ft_string_rfind2(t_string *str, char *needle)
{
	int	h_index;
	int	n_index;

	h_index = 0;
	if (!needle || !*needle)
		return (-1);
	while (str->data[h_index])
	{
		n_index = 0;
		if (str->data[str->size - h_index - 1] == needle[n_index])
		{
			while (str->data[str->size - h_index - 1 + n_index]
				== needle[n_index])
			{
				if (!needle[n_index + 1])
					return (str->size - h_index - 1);
				++n_index;
			}
		}
		++h_index;
	}
	return (-1);
}
