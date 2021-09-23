/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:12:39 by vgaspary          #+#    #+#             */
/*   Updated: 2021/01/31 20:24:07 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft_Vache.h"

static char	**ft_alloc_split(char const *s, char c, char exp, char exp2)
{
	size_t	i;
	char	**split;
	size_t	total;
	int exp_state;
	int exp_state2;

	i = 0;
	total = 0;
	exp_state = 1;
	exp_state2 = 1;
	while (s[i])
	{
		if((s[i] == exp && exp_state2 == 1) && exp_state == 1)
			exp_state = 0;
		 else if ((s[i] == exp && exp_state2 == 1) && exp_state == 0)
			exp_state = 1;
		if((s[i] == exp2 && exp_state == 1) && exp_state2 == 1)
			exp_state2 = 0;
		else if((s[i] == exp2 && exp_state == 1) && exp_state2 == 0)
			exp_state2 = 1;
		if (s[i] == c && exp_state && exp_state2)
			total++;
		
		i++;
	}
	split = (char**)malloc(sizeof(s) * (total + 2));
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

static void	*ft_split_by_char(char **split, char const *s, char c, char exp, char exp2)
{
	size_t			i;
	t_split_next	st;
	t_split_next	lt;
	int exp_state;
	int exp_state2;

	i = 0;
	lt.length = 0;
	lt.start = 0;
	exp_state = 1;
	exp_state2 = 1;
	while (s[i])
	{
		if((s[i] == exp && exp_state2 == 1) && exp_state == 1)
			exp_state = 0;
		 else if ((s[i] == exp && exp_state2 == 1) && exp_state == 0)
			exp_state = 1;
		if((s[i] == exp2 && exp_state == 1) && exp_state2 == 1)
			exp_state2 = 0;
		else if((s[i] == exp2 && exp_state == 1) && exp_state2 == 0)
			exp_state2 = 1;
		if (s[i] == c && exp_state && exp_state2)
		{
			st.start = lt.start;
			st.length = (i - lt.start);
			if (i > lt.start && !ft_split_range(split, s, &st, &lt))
				return (NULL);
			lt.start = i + 1;
		}
		i++;
	}
	st.start = lt.start;
	st.length = (i - lt.start);
	if (i > lt.start && i > 0 && !ft_split_range(split, s, &st, &lt))
		return (NULL);
	split[lt.length] = 0;
	return (split);
}

char		**ft_split_Vache(char const *s, char c, char exp, char exp2)
{
	char	**split;
	if (!(split = ft_alloc_split(s, c, exp, exp2)))
		return (NULL);
	if (!ft_split_by_char(split, s, c, exp, exp2))
		return (NULL);
	return (split);
}
