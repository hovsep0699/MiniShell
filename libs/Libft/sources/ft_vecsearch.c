/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:45:17 by hohayrap          #+#    #+#             */
/*   Updated: 2021/11/06 19:18:35 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_vecstr_search(char **vecstr, char *search)
{
	int		index;
	size_t	search_len;

	index = -1;
	if (!vecstr || !*vecstr || !search)
		return (NULL);
	search_len = ft_strlen(search);
	while (vecstr[++index])
		if (!ft_strncmp(vecstr[index], search, search_len))
			return (ft_strdup(vecstr[index] + search_len));
	return (NULL);
}

int	ft_vecstr_search1(char **vecstr, char *search)
{
	int		index;
	size_t	search_len;

	index = -1;
	if (!vecstr || !*vecstr || !search)
		return (-1);
	search_len = ft_strlen(search);
	while (vecstr[++index])
		if (!ft_strncmp(vecstr[index], search, search_len))
			return (index);
	return (-1);
}

int	ft_vecstr_search2(char **vecstr, char *search, int start_index)
{
	int		index;
	size_t	search_len;

	index = start_index;
	if (!vecstr || !*vecstr || !search)
		return (-1);
	search_len = ft_strlen(search);
	while (vecstr[++index])
		if (!ft_strncmp(vecstr[index], search, search_len))
			return (index);
	return (index - 1);
}

int	ft_vecstr_search3(char **vecstr, char *search, int start_index)
{
	int		index;
	size_t	search_len;

	index = start_index;
	if (!vecstr || !*vecstr || !search)
		return (-1);
	search_len = ft_strlen(search);
	while (vecstr[++index])
		if (!ft_strncmp(vecstr[index], search, search_len))
			return (index - 1);
	return (index - 1);
}
