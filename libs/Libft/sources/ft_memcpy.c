/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 02:25:42 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:27:19 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	source = (const unsigned char *)src;
	destination = (unsigned char *)dst;
	while (n)
	{
		*destination = *source;
		++destination;
		++source;
		--n;
	}
	return (dst);
}
