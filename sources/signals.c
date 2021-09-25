#include "minishell.h"

void    ft_process_signal(int signal)
{
    if (signal == SIGQUIT)
        exit(0);
}