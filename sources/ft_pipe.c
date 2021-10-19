#include "minishell.h"

void ft_pipe_close(int fd)
{
	if (fd > 0)
		close(fd);
}
char *ft_pipe(t_last_command *command_shablon, char *data)
{
    char **str;
    int len;
    int i;
    int fd[2];
    char *pipe_line;
    pid_t id;

    i = 0;
    str = ft_split_Vache(data, '|', CHAR_QUATES, CHAR_DQUATES);
    len = ft_vecstrlen(str);
    if(len <= 1)
    {
        pipe_line = ft_strdup(str[i]);
        ft_vecstrdel(&str);
        return(pipe_line);
    }
    i = len;
    while (i > 1)
    {
        i--;
        pipe(fd);
        id = fork();

        if (id > 0)
        {
            dup2(fd[0], STDIN_FILENO);
            command_shablon->change_fd_in = fd[0];
            ft_pipe_close(fd[1]);
            if (i == len - 1 )
                command_shablon->isparrent = 1;
            else
                command_shablon->isparrent = 0;
            pipe_line = ft_strdup(str[i]);
            ft_vecstrdel(&str);
            return(pipe_line);
        }
        if(i > 0)
        {
            dup2(fd[1], STDOUT_FILENO);
            command_shablon->change_fd_out = fd[1];
            ft_pipe_close(fd[0]);
            command_shablon->isparrent = 0;
        }
    }
    pipe_line = ft_strdup(str[0]);
    ft_vecstrdel(&str);
    return(pipe_line);
}
