/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:44:21 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:09:49 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCT_H
# define PARSER_STRUCT_H

# include "tokenizer_struct.h"

/**
 * @typedef t_ast_node
 * @brief Represents a node in the abstract syntax tree (AST).
 */
typedef struct s_ast_node			t_ast_node;

/**
 * t_ast_node	base;
 * t_argument	*argument;
 * t_redirect	*redirect;
*/
typedef struct s_command			t_command;

/**
 * t_ast_node	base;
 * char			**arguments;
*/
typedef struct s_argument			t_argument;
typedef struct s_redirect			t_redirect;

/**
 * @typedef t_token_type
 * @brief Enumerates different token types mapping.
 */
typedef enum e_token_map_type		t_token_map_type;

/**
 * @typedef t_quot_type
 * @brief Enumerates different quotation types.
 */
typedef enum e_quot_type			t_quot_type;

/**
 * @typedef t_global_tree
 * @brief Represents the global abstract syntax tree (AST).
 */
typedef struct s_global_tree		t_global_tree;

/**
 * 
 * Stack structure of the Shunting Yard algorithm.
 * 
 * This structs introduces two stack structures for 
 * handling abstract syntax trees (AST) during expression parsing.
*/
typedef struct s_global_stack		t_global_stack;

typedef struct s_shant_stack		t_shant_stack;

/**
 * 	NEXT_BRACE = 1L << 0,
 *	PREV_BRACE = 1L << 1
*/
typedef enum e_redirect_side		t_redirect_side;
// typedef void (*t_callback)(t_list_token* list);

typedef struct s_io					t_io;
typedef enum e_io_type				t_io_type;

typedef struct s_for_shunting_yard	t_for_shunting_yard;

struct s_io
{
	int	input;
	int	output;
	int	error;
};

enum e_io_type
{
	STDIN,
	STDOUT,
	STDERR
};

enum e_redirect_side
{
	NEXT_BRACE = 1L << 0,
	PREV_BRACE = 1L << 1
};

enum e_token_map_type
{
	MNNULL,
	MTEXT		= 1000,
	MPIPE		= 124,
	MOR			= -124,
	MJOB		= 38,
	MAND		= -38,
	MSEMI		= 59,
	MSEMITWO	= -59,
	MOPBREK		= 40,
	MCLBREK		= 41,
	MWRITE		= 62,
	MREAD		= 60,
	MAPPEND		= -62,
	MHEREDOC	= -60
};

enum e_quot_type
{
	UNQUOT		= 0,
	SINGL		= 27,
	DOUBLE		= 22
};

struct s_global_tree
{
	t_ast_node		*ast_node;
	size_t			tree_size;
};

/**
 * 
 * AST (Abstract syntax tree)
 */
struct s_ast_node
{
	t_token_type	token_type;
	t_quot_type		quate_type;
	char			*token;
	t_ast_node		*left;
	t_ast_node		*right;
	t_ast_node		*parent;
	t_global_stack	*subshell;
};

/**
 * 
 * 	t_ast_node		base;
 * 	t_argument		*argument;
 * 	t_redirect		*redirect;
*/
struct s_command
{
	t_ast_node	base;
	t_argument	*argument;
	t_redirect	*redirect;
	t_io		io;
};

struct s_argument
{
	t_ast_node	base;
	char		**arguments;
};

struct s_redirect
{
	t_ast_node		base;
	t_redirect_side	side;
	char			*argument;
};

struct s_global_stack
{
	t_shant_stack	*top;
	size_t			size;
};

struct s_shant_stack
{
	t_ast_node		*ast_node;
	t_shant_stack	*next;
};

struct s_for_shunting_yard
{
	t_token			token;
	t_command		*command;	
	t_ast_node		*node;
	t_ast_node		*ast_node;
	t_ast_node		*ast_left;
	t_ast_node		*ast_right;
	t_global_stack	*stack_opre;
	t_global_stack	*stack_oute;	
};

#endif
// typedef struct s_for_shunting_yard t_for_shunting_yard;

// struct s_for_shunting_yard
// {
// 	t_token			token;
// 	t_command		*command;	
// 	t_ast_node		*node;
// 	t_ast_node		*ast_node;
// 	t_ast_node		*ast_left;
// 	t_ast_node		*ast_right;
// 	t_global_stack	*stack_opre;
// 	t_global_stack	*stack_oute;	
// };
