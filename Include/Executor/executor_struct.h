/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:54:56 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:09:42 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_STRUCT_H
# define EXECUTOR_STRUCT_H

# include "parser_struct.h"
# include "tokenizer_struct.h"

typedef int							(*t_function_callback)();

typedef enum e_exec_type			t_exec_type;
typedef enum e_visibility_type		t_visibility_type;
typedef enum e_hash_type			t_hash_type;
typedef enum e_expand_type			t_expand_type;
typedef enum e_signal_type			t_signal_type;

typedef struct s_hash_entity		t_hash_entity;
typedef struct s_hash_entity_list	t_hash_entity_list;
typedef struct s_entity_table		t_entity_table;
typedef struct s_hash_table			t_hash_table;
typedef struct s_vector				t_vector;
typedef struct s_function_entity	t_function_entity;
typedef struct s_env_entity			t_env_entity;
typedef struct s_hash_table_arr		t_hash_table_arr;
typedef struct s_symbol_table		t_symbol_table;
typedef struct s_hash_data			t_hash_data;
typedef struct s_process_info		t_process_info;
typedef struct s_expand_token		t_expand_token;
typedef struct s_file_mode			t_file_mode;
typedef struct s_hash_iterate		t_hash_iterate;
typedef struct s_history			t_history;

enum e_signal_type
{
	SIGNORMAL,
	SIGHEREDOC,
	SIGCHILD
};

enum e_exec_type
{
	LIST = 1L << 0,
	TREE = 1L << 1
};

enum e_hash_type
{
	FUNCTION,
	ENV
};

enum e_expand_type
{
	EXPAND,
	NOEXPAND
};

enum e_visibility_type
{
	NORMAL	= 1L << 0,
	VENV	= 1L << 1,
	EXPORT	= 1L << 3,
	HIDDEN	= 1L << 2,
};

struct s_hash_entity
{
	char				*key;
	t_hash_entity		*next;
};

struct s_hash_entity_list
{
	t_hash_entity		*head;
	t_hash_entity		*tail;
	size_t				size;
};

struct s_entity_table
{
	t_hash_type			type;
	t_hash_entity_list	*entity;
	size_t				size;
	size_t				capacity;
};

struct s_hash_table
{
	t_entity_table	*table;
};

struct s_hash_data
{
	char				*key;
	void				*data;
	t_visibility_type	type;
};

struct s_function_entity
{
	t_hash_entity		base;
	t_function_callback	function;
};

struct s_env_entity
{
	t_hash_entity		base;
	t_visibility_type	visibility;
	char				*value;
};

struct s_hash_table_arr
{
	char				**table;
	size_t				size;
};

struct s_symbol_table
{
	t_hash_table		*env;
	t_hash_table		*function;
};

struct s_vector
{
	int					*arr;
	size_t				size;
	size_t				capacity;
};

struct s_process_info
{
	t_command			*command;
	t_io				io;
	t_symbol_table		*table;
	t_vector			pipe_fd;
	size_t				pipe_iter;
	size_t				pipe_count;
	int					status;
	t_hash_table_arr	env;
	int					is_builtin;
};

struct s_expand_token
{
	size_t				index_quot;
	size_t				size;
	size_t				index;
	char				*for_rep;
	char				*token;
};

struct s_file_mode
{
	int					access_mode;
	int					open_mode;
	t_token_type		mode;
	int					is_heredoc;
	int					is_input;
};

struct s_hash_iterate
{
	int					mode;
	t_visibility_type	visibility;
	t_hash_entity		*entity;
	size_t				pos;
};

struct s_history
{
	char				**lines;
	size_t				size;
	size_t				capacity;
};

#endif