/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:09:01 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:10:05 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_STRUCT_H
# define TOKENIZER_STRUCT_H

# define SEPARATORS 		"|<>"
//;|&<>
# define OPERATORS			"|"

typedef struct s_stack				t_stack;
typedef struct s_node				t_node;
typedef struct s_token				t_token;
typedef struct s_list_token			t_list_token;

/**
 * @typedef t_token_type
 * @brief Enumerates different token types.
 */
typedef enum e_token_type			t_token_type;

typedef struct s_tokenize_wrapper	t_tokenize_wrapper;
typedef struct s_tokenize_wrap		t_tokenize_wrap;

enum e_token_type
{
	NNULL,						// NULL 
	TEXT		= 1L << 0,		//	Text
	PIPE		= 1L << 1,		//	|
	OR			= 1L << 2,		//	||
	JOB			= 1L << 3,		//	&
	AND			= 1L << 4,		//	&&
	SEMI		= 1L << 5,		//	;
	SEMITWO		= 1L << 6,		//	;;
	OPBREK		= 1L << 7,		// 	(
	CLBREK		= 1L << 8,		// 	)
	WRITE		= 1L << 9,		// 	>
	READ		= 1L << 10,		// 	<
	APPEND		= 1L << 11,		// >>
	HEREDOC		= 1L << 12,		// <<
	REDIRECT	= 1L << 13,
	ROOT		= 1L << 14,		// 	(AST) Root Node
	SUBSHELL	= 1L << 15,		//	Subshell Root Node
	COMMAND		= 1L << 16,		//	Command
	ARGUMENT	= 1L << 17		//	Argument
};

struct s_node
{
	char	data;
	t_node	*next;
};

struct s_stack
{
	t_node	*top;
};

struct s_token
{
	t_token_type		type;
	char				*token;
	int					quate_type;
	t_token				*next;
	t_token				*prev;
};

struct s_list_token
{
	t_token	*head;
	t_token	*tail;
	size_t	size;
};

struct s_tokenize_wrapper
{
	t_list_token	*list;
	t_list_token	*space_list;
	t_token			*tmp;
	t_token			*head;
	char			*token;
	char			*tmp_token;
	int				type;
};

struct s_tokenize_wrap
{
	size_t		index;
	char		*token_start;
	char		*next_token;
	int			type;
	int			is_one_sym;
};

#endif
//      sort -nr -k 5 <( ls -l /bin ) <( ls -l /usr/bin ) <( ls -l /sbin )
//      comm -12 <( sort file1 ) <( sort file2 )