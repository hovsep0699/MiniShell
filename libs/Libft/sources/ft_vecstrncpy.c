/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecstrncpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:41:27 by hohayrap          #+#    #+#             */
/*   Updated: 2021/11/01 19:53:21 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_vecstrinit(int size)
{
	char	**vec;

	vec = (char **)ft_calloc(size, sizeof(char *));
	return (vec);
}

char	**ft_vecstrncpy(char **vecstr, int n)
{
	char	**vecstrcpy;
	int		index;

	index = -1;
	vecstrcpy = (char **)malloc(sizeof(char *) * n + 1);
	while (vecstr[++index] && index < n)
		vecstrcpy[index] = ft_strdup(vecstr[index]);
	vecstrcpy[index] = NULL;
	return (vecstrcpy);
}

char	**ft_vecstrlcpy(char **vecstr, int start, int n)
{
	char	**vecstrcpy;
	int		index;

	index = start - 1;
	vecstrcpy = (char **)malloc(sizeof(char *) * n + 1);
	while (vecstr[++index] && index < n)
		vecstrcpy[index] = ft_strdup(vecstr[index]);
	vecstrcpy[index] = NULL;
	return (vecstrcpy);
}

char	**ft_vecstrcpy(char **vecstr)
{
	char	**vecstrcpy;
	int		index;
	size_t	len;

	index = -1;
	len = ft_vecstrlen(vecstr);
	vecstrcpy = (char **)malloc(sizeof(char *) * len + 1);
	while (vecstr[++index])
		vecstrcpy[index] = ft_strdup(vecstr[index]);
	vecstrcpy[index] = NULL;
	return (vecstrcpy);
}

char	**ft_fvecstrcpy(char **vecstr1, char **vecstr2)
{
	char	**vecstrcpy;
	int		index;
	int		len;

	index = 0;
	len = ft_vecstrlen(vecstr1);
	len += ft_vecstrlen(vecstr2);
	vecstrcpy = (char **)malloc(sizeof(char *) * len + 1);
	len = 0;
	while (vecstr1[index])
	{
		vecstrcpy[len++] = ft_strdup(vecstr1[index]);
		index++;
	}
	index = 0;
	while (vecstr2 != NULL && vecstr2[index])
	{
		vecstrcpy[len++] = ft_strdup(vecstr2[index]);
		index++;
	}
	vecstrcpy[len] = NULL;
	return (vecstrcpy);
}
