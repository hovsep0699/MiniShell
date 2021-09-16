/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 04:04:02 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:41:30 by hohayrap         ###   ########.fr       */
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
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (index < len && start + index < (unsigned int)s_len)
	{
		str[index] = *(s + start + index);
		++index;
	}
	str[index] = '\0';
	return (str);
}
