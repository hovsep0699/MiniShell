/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:12:39 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/03 20:00:07 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft_Vache.h"

static char	**ft_alloc_split(char const *s, char c)
{
	size_t			i;
	char			**split;
	size_t			total;
	t_split_next	ex;

	i = 0;
	total = 0;
	ex.exp_state = 1;
	ex.exp_state2 = 1;
	while (s[i])
	{
		ex.exp_state = quote_check_sp(ex.exp_state, ex.exp_state2, s[i]);
		ex.exp_state2 = quote_check_sp(ex.exp_state2, ex.exp_state, s[i]);
		if (s[i] == c && ex.exp_state && ex.exp_state2)
			total++;
		i++;
	}
	split = (char **)malloc(sizeof(s) * (total + 2));
	if (!split)
		return (NULL);
	return (split);
}

static void	*ft_free_all_split_alloc(char **split, size_t elts)
{
	size_t	i;

	i = 0;
	while (i < elts)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static void	*ft_split_range(char **split, char const *s,
		t_split_next *st, t_split_next *lt)
{
	split[lt->length] = ft_substr(s, st->start, st->length);
	if (!split[lt->length])
		return (ft_free_all_split_alloc(split, lt->length));
	lt->length++;
	return (split);
}

static void	*ft_split_by_char(char **split, char const *s, char c)
{
	t_split_next	st;
	t_split_next	lt;

	lt = def();
	while (s[lt.i])
	{
		lt.exp_state = quote_check_sp(lt.exp_state, lt.exp_state2, s[lt.i]);
		lt.exp_state2 = quote_check_sp(lt.exp_state2, lt.exp_state, s[lt.i]);
		if (s[lt.i] == c && lt.exp_state && lt.exp_state2)
		{
			st.start = lt.start;
			st.length = (lt.i - lt.start);
			if (lt.i > lt.start && !ft_split_range(split, s, &st, &lt))
				return (NULL);
			lt.start = lt.i + 1;
		}
		lt.i++;
	}
	st.start = lt.start;
	st.length = (lt.i - lt.start);
	if (lt.i > lt.start && lt.i > 0 && !ft_split_range(split, s, &st, &lt))
		return (NULL);
	split[lt.length] = 0;
	return (split);
}

char	**ft_split_vache(char const *s, char c)
{
	char	**split;

	split = ft_alloc_split(s, c);
	if (split == NULL)
		return (NULL);
	if (!ft_split_by_char(split, s, c))
		return (NULL);
	return (split);
}
