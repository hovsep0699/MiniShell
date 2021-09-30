#ifndef START
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include "Libft_Vache.h"
#include "cstring.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <limits.h>

//erorner
#define START 0
// #define EXIT -7
#define PARSER_ERROR -1
#define WRONG_INPUT -2
#define COMAND_NOT_FOUND -3
#define BAD_ASSIGNMENT -4
#define COMMAND_NOT_FOUND 127
#define UNPRINT_ERROR -10
#define InvalidParameterName -6
#define FIRSTDIGIT -8
#define SUCCESS 1


#define PATH_SHOW_NUMBER 3
//tiper
// #define ECHO 1
// #define EXPORT 2
// #define UNSET 3
// #define ENV 4
// #define UNDEFINED 5
// #define EXIT 6
//droshakner
#define GREATHER 1
#define OPEN_ANGEL_BRACKETS 2
// #define PIPE 3
#define OPEN_CLOSE 4
#define DGREATHER 5
#define NOT_NEW_LINE 6
#define CHAR_QUATES 39
#define CHAR_DQUATES 34

#define TEXT_RED "\033[0;31m"
#define TEXT_BLACK "\033[0;30m"
#define TEXT_GREEN "\033[0;32m"
#define TEXT_YELLOW "\033[0;33m"
#define TEXT_BLUE "\033[0;34m"
#define TEXT_PURPLE "\033[0;35m"
#define TEXT_CYAN "\033[0;34m"
#define TEXT_WHITE "\033[0;37m"
// #define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
// #define clear() printf("\033[H\033[J")


#define SIGHUP  1   /* Hangup the process */ 
#define SIGINT  2   /* Interrupt the process */ 
#define SIGQUIT 3   /* Quit the process */ 
#define SIGILL  4   /* Illegal instruction. */ 
#define SIGTRAP 5   /* Trace trap. */ 
#define SIGABRT 6 	/* Abort. */

#define MAX_BUILTIN_FUNCS 8

#define MAX_SIDE_FUNCS 6


typedef struct s_dictionary dictionary_t;
typedef	enum e_builtin_commands t_builtin_commands;
typedef	enum e_side_commands t_side_commands;
typedef struct s_last_command t_last_command;
typedef struct s_command_function t_command_function;
typedef struct s_command_side_function t_command_side_function;
typedef	int (*cmd_func_t)(t_last_command *, char **, char **, int);
// typedef	int (**cmd_funcs_t[])(t_last_command *, char **, char **, int);

enum e_builtin_commands
{
	ECHO,
	EXPORT,
	UNSET,
	EXIT,
	ENV,
	CD,
	PWD,
	UNDEFINED
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

struct s_command_function
{
	t_builtin_commands name;
	cmd_func_t function;
};

struct s_command_side_function
{
	t_side_commands name;
	cmd_func_t function;
};

struct	s_dictionary
{
	char *key;
	char *item;
	struct	s_dictionary *next;
};
struct	s_last_command
{
	int						start_program;
	int						echo_option;
	int 					quote_staet_new;
	size_t					exit_status;
	int 					rut;
	t_builtin_commands		type_command;
	t_side_commands			util_commant;
	int						index_command;
	int						last_command;
	int						nerar_exeption;
	int						dollar_exist;
	int						env_exist;
	char					*data;
	char					*output_data;
	char					*name_file;
	int						fd[2];
	int						change_fd[2];
	dictionary_t			*variable_dic;
	t_command_function		functions[MAX_BUILTIN_FUNCS];
	t_command_side_function	side_functions[MAX_SIDE_FUNCS];
	// int (*function_pointer[5][7])(struct	s_last_command *,char **, char **,int);
};


/*    to do    */

// struct s_function_args
// {
// 	t_last_command lcmd;
// 	char **envp;
// 	char **data;
// 	int		count
// };
// cmd_funcs_t cmds = {ft_export, ft_write_file};

void ft_setenv(char **envp, char *key, char *value);

t_command_side_function		ft_side_funcs_default_constructor(void);
t_command_side_function		ft_side_funcs_constructor(t_side_commands name, cmd_func_t cmd);
t_command_function			ft_command_funcs_default_constructor(void);
t_command_function			ft_command_funcs_constructor(t_builtin_commands name, cmd_func_t cmd);

t_last_command	ft_last_command_constructor(void);
int				get_next_line(int fd, char **line);
char			*ft_dis_strjoin(char *s1, char  *s2,int mod);
size_t			ft_joins(char const *s2, size_t i,int count, char *subjoin);
int				ft_dis_strchr(const char *s, int c);
char			*ft_clean(char *bf, int length);
char			*ft_single_join();
char			*ft_strnull(void);
int 			ft_strcmp_char(char *str,char c,int count);
int 			ft_flag_find(char str);
char 			*enter_split_sapce(char *not_splite);
int 			ft_default_set(t_last_command *command);
void 			ft_print_welcome(char *path);
char			*ft_strjoin_minishell(char *s1, int start_index, int end_index,int isflag);
int 			system_command(char **command,t_last_command *command_list,char **envp_my,int count);
int 			exec_echo(char **arguments,t_last_command *comand_shablon, int count,char **envp_my);
int 			print_pipe(int pipe_count);
int 			free_space(char *clean_space);
int 			ft_print_echo(t_last_command *command_shablon, char **envp_my,char **data, int count);
void 			ft_dictionary_del(dictionary_t *del_stack);
void			ft_dictionaryadd_back(dictionary_t **lst, dictionary_t *new);
dictionary_t	*ft_dictionarylast(dictionary_t *lst);
dictionary_t	*ft_dictionary_create(char *items);
int				ft_dictionarysize(dictionary_t *stack);
int 			ft_alloc_split_minishell(char const *s, char c, char exp, char exp2);
char 			*find_data(char *key,dictionary_t *command);
char 			*ft_tolower_minishell(char *upper_str,int *len);
int 			ft_export(struct	s_last_command * dictioanry,char **envp, char **data,int count);
void 			ft_print_error(int exeption,char *str_exeption,char element_exeption,char *command_name);
int 			find_data_int(char *key,dictionary_t *command);
void 			change_item(char *new_item,int key_index,dictionary_t *dict);
char			*ft_equal_strjoin(char *s1,t_last_command *command_shablon,char *pars_str,int end_of_line);
int 			find_equal_part(char *str);
int 			ft_unset(struct	s_last_command * dictioanry,char **envp, char **data,int count);
void 			ft_dictionary_del_key(dictionary_t *del_stack);
int 			ft_write_file(struct	s_last_command * dictioanry,char **envp, char **data,int count);
int 			only_create_file(char *file_name,struct	s_last_command *dictioanry);
int 			ft_count_quote(char *s);
void			ft_char_pointer_erase(char *str, size_t it);
int 			ft_isalnum_str(char *str,int *i);
int 			ft_count_quote_character(char character,int *quoet_exist,int *dquoet_exist);
int 			ft_Dwrite_file(struct	s_last_command * dictioanry,char **envp, char **data,int count);
int 			ft_put_env_export(struct	s_last_command * dictionary,char **envp,char **data,int count);
int				ft_exit(t_last_command *command_shablon, char **envp_my, char **data, int count);
int				ft_fd_open(t_last_command *command);
void			ft_last_command_destructor(t_last_command *lcmd);
void			ft_process_signal(int signal);
cmd_func_t		ft_search_side_func(t_last_command *lcmd);
cmd_func_t		ft_search_builtin_func(t_last_command *lcmd);
t_last_command	ft_last_command_constructor();
int				ft_cd(t_last_command *command_shablon, char **envp_my, char **data, int count);
int				ft_pwd(t_last_command *command_shablon, char **envp_my, char **data, int count);
dictionary_t 	*ft_env_copy(char **env);
void			ft_dictionary_destructor(dictionary_t *dict);
#endif