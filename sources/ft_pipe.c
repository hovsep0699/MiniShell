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

    i = 0;
    str = ft_split_Vache(data, '|', CHAR_QUATES, CHAR_DQUATES);
    len = ft_vecstrlen(str);
    while (i < len)
    {
        pipe(fd);
       if(i == 0)
       {
        dup2(fd[1],STDOUT_FILENO);
        ft_pipe_close(fd[0]);
       }
       if()
    }
    
}
