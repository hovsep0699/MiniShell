/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:00:56 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/28 21:06:25 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_STRUCTURES_H
# define SHELL_STRUCTURES_H

# include "shell_defines.h"

enum e_builtin_commands
{
	ECHO,
	EXPORT,
	UNSET,
	EXIT,
	ENV,
	CD,
	PWD,
	WWRITE,
	DDWRITE,
	UNDEFINED
};

enum e_front_commands
{
	FFREAD,
	FDREAD,
	FNONE
};

enum e_side_commands
{
	WRITE,
	READ,
	DWRITE,
	DREAD,
	PIPE,
	NONE
};
struct s_quote_check
{
	int	i;
	int	pipe_problem;
	int	flag_caharacter;
};
struct s_command_function
{
	t_builtin_commands	name;
	t_cmd_func			function;
};

struct s_front_function
{
	t_front_commands	name;
	t_cmd_func			function;
};

struct s_signal
{
	int			exit_status;
	int			is_read;
	pid_t		pid;
	int			heredoc;
};

struct s_command_side_function
{
	t_side_commands	name;
	t_cmd_func		function;
};

struct	s_dictionary
{
	char				*key;
	char				*item;
	struct s_dictionary	*next;
};

struct s_unset
{
	int				i;
	int				len;
	int				cind;
	int				eind;
	int				esp;
	int				dklen;
	t_dictionary	*tmp;
	t_dictionary	*provide;
};

typedef struct s_dictone
{
	t_dictionary	*ptr;
	int				index;
	int				index_item;
	int				len_items;
}	t_dictone;

typedef struct s_pipe
{
	int	len;
	int	i;
	int	fd[2];
}	t_pipe;

typedef struct s_split
{
	int	i;
	int	j;
	int	state;
	int	len;
}	t_split;

typedef struct s_eqstr
{
	char	*subjoin;
	int		i;
	int		len_key;
	int		quate_exist;
	int		dquate_exist;
	int		end_index;
	int		count;
}	t_eqstr;

struct	s_dict
{
	int						change_fd_in;
	int						change_fd_out;
	int						start_program;
	int						echo_option;
	int						quote_staet_new;
	int						isparrent;
	t_builtin_commands		type_command;
	t_side_commands			util_commant;
	t_front_commands		fr_command;
	int						icom;
	int						j;
	int						last_command;
	int						nerar_exeption;
	char					*data;
	char					*output_data;
	char					*fname_file;
	char					*name_file;
	int						fd[2];
	bool					is_parent;
	char					*line;
	t_dictionary			*variable_dic;
	t_command_function		functions[MAX_BUILTIN_FUNCS];
	t_command_side_function	side_functions[MAX_SIDE_FUNCS];
	t_front_function		front_function[MAX_FRONT_FUNCS];
	int						i;
};

#endif
