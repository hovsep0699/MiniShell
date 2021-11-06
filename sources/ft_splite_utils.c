/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splite_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:46:30 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/06 16:45:46 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_add_space(char *source, int count, int mod, int index)
{
	char	*tmp;
	int		i;
	char	tmp_character;
	int		j;

	i = 0;
	j = index;
	while (source[j])
	{
		tmp_character = source[j - 1];
		if (count == 0)
			return (tmp);
		if (count == 1 && j == index + 1)
			source[j] = ' ';
		if (count == 2)
			source[j + 1] = ' ';
		if (count == 3)
		{
			source[j] = ' ';
			source[j + 2] = ' ';
			j += 1;
		}
		source[j] = tmp_character;
	}
	return (tmp);
}

int	ft_len_array(char *splite_array)
{
	int	i;
	int	state;
	int	count;

	i = 0;
	state = 0;
	count = 0;
	while (splite_array[i])
	{
		if ((splite_array[i] == '|' || splite_array[i] == '>'
				|| splite_array[i] == '<' || splite_array[i] == ';') && i != 0)
		{
			if (splite_array[i - 1] != ' ')
				count++;
			if (splite_array[i + 2] != ' ')
				count++;
			if ((ft_strncmp(splite_array + i, "<>", 2) == 0)
				|| (ft_strncmp(splite_array + i, ">>", 2) == 0))
				i++;
			state = 0;
		}
		i++;
	}
	return (count + i);
}

void	change_splitem(char *splite_array, t_split *splvar, char *str)
{
	if (str[splvar->i - 1] != ' ')
		splite_array[splvar->j++] = ' ';
	if ((ft_strncmp(str + splvar->i, "<<", 2) == 0)
		|| (ft_strncmp(str + splvar->i, ">>", 2) == 0))
	{
		splite_array[splvar->j++] = str[splvar->i++];
		splite_array[splvar->j++] = str[splvar->i];
	}
	else
		splite_array[splvar->j++] = str[splvar->i];
	if (str[splvar->i + 1] != ' ')
		splite_array[splvar->j++] = ' ';
	splvar->i++;
}

char	*enter_split_sapce(char **not_splite)
{
	char	*splite_array;
	char	*str;
	t_split	splvar;

	splvar.i = 0;
	splvar.state = 0;
	splvar.j = 0;
	str = ft_strdup(*(not_splite));
	if (!str)
		return (NULL);
	splvar.len = ft_len_array(str);
	splite_array = ft_calloc(splvar.len + 1, sizeof(char));
	while (str[splvar.i])
	{
		if ((str[splvar.i] == '|' || str[splvar.i] == '>'
				|| str[splvar.i] == '<' || str[splvar.i] == ';')
			&& splvar.i != 0)
			change_splitem(splite_array, &splvar, str);
		else
			splite_array[splvar.j++] = str[splvar.i++];
	}
	ft_strdel(&str);
	return (splite_array);
}
