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
    pid_t id;

    i = 0;
    str = ft_split_Vache(data, '|', CHAR_QUATES, CHAR_DQUATES);
    // ft_strdel(&data);
    len = ft_vecstrlen(str);
    if(len == 1)
        return(str[0]);
    while (++i < len)
    {
        pipe(fd);
        id = fork();
        if (!id)
        {
            dup2(fd[1], STDOUT_FILENO);
            dup2(fd[0], STDIN_FILENO);
            if (i == 1)
            {
                command_shablon->change_fd_out = fd[1];
                ft_pipe_close(fd[0]);
            }
            else
            {
                command_shablon->change_fd_in = fd[0];
                command_shablon->change_fd_out = fd[1];
            }
            command_shablon->isparrent = 0;
            return(str[i - 1]);
        }
        else if(i == len - 1 && id != 0)
        {

            // dup2(STDOUT_FILENO, fd[1]);
            dup2(command_shablon->fd[1], STDOUT_FILENO);
            dup2(fd[0], STDIN_FILENO);
            command_shablon->change_fd_in = fd[0];
            ft_pipe_close(fd[1]);
        }
    }
            //     ft_putnbr(id);
            // ft_putchar('\n');
            // ft_putendl(str[len - 1]);
    return(str[len - 1]);
}
