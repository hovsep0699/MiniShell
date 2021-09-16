/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:45:17 by hohayrap          #+#    #+#             */
/*   Updated: 2021/07/24 16:45:20 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_vecstr_search(char **vecstr, char *search)
{
	int		index;
	size_t	search_len;

	index = -1;
	if (!vecstr || !*vecstr || !search)
		return NULL;
	search_len = ft_strlen(search);
	while (vecstr[++index])
		if (!ft_strncmp(vecstr[index], search, search_len))
			return (ft_strdup(vecstr[index] + search_len));
	return (NULL);
}
