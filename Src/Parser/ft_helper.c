/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:55:56 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:16:16 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_get_pid(t_container cont, t_hash_table *env)
{
	char	*p_id;
	pid_t	pid;

	(void)cont;
	pid = fork();
	if (pid < 0)
		return ;
	else if (pid == 0)
		exit(EXIT_SUCCESS);
	else
	{
		wait(NULL);
		g_global_state.pid = (pid - 1);
		p_id = ft_itoa(pid - 1);
		ft_set_env(env, (t_hash_data){"$", p_id, HIDDEN});
		free(p_id);
	}
}

int	ft_should_ast_create(t_list_token *list)
{
	size_t	pc;
	char	*tok;
	t_token	*temp;
	int		is_pipe;

	pc = 0;
	is_pipe = 0;
	temp = list->head;
	while (temp)
	{
		tok = temp->token;
		while (*tok)
		{
			if (*tok == '|' || *tok == '&')
			{
				is_pipe = 1;
				break ;
			}
			++tok;
		}
		if (temp->type == PIPE || temp->type == AND || is_pipe)
			pc++;
		temp = temp->next;
	}
	return (pc != 0);
}

int	ft_should_ast_created(t_list_token *list)
{
	size_t	pc;
	t_token	*temp;

	pc = 0;
	temp = list->head;
	while (temp)
	{
		if (ft_isoperator(temp->type) || ft_is_breckets(temp->type))
			pc++;
		temp = temp->next;
	}
	return (pc != 0);
}
