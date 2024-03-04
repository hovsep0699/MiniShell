/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:37:00 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:01 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_is_valid_identifier(char *ident)
{
	size_t	i;

	i = 0;
	if (ft_isdigit(ident[i]))
		return (0);
	while (ident && ident[i])
	{
		if (!(ft_isalnum(ident[i]) || ident[i] == '_'))
			return (0);
		++i;
	}
	return (1);
}

char	*ft_export_get_key(char *token, char *plus)
{
	char	*key;

	if (*token)
	{
		*plus = token[ft_strlen(token) - 1];
		if (*plus == '+')
			key = ft_substr(token, 0, ft_strlen(token) - 1);
		else
			key = ft_substr(token, 0, ft_strlen(token));
	}
	else
		key = ft_strdup(token);
	return (key);
}

char	*ft_export_collect_data(char *line, t_hash_data *data, char *plus)
{
	size_t		len;
	char		*id;
	char		*tmp;

	id = ft_strchr(line, '=');
	if (id)
	{
		len = id - line;
		data->data = id + 1;
		if (!*(char *)data->data)
			data->data = "";
	}
	else
	{
		len = ft_strlen(line);
		data->data = NULL;
	}
	tmp = ft_substr(line, 0, len);
	data->key = ft_export_get_key(tmp, plus);
	if (!id)
		data->type = EXPORT;
	else
		data->type = NORMAL;
	return (tmp);
}
