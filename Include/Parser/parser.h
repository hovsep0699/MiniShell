/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:08:21 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:09:52 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "shell.h"

/**
 * Src/Parser/ft_ast_free.c
*/
void			ft_collect_ast_to_q(t_ast_node *tree, t_global_stack *q_node);
void			ft_free_redirect(t_redirect *redirect);
void			ft_free_arguments(t_argument *argument);
void			ft_close_command_fd(t_io io);
void			ft_free_command(t_command *command);
void			ft_free_tree(t_ast_node *tree);

/**
 * Src/Parser/ft_ast_method.c 
*/
t_global_tree	*ft_init_ast_tree(void);
t_ast_node		*ft_create_ast_node(t_token *token);
size_t			ft_ast_len(t_ast_node *root);
void			ft_init_ast_node(t_ast_node *node, t_token *token);
char			*ft_ast_strjoin(char *s1, char *s2);
t_ast_node		*ft_ast_left_most(t_ast_node *ast_node);

/**
 * Src/Parser/ft_ast_print.c
*/
void			print_redirect(t_ast_node *redirect);
void			print_argument(t_ast_node *arg);
void			print_command(t_ast_node *command, char *prefix, int is_root, \
				int is_left);
void			print_node_type(t_ast_node *node, char *prefix, int is_root, \
				int is_left);
void			ft_ast_print(t_ast_node *head, char *prefix, int is_left, \
				int is_root);

/**
 * Src/Parser/ft_build_command.c
*/
t_command		*ft_create_command(t_argument *argument, t_redirect *redirect, \
				t_ast_node base);
t_argument		*ft_create_argument(char **argument, t_ast_node base);
t_redirect		*ft_create_redirect(char *file_name, t_ast_node base, \
				t_redirect_side side);
void			ft_push_redirect(t_command *command, char *file_name, \
				t_token_type type, t_redirect_side side);
void			ft_handle_argument(t_list_token *lsit, t_command *command);
void			ft_handle_redirect(t_list_token *list, t_command *command);
t_command		*ft_handle_command(t_list_token *list);
void			ft_handle_argument_helper(t_token **token, size_t *index);

/**
 * Src/Parser/ft_casts.c
*/
t_ast_node		*ft_command_to_ast_node(t_command *cmd);
t_ast_node		*ft_redirect_to_ast_node(t_redirect *rd);
t_ast_node		*ft_argument_to_ast_node(t_argument *arg);
t_command		*ft_ast_to_command(t_ast_node *ast);
t_argument		*ft_ast_to_argument(t_ast_node *ast);
t_redirect		*ft_ast_to_redirect(t_ast_node *ast);

/**
 * Src/Parser/ft_helper.c
*/
int				ft_should_ast_create(t_list_token *list);
int				ft_should_ast_created(t_list_token *list);
void			ft_get_pid(t_container cont, t_hash_table *env);

/**
 * Src/Parser/ft_parser.c
*/
t_io			ft_init_io(void);
t_io			ft_init_io_std(void);
t_container		ft_parser(t_container cont, t_list_token *list);

/**
 * Src/Parser/ft_shanting_stack.c
*/
t_global_stack	*ft_init_shant_stack(void);
int				ft_is_shant_stack_empty(t_global_stack *stack);
t_shant_stack	*ft_push_shant_stack(t_global_stack *stack, \
				t_ast_node *ast_node);
void			ft_pop_shant_stack(t_global_stack *stack);
void			ft_free_shant_stack(t_global_stack *stack);
void			ft_print_shat_steak(t_global_stack *stack);

/**
 * Src/Parser/ft_shunting_yard.c
*/
t_ast_node		*ft_shunting_yard_build_ast(t_list_token *list);

/**
 * Src/Parser/ft_subshell.c
*/
void			ft_handle_subshell(t_list_token *list, t_command *command);
t_list_token	*ft_get_subshell_list(t_token *open_brek);
void			ft_remove_subshell(t_list_token *lst);
void			ft_remove_command_redirect(t_list_token *lst);
t_token			*ft_skip_subshell(t_token *list);
t_ast_node		*ft_get_subshell(t_token *open_brek);

void			ft_shunting_yard_step1(t_list_token **list, \
				t_for_shunting_yard *model);
void			ft_shunting_yard_step2(t_for_shunting_yard *model);

#endif
