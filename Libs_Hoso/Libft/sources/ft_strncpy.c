/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:25:28 by mgarcia-          #+#    #+#             */
/*   Updated: 2021/03/23 16:34:58 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t index;

	index = 0;
	if (len > 0)
	{
		while (src[index] && index < len)
		{
			dst[index] = src[index];
			++index;
		}
		while (index < len)
		{
			dst[index] = '\0';
			++index;
		}
	}
	return (dst);
}
