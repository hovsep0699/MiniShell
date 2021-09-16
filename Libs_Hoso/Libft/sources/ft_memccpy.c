/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 00:49:28 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:26:53 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;
	size_t				index;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	index = 0;
	while (++index <= n)
	{
		*dest = *source;
		if (*source == (unsigned char)c)
			return (dst + index);
		++dest;
		++source;
	}
	return (NULL);
}
