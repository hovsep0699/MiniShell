/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 03:56:55 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:36:16 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *start;

	start = (const char *)s;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
		++s;
	while (s >= start)
	{
		if (*s == c)
			return ((char *)s);
		--s;
	}
	return (NULL);
}
