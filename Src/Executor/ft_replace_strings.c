/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:35:17 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:27 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_replace_part(char *start_offset, char *token_tmp, \
						size_t token_size, char *change_env)
{
	char	*end_offset;

	end_offset = ft_strdup(token_tmp + token_size);
	if (!end_offset)
		end_offset = ft_strdup("");
	start_offset = ft_substr(start_offset, 0, token_tmp - start_offset);
	start_offset = ft_gnl_strjoin(start_offset, change_env);
	start_offset = ft_gnl_strjoin(start_offset, end_offset);
	free(end_offset);
	return (start_offset);
}

void	ft_replace_all(char **line, char *src_env, char *change_env)
{
	size_t	token_size;
	char	*token_tmp;
	char	*start_offset;

	token_size = ft_strlen(src_env);
	start_offset = ft_strdup(*line);
	token_tmp = ft_strstr(start_offset, src_env);
	while (token_tmp)
	{
		if (token_size)
			start_offset = ft_replace_part(start_offset, \
						token_tmp, token_size, change_env);
		if (*token_tmp)
			token_tmp = ft_strstr(start_offset, src_env);
		else
			token_tmp = NULL;
	}
	free(*line);
	*line = start_offset;
}

char	*ft_generate_filename(void)
{
	static size_t	i;
	char			*id;
	char			*filename;

	filename = ft_strdup(HEREDOC_DIR"/.heredoc");
	if (i == 0)
	{
		i++;
		return (filename);
	}
	id = ft_itoa(i++);
	filename = ft_gnl_strjoin(filename, id);
	free(id);
	return (filename);
}
