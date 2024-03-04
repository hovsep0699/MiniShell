/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:55:47 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:09:45 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "shell.h"

t_function_entity		*ft_entity_to_function(t_hash_entity *hash);
t_env_entity			*ft_entity_to_env(t_hash_entity *hash);
t_hash_entity			*ft_function_to_entity(t_function_entity *func);
t_hash_entity			*ft_env_to_entity(t_env_entity *env);
int						ft_command_path(t_command *command, t_hash_table *env);
void					ft_hendle_pipe(t_vector *pipe_fd, \
							size_t pipe_iter, t_io io);
void					ft_handle_redirect_ios(t_io io);
char					*ft_get_last_arg(t_command *command);
int						ft_open_process_for_pipe(t_ast_node *tree, \
							t_process_info *info, size_t *pipe_iter);
void					ft_execute_part(t_ast_node *tree, \
							t_process_info *info, size_t *pipe_iter);
void					ft_restore_std_io(t_io io);
int						ft_handle_external(t_process_info *info);
int						ft_executor_with_list(t_process_info *info);
void					ft_shunting_yard_step1(t_list_token **list, \
							t_for_shunting_yard *model);
void					ft_shunting_yard_step2(t_for_shunting_yard *model);
size_t					ft_pipe_count_tree(t_ast_node *tree);
int						ft_execute_command(t_process_info *info);
void					ft_executor(t_symbol_table *table, t_container cont);
void					ft_handle_child_process(t_process_info *info, \
							int is_pipe);
int						ft_ignore_symbol(char *str, char sym, size_t i);
size_t					ft_count_replace_len(char *arg, \
							t_symbol_table *symbol_table, \
							t_expand_type isexpand);
int						ft_variable_identifier(char *ident);
char					*ft_count_replace(char *arg, \
						t_symbol_table *symbol_table, t_expand_type isexpand);
void					ft_expand_env(t_command *command, \
							t_symbol_table *table);
void					ft_open_file(t_process_info *info, t_vector *fd_vector);
t_vector				ft_open_pipe_fd(size_t pipe_count);
void					ft_open_all_fd(t_ast_node *ast_node, \
							t_process_info *info);
void					ft_close_fd(t_vector *fd_vector);
void					ft_open_type(t_redirect *redirect, \
							t_process_info *info, t_vector *fd_vector);
int						ft_partition(char **arr, int low, int high);
void					ft_quicksort(char **arr, int low, int high);
t_hash_table_arr		ft_sort_env(t_hash_table *table);
t_entity_table			*ft_init_entity_table(size_t initialCapacity, \
							t_hash_type type);
t_hash_table			*ft_init_hash_table(size_t initialCapacity, \
							t_hash_type type);
void					ft_init_entity_list(t_hash_entity_list *list);
size_t					ft_hash_entity(size_t capacity, char *key);
t_function_entity		*ft_create_function_entity(char *key, void *data);
t_env_entity			*ft_create_env_entity(t_hash_data data);
void					ft_push_entity(\
							t_hash_entity_list *lst, \
							t_hash_data data, t_hash_type type);
void					ft_resize_entity(t_hash_table *table, \
							size_t new_capacity);
void					ft_insert_entity(t_hash_table *table, t_hash_data data);
t_function_callback		ft_get_function(t_hash_table *table, char *key);
t_function_entity		*ft_get_function_entity(t_hash_table *table, char *key);
t_env_entity			*ft_get_env_entity(t_hash_table *table, char *key);
char					*ft_get_env(t_hash_table *table, char *key);
void					ft_set_env(t_hash_table *table, t_hash_data data);
void					print_env(t_hash_table *env, \
							t_visibility_type visibility);
t_hash_table			*ft_create_env(char **env);
t_hash_table			*ft_create_func_table(void);
void					ft_pop_entity(t_hash_table *table, char *key);
t_hash_table_arr		ft_convert_env_to_args(t_hash_table *env, \
							t_visibility_type visibility, int mode);
void					ft_free_hash_table(t_hash_table *table);
void					print_env_table(t_hash_table_arr arr);
void					ft_clear_hash_table(t_hash_table *table);
int						ft_isquot(const char *end_of_file);
char					*ft_generate_filename(void);
char					*ft_substr_c(char *line, char c);
void					ft_replace_all(char **line, \
							char *src_env, char *chang_env);
void					ft_hendle_env_variable(char **line, t_hash_table *env);
int						ft_open_heredoc(t_redirect	*red, t_hash_table *env);
void					sigint_handler(int signum);
void					ft_sigquit_handler(int signum);
void					ft_child_sigint(int num);
void					ft_heredoc_signal(int num);
t_symbol_table			*ft_create_symbol_table(char **env);
void					ft_clear_symbol_table(t_symbol_table *table);
void					ft_init_arrey(t_vector *tab, \
							size_t size);
void					ft_push_arrey(t_vector *tab, \
							int val);
int						ft_sig(void);
int						ft_is_dir(char *path);
char					*ft_get_prefix(char *path, char *path_exec);
int						ft_find_from_env(char **path, \
							char *path_exec, t_hash_table *env);
void					ft_hendle_pipe(t_vector *pipe_fd, \
							size_t pipe_iter, t_io io);
void					ft_handle_redirect_ios(t_io io);
char					*ft_get_last_arg(t_command *command);
void					ft_handle_external_command(t_command *command, \
							t_symbol_table *table, \
							char **env);
t_function_callback		ft_handle_pipe_builtins(int is_pipe, \
							t_process_info	*info);
void					ft_remove_empty_args(t_command *command);
char					*ft_get_pattern(char *arg, \
							size_t i, size_t *index_quot);
int						ft_ignore_symbol(char *str, char sym, size_t i);
size_t					ft_get_length(char *arg, size_t i, \
							size_t start, t_symbol_table *table);
void					ft_remove_empty_args(t_command *command);
size_t					ft_size_variable_env(char *arg, \
							t_symbol_table *symbol_table);
size_t					ft_count_replace_len(char *arg, \
							t_symbol_table *symbol_table, \
							t_expand_type isexpand);
size_t					ft_vulue_variable_env(char *arg, char *expand, \
							t_symbol_table *symbol_table);
int						ft_variable_identifier(char *ident);
void					ft_replace_pattern_part(char *expand, \
							t_expand_token *exp, \
							t_symbol_table *table);
void					ft_handle_exp_quotes(t_expand_token *exp, \
							t_symbol_table *table);
size_t					ft_copy_pattern(t_expand_token expand, \
							t_symbol_table *table, size_t start);
t_file_mode				ft_init_mode(t_token_type type);
int						ft_open_file_type_mode(t_redirect *redirect, \
							t_process_info *info, t_vector *fd_vector, \
							t_file_mode modes);
int						ft_open_with_mode(t_redirect *redirect, \
							t_file_mode modes, t_process_info *info);
int						ft_partition(char **arr, int low, int high);
void					ft_quicksort(char **arr, int low, int high);
t_hash_table_arr		ft_sort_env(t_hash_table *table);
void					ft_free_entity_dispatch(t_hash_type type, \
							t_hash_entity *node);
void					ft_handle_env_key_part(t_hash_data data, \
							t_hash_table *table);
void					ft_dispatch_container(t_container cont, \
							t_process_info *info);
void					ft_replace_all(char **line, char *src_env, \
							char *change_env);
char					*ft_generate_filename(void);
void					ft_restore_and_close(int here_fd, int stdio);
int						ft_isquot(const char *end_of_file);
size_t					ft_eof_length(char *end_of_file);
char					*ft_ignor_eof_quots(char *end_of_file);
void					ft_fill_eof_str(char *end_of_file, char *eof_key);
void					ft_handle_args(t_list_token *list, char **args);
void					ft_update_env_exit(t_container cont, \
							t_symbol_table *table);
void					ft_push_history(t_history *hist, char *val);
void					ft_init_history(t_history *hist, size_t size);

#endif