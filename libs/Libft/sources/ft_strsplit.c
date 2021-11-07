/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:16:11 by hohayrap          #+#    #+#             */
/*   Updated: 2021/06/24 19:21:38 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	words;

	words = 0;
	if (*str != c && *str)
		words++;
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				words++;
		}
		str++;
	}
	return (words);
}

static int	ft_let(const char *str, char c)
{
	int	len;

	len = 0;
	while (*str != c && *str)
	{
		len++;
		str++;
	}
	return (len);
}

static char	**arr_allocate(char const *s, char c)
{
	char	**arr;

	arr = (char **)ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!s || arr == NULL)
		return (NULL);
	return (arr);
}

t_sph	ft_def_set(void)
{
	t_sph	sp;

	sp.si = 0;
	sp.in = 0;
	return (sp);
}

char	**ft_strsplit(char const *s, char c)
{
	t_sph	sp;

	sp = ft_def_set();
	sp.spa = arr_allocate(s, c);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			sp.spa[sp.si] = (char *)ft_calloc((ft_let(s, c) + 1), sizeof(char));
			if (sp.spa == NULL)
				return (NULL);
			while (*s && *s != c)
			{
				sp.spa[sp.si][sp.in] = (char)*s;
				sp.in++;
				++s;
			}
			++sp.si;
			sp.in = 0;
		}
	}
	sp.spa[sp.si] = NULL;
	return (sp.spa);
}
