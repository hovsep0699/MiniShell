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

static int		ft_count_words(const char *str, char c)
{
	int words;

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

static int		ft_letters(const char *str, char c)
{
	int len;

	len = 0;
	while (*str != c && *str)
	{
		len++;
		str++;
	}
	return (len);
}

static char		**arr_allocate(char const *s, char c)
{
	char	**arr;

	if (!s || (!(arr = (char **)malloc(sizeof(char *) * \
						(ft_count_words(s, c) + 1)))))
		return (NULL);
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		s_index;
	int		index;
	char	**split_arr;

	s_index = 0;
	index = 0;
	split_arr = arr_allocate(s, c);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(split_arr[s_index] = (char *)malloc(sizeof(char) * (ft_letters(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
            {
				split_arr[s_index][index] = (char)*s;
                ++index;
                ++s;
            }

			split_arr[s_index][index] = '\0';
			++s_index;
			index = 0;
		}
	}
	split_arr[s_index] = NULL;
	return (split_arr);
}
