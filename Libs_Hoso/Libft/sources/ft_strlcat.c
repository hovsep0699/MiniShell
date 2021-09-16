/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 03:16:37 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:32:16 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		++i;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		++j;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
