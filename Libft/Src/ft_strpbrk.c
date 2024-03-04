/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:37:42 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:12:48 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *str1, const char *str2)
{
	const char	*s1;
	const char	*s2;

	if (!str1 || !str2)
		return (NULL);
	s1 = str1;
	while (s1 && *s1)
	{
		s2 = str2;
		while (s2 && *s2)
		{
			if (*s1 == *s2)
				return ((char *)s1);
			s2++;
		}
		s1++;
	}
	return (NULL);
}
