#ifndef SHELL_DEFINES_H
#define SHELL_DEFINES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
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
# define START 0
# define PARSER_ERROR -1
# define WRONG_INPUT -2
# define COMAND_NOT_FOUND -3
# define BAD_ASSIGNMENT -4
# define COMMAND_NOT_FOUND 127
# define UNPRINT_ERROR -10
# define INVAILDPARAMETERNAME -6
# define FIRSTDIGIT -8
# define SUCCESS 1
# define CHILD_PROC 0
# define PATH_SHOW_NUMBER 3
# define GREATHER 1
# define OPEN_ANGEL_BRACKETS 2
# define OPEN_CLOSE 4
# define DGREATHER 5
# define NOT_NEW_LINE 6
# define CHAR_QUATES 39
# define CHAR_DQUATES 34
# define TEXT_RED "\033[0;31m"
# define TEXT_BLACK "\033[0;30m"
# define TEXT_GREEN "\033[0;32m"
# define TEXT_YELLOW "\033[0;33m"
# define TEXT_BLUE "\033[0;34m"
# define TEXT_PURPLE "\033[0;35m"
# define TEXT_CYAN "\033[0;34m"
# define TEXT_WHITE "\033[0;37m"
# define SIGHUP  1
# define SIGINT  2
# define SIGQUIT 3
# define SIGILL  4
# define SIGTRAP 5
# define SIGABRT 6
# define STDIN_FILE 0
# define STDOUT_FILE 1
# define STDERR_FILE 2
# define MAX_BUILTIN_FUNCS 10
# define MAX_SIDE_FUNCS 6
# define MAX_FRONT_FUNCS 3


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