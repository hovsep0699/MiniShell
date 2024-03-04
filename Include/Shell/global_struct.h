/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:08:40 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:09:59 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_STRUCT_H
# define GLOBAL_STRUCT_H

# include "executor_struct.h"
# include "parser_struct.h"
# include "sematic_struct.h"
# include "tokenizer_struct.h"

typedef struct s_container			t_container;

typedef struct s_global_state		t_global_state;

struct s_container
{
	t_exec_type		exec_type;
	t_io			fd;
	t_status_codes	exit_status;
	t_symbol_table	*table;
	union
	{
		t_global_tree	*tree;
		t_command		*command;
	};
};

struct s_global_state
{
	struct termios	orig_termios;
	t_signal_type	minishell_signal;
	pid_t			pid;
	t_history		history;
	int				heredoc_signal;
	int				permission_status;
	int				is_dir;
	char			*argument;
	int				last_in;
	int				is_tree;
};

extern t_global_state				g_global_state;

#endif