/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 03:59:50 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:41:20 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st_index;
	size_t	e_index;
	char	*trim_str;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return ("\0");
	st_index = 0;
	e_index = ft_strlen(s1) - 1;
	while (*(s1 + st_index) && ft_strchr(set, *(s1 + st_index)))
		++st_index;
	while (e_index > st_index && ft_strchr(set, *(s1 + e_index)))
		--e_index;
	if (!(trim_str = malloc((e_index - st_index + 2) * sizeof(char))))
		return (NULL);
	ft_strlcpy(trim_str, s1 + st_index, e_index - st_index + 2);
	return (trim_str);
}
