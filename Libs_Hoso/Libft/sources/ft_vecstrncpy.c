/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecstrncpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:41:27 by hohayrap          #+#    #+#             */
/*   Updated: 2021/07/28 20:41:30 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

