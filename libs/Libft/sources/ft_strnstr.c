/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 03:52:05 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:36:06 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_index;
	size_t	n_index;
	size_t	n_size;

	h_index = 0;
	n_size = ft_strlen(needle);
	if (needle[0] == '\0')
		return (char *)haystack;
	while (haystack[h_index] != '\0' && len > n_size - 1)
	{
		n_index = 0;
		while (needle[n_index] == haystack[h_index + n_index])
		{
			++n_index;
			if (needle[n_index] == '\0')
				return ((char *)haystack + h_index);
		}
		--len;
		++h_index;
	}
	return (NULL);
}
