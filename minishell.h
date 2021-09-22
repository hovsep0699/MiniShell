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
#include <readline/readline.h>
#include "Libft_Vache.h"
#include "cstring.h"
#include <readline/history.h>
//erorner
#define START 0
#define EXIT -7
#define PARSER_ERROR -1
#define WRONG_INPUT -2
#define COMAND_NOT_FOUND -3
#define BAD_ASSIGNMENT -4
#define COMMAND_NOT_FOUND -5
#define UNPRINT_ERROR -10
#define InvalidParameterName -6
#define FIRSTDIGIT -8
#define SUCCESS 1
//tiper
#define ECHO 1
#define EXPORT 2
#define UNSET 3
#define ENV 4
#define EXITE 5
//droshakner
#define GREATHER 1
#define OPEN_ANGEL_BRACKETS 2
#define PIPE 3
#define OPEN_CLOSE 4
#define DGREATHER 5
#define NOT_NEW_LINE 6
#define CHAR_QUATES 39
#define CHAR_DQUATES 34

typedef struct s_dictionary dictionary_t;


struct	s_dictionary
{
	char *key;
	char *item;
	struct	s_dictionary *next;
};
typedef struct	s_last_command
{
	int			start_program;
	int			echo_option;
	int 		quote_staet_new;
	size_t		exit_status;
	int 		rut;
	int			type_command;
	int			util_commant;
	int			index_command;
	int			last_command;
	int			nerar_exeption;
	int			dollar_exist;
	int			env_exist;
	char		*data;
	char		*output_data;
	char		*name_file;
	dictionary_t *variable_dic;
	int (*function_pointer[5][7])(struct	s_last_command *,char **, char **,int);

}				t_last_command;


int				get_next_line(int fd, char **line);
char			*ft_dis_strjoin(char *s1, char  *s2,int mod);
size_t		ft_joins(char const *s2, size_t i,int count, char *subjoin);
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
dictionary_t *ft_dictionary_create(char *items);
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

#endif