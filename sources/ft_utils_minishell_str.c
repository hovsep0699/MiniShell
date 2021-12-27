/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_minishell_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:46:40 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/06 14:22:49 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp_char(char *str, char c, int count)
{
	int	index;

	index = 0;
	if (str == NULL)
		return (-1);
	while (str[index] && index != count)
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

char	*ft_tolower_minishell(char *upper_str, int *len)
{
	char		*lower_case;
	int			qex;
	int			dqex;
	t_split		stru;

	*len = ft_zero_byte_strlen(upper_str) - ft_count_quote(upper_str);
	lower_case = (char *)ft_calloc(sizeof(char),*len + 1);
	stru.i = 0;
	stru.j = 0;
	qex = 1;
	dqex = 1;
	while (upper_str[stru.i])
	{
		if (ft_count_quote_character(upper_str[stru.i],
				&qex, &dqex))
			stru.i++;
		else if (upper_str[stru.i] == '\\' && (qex != 0 && dqex != 0))
			stru.i++;
		else if (upper_str[stru.i] >= 'A' && upper_str[stru.i] <= 'Z')
			lower_case[stru.j++] = upper_str[stru.i++] + 32;
		else
			lower_case[stru.j++] = upper_str[stru.i++];
	}
	return (lower_case);
}

int	free_space(char *clean_space)
{
	if (clean_space != NULL && ft_strlen(clean_space) != 0)
	{
		ft_strdel(&clean_space);
		clean_space = NULL;
	}
	return (1);
}

void	ft_char_pointer_erase(char *str, size_t it)
{
	char	*copy;
	size_t	index;
	size_t	copy_index;

	copy = (char *)malloc(sizeof(char) * ft_zero_byte_strlen(str));
	index = 0;
	copy_index = 0;
	while (str[index])
	{
		if (index == it)
		{
			++index;
			continue ;
		}
		copy[copy_index] = str[index];
		++index;
		++copy_index;
	}
	copy[++copy_index] = '\0';
	ft_strdel(&str);
	str = copy;
}

int	ft_default_set(t_dict *command)
{
	command->echo_option = 0;
	ft_strdel(&command->data);
	ft_strdel(&command->name_file);
	ft_strdel(&command->fname_file);
	command->quote_staet_new = 0;
	command->change_fd_in = -1;
	command->change_fd_out = -1;
	command->type_command = UNDEFINED;
	command->icom = 0;
	command->fr_command = FNONE;
	command->util_commant = NONE;
	command->last_command = 0;
	command->isparrent = 1;
	command->name_file = NULL;
	g_signal.heredoc = 0;
	command->fname_file = NULL;
	g_signal.is_read = 0;
	return (1);
}
