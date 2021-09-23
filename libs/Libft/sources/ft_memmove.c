/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 02:36:21 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:27:44 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*source;
	unsigned char		*destination;

	if (!dst && !src)
		return (NULL);
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if ((source < destination) && (destination < source + len))
	{
		destination += len;
		source += len;
		while (len)
		{
			*(--destination) = *(--source);
			--len;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
