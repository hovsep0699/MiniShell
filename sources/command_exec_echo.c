#include "minishell.h"

int ft_print_echo(struct	s_last_command *command_shablon, char **envp_my, char **data,int count)
{
	write(1,command_shablon->data,ft_zero_byte_strlen(command_shablon->data));
	if(command_shablon->echo_option != 1)
			write(1,"\n",1);
		return(1);
}
