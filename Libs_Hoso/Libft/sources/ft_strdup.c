/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 03:10:49 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:31:49 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	size;
	size_t	index;
	char	*str;

	size = ft_strlen(src);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	index = 0;
	while (src[index])
	{
		str[index] = src[index];
		++index;
	}
	str[index] = '\0';
	return (str);
}
