/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:05:13 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:17:31 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_get_line(void)
{
	char	*line;

	line = readline("minishell $> ");
	if (line)
	{
		add_history(line);
		ft_push_history(&g_global_state.history, line);
	}
	return (line);
}
