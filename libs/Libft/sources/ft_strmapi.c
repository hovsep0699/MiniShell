/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 03:34:41 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:32:51 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	index;

	index = 0;
	if (!s || !f)
		return (NULL);
	if (!(new_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[index])
	{
		new_str[index] = f(index, s[index]);
		++index;
	}
	new_str[index] = '\0';
	return (new_str);
}
