#include "minishell.h"

int	ft_fd_open(t_dict *command)
{
	dup2(command->fd[0], STDIN_FILENO);
	dup2(command->fd[1], STDOUT_FILENO);
	return (SUCCESS);
}
