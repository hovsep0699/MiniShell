/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:41:22 by mgarcia-          #+#    #+#             */
/*   Updated: 2021/03/23 16:22:49 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	swap;
	int		index;
	int		r_index;

	index = 0;
	r_index = ft_strlen(str) - 1;
	while (index < r_index)
	{
		swap = str[index];
		str[index] = str[r_index];
		str[r_index] = swap;
		++index;
		--r_index;
	}
	return (str);
}
