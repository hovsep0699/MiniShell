#include "minishell.h"

int ft_fd_open(t_last_command *command)
{
    command->fd[0] = dup(0);
    command->fd[1] = dup(1);
    dup2(command->fd[0],STDIN_FILENO);
    dup2(command->fd[1],STDOUT_FILENO);
    return(SUCCESS);
}
