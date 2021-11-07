/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:46:22 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/26 19:48:35 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring.h"
#include <stdio.h>

void	ft_string_reverse(t_string *str)
{
	ft_strdel(&str->data);
	str->data = ft_strrev(str->data);
}

void	ft_t_stringolower(t_string *str)
{
	int	index;

	index = -1;
	while (str->data[++index])
		str->data[index] += DIFF_ALPHA_CASES;
}

void	ft_t_stringoupper(t_string *str)
{
	int	index;

	index = -1;
	while (str->data[++index])
		str->data[index] -= DIFF_ALPHA_CASES;
}

bool	ft_string_compare(t_string *str1, t_string *str2)
{
	if (!ft_strcmp(str1->data, str2->data))
		return (true);
	return (false);
}

bool	ft_string_compare2(t_string *str1, char *str2)
{
	if (!ft_strcmp(str1->data, str2))
		return (true);
	return (false);
}
