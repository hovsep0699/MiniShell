/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shunting_yard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:00:12 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:16:45 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_shunting_yard_step1_util(t_for_shunting_yard *model)
{
	while (model->stack_opre->size && \
		!ft_iscommand(model->stack_opre->top->ast_node->token_type))
	{
		if (model->stack_oute->size)
			model->ast_right = model->stack_oute->top->ast_node;
		else
			model->ast_right = NULL;
		ft_pop_shant_stack(model->stack_oute);
		if (model->stack_oute->size)
			model->ast_left = model->stack_oute->top->ast_node;
		else
			model->ast_left = NULL;
		ft_pop_shant_stack(model->stack_oute);
		model->ast_node = model->stack_opre->top->ast_node;
		if (model->ast_left)
			model->ast_left->parent = model->ast_node;
		if (model->ast_right)
			model->ast_right->parent = model->ast_node;
		model->ast_node->left = model->ast_left;
		model->ast_node->right = model->ast_right;
		ft_push_shant_stack(model->stack_oute, model->ast_node);
		ft_pop_shant_stack(model->stack_opre);
	}
}

void	ft_shunting_yard_step1(t_list_token **list, t_for_shunting_yard *model)
{
	t_ast_node	*ast_node;

	while ((*list)->head)
	{
		ft_init_token(&model->token, \
			(*list)->head->type, ft_strdup((*list)->head->token));
		ft_pop_front(*list);
		if (!ft_iscommand(model->token.type))
		{
			ft_shunting_yard_step1_util(model);
			ast_node = ft_create_ast_node(&model->token);
			ft_push_shant_stack(model->stack_opre, ast_node);
		}
		else
		{
			ft_push_front(*list, model->token.type, model->token.token);
			model->command = ft_handle_command(*list);
			model->node = ft_command_to_ast_node(model->command);
			ft_push_shant_stack(model->stack_oute, model->node);
		}
		free(model->token.token);
	}
}

void	ft_shunting_yard_step2(t_for_shunting_yard *model)
{
	while (model->stack_opre->size)
	{
		if (model->stack_oute->size)
			model->ast_right = model->stack_oute->top->ast_node;
		else
			model->ast_right = NULL;
		ft_pop_shant_stack(model->stack_oute);
		if (model->stack_oute->size)
			model->ast_left = model->stack_oute->top->ast_node;
		else
			model->ast_left = NULL;
		ft_pop_shant_stack(model->stack_oute);
		model->ast_node = model->stack_opre->top->ast_node;
		if (model->ast_left)
			model->ast_left->parent = model->ast_node;
		if (model->ast_right)
			model->ast_right->parent = model->ast_node;
		model->ast_node->left = model->ast_left;
		model->ast_node->right = model->ast_right;
		ft_push_shant_stack(model->stack_oute, model->ast_node);
		ft_pop_shant_stack(model->stack_opre);
	}
}

t_ast_node	*ft_shunting_yard_build_ast(t_list_token *list)
{
	t_for_shunting_yard	model;

	model.stack_opre = ft_init_shant_stack();
	model.stack_oute = ft_init_shant_stack();
	model.ast_node = NULL;
	ft_shunting_yard_step1(&list, &model);
	ft_shunting_yard_step2(&model);
	if (list->size)
		ft_pop_front(list);
	model.ast_node = model.stack_oute->top->ast_node;
	ft_free_shant_stack(model.stack_oute);
	ft_free_shant_stack(model.stack_opre);
	return (model.ast_node);
}
