/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:08:49 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:10:03 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <stddef.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include <signal.h>
# include <sys/stat.h>
# include <termios.h>

# ifndef READLINE_LIBRARY
#  define READLINE_LIBRARY 1
# endif

# ifndef HEREDOC_DIR
#  define HEREDOC_DIR "."
# endif

# include "readline/readline.h"
# include "readline/history.h"
# include "global_struct.h"
# include "libft.h"
# include "executor.h"
# include "parser.h"
# include "sematic.h"
# include "tokenizer.h"
# include "builtins.h"

void	ft_program(char **env);
void	ft_init_global_state(void);
void	ft_start_shell(char *line, t_list_token **list, t_container *container);
void	ft_free_container_dispatch(t_container container);
void	ft_handle_status(char *line, t_list_token	**list, \
						t_container *container);
void	ft_main_loop(t_container *container);
void	ft_history_cleanup(t_history *history);
void	ft_print_header(void);

#endif
