/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 03:11:53 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:31:59 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	f_size;
	size_t	s_size;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	f_size = ft_strlen(s1);
	s_size = ft_strlen(s2);
	if (!(new_str = malloc(f_size + s_size + 1)))
		return (NULL);
	ft_strlcpy(new_str, s1, f_size + 1);
	ft_strlcat(new_str, s2, s_size + f_size + 1);
	return (new_str);
}
