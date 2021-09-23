/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:57:31 by hohayrap          #+#    #+#             */
/*   Updated: 2021/08/14 15:16:38 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_zero_byte_strlen(const char *s)
{
	size_t index;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
		++index;
	return (index);
}

char	*ft_realloc_strjoin(char *s1, char *s2)
{
	char		*new_str;
	size_t		f_index;
	size_t		s_index;

	if (!(new_str = malloc(sizeof(char) *
					(ft_zero_byte_strlen(s1) + ft_zero_byte_strlen(s2) + 1))))
		return (NULL);
	f_index = 0; 
	s_index = 0;
	if (s1)
		while (s1[f_index])
			new_str[s_index++] = s1[f_index++];
	f_index = 0;
	if (s2)
		while (s2[f_index])
			new_str[s_index++] = s2[f_index++];
	new_str[s_index] = '\0';
	ft_strdel(&s1);
	return (new_str);
}

bool		ft_findchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (true);
		++index;
	}
	return (false);
}
