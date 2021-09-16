#include "minishell.h"

int ft_print_echo(t_last_command *command_shablon, char **envp_my, char **data,int count)
{
	ft_putstr_fd(command_shablon->data,1);
	if(command_shablon->echo_option != 1)
			write(1,"\n",1);
		return(1);
}
