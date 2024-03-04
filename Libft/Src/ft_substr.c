/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:21:44 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:13:03 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			s_len;
	size_t			over_len;
	unsigned int	index;
	char			*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	over_len = ft_strlen(s + start);
	index = 0;
	if (len > over_len)
		len = over_len;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (index < len && start + index < (unsigned int)s_len)
	{
		str[index] = *(s + start + index);
		++index;
	}
	str[index] = '\0';
	return (str);
}
