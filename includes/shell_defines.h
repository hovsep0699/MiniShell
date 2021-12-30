/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:00:44 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/30 14:53:14 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_DEFINES_H
# define SHELL_DEFINES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>
# include <errno.h>
# include <dirent.h>
# include <stdio.h>
# include "Libft_Vache.h"
# include "cstring.h" 
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/ioctl.h>

# define MAX_EXIT_STATUS 255
# define COMMAND_NOT_FOUND 127
# define SUCCESS 1
# define CHILD_PROC 0
# define CHAR_QUATES 39
# define CHAR_DQUATES 34
# define SIGHUP  1
# define SIGINT  2
# define SIGQUIT 3
# define SIGILL  4
# define SIGTRAP 5
# define SIGABRT 6
# define MAX_BUILTIN_FUNCS 10
# define MAX_SIDE_FUNCS 6
# define MAX_FRONT_FUNCS 3
# define SHELL_PROMPT "sh$> "

typedef struct s_dictionary				t_dictionary;
typedef struct s_front_function			t_front_function;
typedef struct s_signal					t_signal;
typedef enum e_builtin_commands			t_builtin_commands;
typedef enum e_side_commands			t_side_commands;
typedef enum e_front_commands			t_front_commands;
typedef struct s_dict					t_dict;
typedef struct s_command_function		t_command_function;
typedef struct s_command_side_function	t_command_side_function;
typedef struct s_quote_check			t_quote_check;
typedef struct s_unset					t_unset;
typedef int								(*t_cmd_func)\
(t_dict *, char **, char **, int);
extern t_signal							g_signal;

#endif