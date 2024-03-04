/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shanting_stack_helper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:02:48 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:16:21 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_print_shat_steak(t_global_stack *stack)
{
	t_shant_stack	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		printf("shating token =>%s\n", tmp->ast_node->token);
		tmp = tmp->next;
	}
}
