#include "minishell.h"

void ft_pipe_close(int fd)
{
	if (fd > 0)
		close(fd);
}
int	ft_pipe(t_last_command *command_shablon, char **envp_my, char **data, int count)
{
    int fd[2];
    if (pipe(fd) < 0)
        exit(1);
    if(fork() == 0)
    {       ft_putendl("\nchild\n");
        ft_pipe_close(fd[1]);
        dup2(fd[0], 0);
        command_shablon->change_fd_in = fd[0];
        command_shablon->isparrent = 0;

        ft_search_builtin_func(command_shablon)(command_shablon, envp_my, data, count);
        exit(0);
    }
    else
    { 
        ft_pipe_close(fd[0]);
        dup2(fd[1],1);
         command_shablon->change_fd_out = fd[1];
         command_shablon->isparrent = 1;
          return (2);
    }

}
