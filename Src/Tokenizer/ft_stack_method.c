/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_method.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:34:11 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:18:03 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_stack	*ft_initialize_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

int	ft_is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

void	ft_push_stack(t_stack *stack, char item)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->data = item;
	new_node->next = stack->top;
	stack->top = new_node;
}

char	ft_pop_stack(t_stack *stack)
{
	char	item;
	t_node	*temp;

	if (ft_is_empty(stack))
		return (0);
	temp = stack->top;
	item = temp->data;
	stack->top = temp->next;
	free(temp);
	return (item);
}

void	ft_free_stack(t_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return ;
	while (!ft_is_empty(stack))
		ft_pop_stack(stack);
	stack = NULL;
}
