/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:08:55 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:10:08 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "shell.h"

/**
 * Src/Tokenizer/ft_balanced.c
 */
int				ft_balanced(char *line);

/**
 * Src/Tokenizer/ft_get_line.c'.c
 */
char			*ft_get_line(void);

/**
 * Src/Tokenizer/ft_list_helpers.c
 */
t_list_token	*ft_sublist(t_token *start, t_token *end);
t_token			*ft_find_list(t_token_type type, t_token *start);
t_token			*ft_find_close_list(t_token *open_brac);

/**
 * Src/Tokenizer/ft_list_method.c
 */
t_list_token	*ft_init_list(void);
void			ft_init_token(t_token *node, int type, char *elem);
void			ft_push_back(t_list_token *list, int type, const char *token);
void			ft_push_front(t_list_token *list, int type, const char *token);
void			ft_pop_front(t_list_token *list);
void			ft_pop_back(t_list_token *list);
void			ft_free_list(t_list_token *list);
void			ft_print_list(t_token *list);

/**
 * Src/Tokenizer/ft_split_token.c
 */
void			ft_split_token(t_list_token *list);

/**
 * Src/Tokenizer/ft_stack_method.c
 */
t_stack			*ft_initialize_stack(void);
int				ft_is_empty(t_stack *stack);
int				ft_is_empty(t_stack *stack);
void			ft_push_stack(t_stack *stack, char item);
char			ft_pop_stack(t_stack *stack);
void			ft_free_stack(t_stack *stack);

/**
 * Src/Tokenizer/ft_tokenizer.c
 */
int				ft_ignore_quots(char *str, char quot, size_t i);
char			*ft_tokenize_with_delims(char *str, char *delim, int *type);
char			*ft_tokenize_with_space(char *expr, int *type);
t_list_token	*ft_tokenize_string_space(char *input);
t_list_token	*ft_tokenize(char *input, char *delims);

/**
 * Src/Tokenizer/ft_types.c
 */
int				ft_is_redirection(t_token_type type);
int				ft_is_breckets(t_token_type type);
int				ft_is_special_node(t_token_type type);
int				ft_isoperator(t_token_type type);
int				ft_iscommand(t_token_type type);
char			*ft_get_type(t_token_type type);
t_token_type	ft_get_type_map(int type);

int				ft_is_redirect_type_map(int type);
int				ft_is_operator_type_map(int type);
int				ft_is_command_type_map(int type);
int				ft_is_redirect_type(t_token_type type);
int				ft_is_operator_type(t_token_type type);

void			ft_tokenize_delim_util(t_tokenize_wrap *wrap, int *type);
int				ft_tokenize_delim_helper(t_tokenize_wrap *wrap, char *delim, \
				int *type);
char			*ft_tokenize_with_delims(char *str, char *delim, int *type);
int				ft_tokenize_space_helper(t_tokenize_wrap *wrapper, int *type);
char			*ft_tokenize_with_space(char *expr, int *type);

#endif
