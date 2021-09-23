/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:25:52 by mgarcia-          #+#    #+#             */
/*   Updated: 2021/03/23 16:41:10 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int h_index;
	int n_index;

	h_index = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[h_index])
	{
		n_index = 0;
		if (haystack[h_index] == needle[n_index])
		{
			while (haystack[h_index + n_index] == needle[n_index])
			{
				if (needle[n_index + 1] == '\0')
					return ((char*)&haystack[h_index]);
				++n_index;
			}
		}
		++h_index;
	}
	return (0);
}
