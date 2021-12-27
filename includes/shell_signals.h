#ifndef SHELL_SIGNALS_H
#define SHELL_SIGNALS_H

# include "shell_structures.h"

void						ft_signal_handle(int signum);
t_string					ft_get_put_terminal(void);
void						s_int(int signum);
void						s_quit(int signum);
int							write_ernno(char *str_errno, int errno_cod, int fd);
int							syntax_error(char *str);
void						ft_putcommanderror(t_dict *dict, int errnum);
void						set_default_gloabl(void);
int							ft_fd_open(t_dict *command);
int							ft_process_signal(t_dict *lcmd);
void						export_error(char *str_exeption);
void						errno_print(char *ernno_str);
void						file_errno(char *ernno_str, char *name_file);
void						ft_exitcod(t_eqstr *equ);
int							ft_ret_end(t_dict *command);
int							ft_print_error(int errnum, \
				t_pipe *pips, char **str);
char						*ft_pipe(t_dict *command_shablon, char *data);
int							only_create_file(t_dict *dict);
int							print_pipe(int pipe_count);
void						ft_setenv(char **envp, char *key, char *value);
void						ft_pipe_close(int fd);
t_eqstr						ft_eqdef(char *s1, char *pars_str);
int							ft_default_set(t_dict *command);
int							ft_setechoopt(t_dict *dict);

#endif