/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waite_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:46:50 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/25 18:49:53 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ftsinglejoin(char *c)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	if (c == NULL)
		return (ft_strnull());
	while (c && c[j] != '\n' && c[j] != '\0')
		j++;
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (NULL);
	while (c[i] && i < j && c && c[i] != '\n')
	{
		str[i] = c[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_clean(char *bf, int length)
{
	int		i;
	int		j;
	char	*c;

	j = 0;
	i = 0;
	if (bf == NULL)
		return (NULL);
	while (bf[j] != '\n' && bf[j] != '\0')
		j++;
	if (bf[j] == '\0')
	{
		free(bf);
		return (NULL);
	}
	c = (char *)malloc(sizeof(char) * (length - j) + 1);
	while (bf[j] && bf)
	{
		c[i] = bf[j + 1];
		j++;
		i++;
	}
	c[i] = '\0';
	free(bf);
	return (c);
}

size_t	ft_joins(char const *s2, size_t i, int count, char *subjoin)
{
	int	j;

	j = 0;
	while (s2[j] && j < count)
	{
		subjoin[i] = s2[j];
		i++;
		j++;
	}
	subjoin[i] = '\0';
	return (i);
}

char	*ft_equal_strjoin(char *s1, t_dict *dict, char *pstr, int end)
{
	t_eqstr	equ;

	equ = ft_eqdef(s1, pstr);
	equ.subjoin = (char *)ft_calloc(sizeof(char), (equ.end_index
				+ (ft_zero_byte_strlen(pstr) - equ.count) + 1 + end));
	if (equ.end_index > 0)
		equ.subjoin = ft_strcpy(equ.subjoin, s1);
	while (pstr[equ.i])
		ft_join_util2(pstr, &equ, dict);
	if (!end)
		equ.subjoin[equ.end_index] = ' ';
	ft_strdel(&s1);
	return (equ.subjoin);
}
