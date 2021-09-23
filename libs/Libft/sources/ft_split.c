/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 03:00:00 by hohayrap          #+#    #+#             */
/*   Updated: 2021/06/11 22:50:17 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_splited_count(char const *s, char c)
{
	size_t w_count;
	size_t w_len;

	w_count = 0;
	while (*s)
	{
		w_len = 0;
		while (*s && *s != c)
		{
			++s;
			++w_len;
		}
		if (w_len)
		{
			++w_count;
			continue ;
		}
		++s;
	}
	return (w_count);
}

static char		**ft_split_mem_error(char **strings)
{
	size_t index;

	index = 0;
	while (strings[index])
	{
		free(strings[index]);
		++index;
	}
	free(strings);
	return (NULL);
}

static void		ft_splited_next_size(const char **s, size_t *next, char c)
{
	size_t index;

	*s += *next;
	*next = 0;
	index = 0;
	while (**s && **s == c)
		++(*s);
	while ((*s)[index])
	{
		if ((*s)[index] == c)
			return ;
		++(*next);
		++index;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**sp_str;
	size_t	index;
	size_t	next;
	size_t	tot_size;

	if (!s)
		return (NULL);
	tot_size = ft_splited_count(s, c);
	if (!(sp_str = (char **)malloc((tot_size + 1) * sizeof(char *))))
		return (NULL);
	index = 0;
	next = 0;
	while (index < tot_size)
	{
		ft_splited_next_size(&s, &next, c);
		if (!(sp_str[index] = malloc(sizeof(char) * (next + 1))))
			return (ft_split_mem_error(sp_str));
		ft_strlcpy(sp_str[index], s, next + 1);
		++index;
	}
	sp_str[index] = NULL;
	return (sp_str);
}
