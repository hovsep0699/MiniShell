/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 03:17:47 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:32:24 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t index;
	size_t s_size;

	if (!dst && !src)
		return (0);
	index = 0;
	s_size = ft_strlen(src);
	if (dstsize == 0)
		return (s_size);
	while (src[index] != '\0' && index < dstsize - 1)
	{
		dst[index] = src[index];
		++index;
	}
	dst[index] = '\0';
	return (s_size);
}
