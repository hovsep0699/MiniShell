/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecstrncpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:41:27 by hohayrap          #+#    #+#             */
/*   Updated: 2021/09/26 22:26:31 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_vecstrinit(int size)
{
	char **vec;

	vec = (char **)ft_calloc(size, sizeof(char *));
	return vec;
}


char **ft_vecstrncpy(char **vecstr, int n)
{
	char	**vecstrcpy;
	int		index;

	index = -1;
	vecstrcpy = (char **)malloc(sizeof(char *) * n + 1);
	while (vecstr[++index] && index < n)
		vecstrcpy[index] = ft_strdup(vecstr[index]);
	vecstrcpy[index] = NULL;
	return vecstrcpy;
}

#include <stdio.h>
char **ft_vecstrcpy(char **vecstr)
{
	char	**vecstrcpy;
	int		index;
	size_t	len;

	index = -1;
	len = ft_vecstrlen(vecstr);
	printf("%lu\n", len);
	vecstrcpy = (char **)malloc(sizeof(char *) * len + 1);
	while (vecstr[++index])
		vecstrcpy[index] = ft_strdup(vecstr[index]);
	vecstrcpy[index] = NULL;
	return vecstrcpy;
}

