/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:23:13 by mgarcia-          #+#    #+#             */
/*   Updated: 2021/03/23 16:33:35 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index])
		++index;
	while (*s2 && n > 0)
	{
		s1[index] = *s2;
		++index;
		++s2;
		--n;
	}
	s1[index] = '\0';
	return (s1);
}
