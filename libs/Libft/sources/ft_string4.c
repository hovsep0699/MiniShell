/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:54:20 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/26 19:55:32 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring.h"
#include <stdio.h>

int	ft_string_rfind3(t_string *str, t_string *needle)
{
	return (ft_string_rfind2(str, needle->data));
}

void	ft_string_destructor(t_string *str)
{
	ft_strdel(&str->data);
	str->size = 0;
}

void	ft_string_join(t_string *str, t_string *str2)
{
	str->data = ft_realloc_strjoin(str->data, str2->data);
	str->size = ft_zero_byte_strlen(str->data);
}

void	ft_string_join2(t_string *str, char *str2)
{
	str->data = ft_realloc_strjoin(str->data, str2);
	str->size = ft_zero_byte_strlen(str->data);
}

void	ft_string_substr(t_string *str, t_string *new, size_t start, size_t len)
{
	ft_strdel(&new->data);
	new->data = ft_substr(str->data, start, len);
}
