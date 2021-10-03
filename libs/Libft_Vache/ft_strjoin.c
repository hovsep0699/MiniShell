/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:46:02 by vgaspary          #+#    #+#             */
/*   Updated: 2021/01/31 18:54:55 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_joins(char const *s2, size_t i, char *subjoin)
{
	while (*s2)
	{
		subjoin[i] = *s2;
		i++;
		s2++;
	}
	return (i);
}

char			*ft_strjoin( char const *s1,  char const *s2)
{
	char	*subjoin;
	size_t	i;

	i = 0;
	subjoin = (char *)malloc((sizeof(s1)
				* (ft_zero_byte_strlen(s1) + ft_zero_byte_strlen(s2)) + 2));
	if (!subjoin)
		return (NULL);
	if(ft_zero_byte_strlen(s1) > 0)
	i = ft_joins(s1, i, subjoin);
	if(ft_zero_byte_strlen(s2) > 0)
	i = ft_joins(s2, i, subjoin);
	subjoin[i] = '\0';
	return (subjoin);
}
