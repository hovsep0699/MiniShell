#include "minishell.h"

int ft_print_echo(t_last_command *command_shablon, char **envp_my, char **data,int count)
{
	write(1, command_shablon->data, ft_zero_byte_strlen(command_shablon->data));
	if(command_shablon->echo_option != 1)
			write(1,"\n",1);
		return(1);
}

int	ft_exit(t_last_command *command_shablon, char **envp_my, char **data, int count)
{
	int exit_status;
	int index;
	bool is_error;

	index = 0;
	is_error = false;
	while (command_shablon->data[index] && ft_isspace(command_shablon->data[index])) ++index;
	if (!command_shablon->data[index])
		is_error = true;
	else
	{
		while (command_shablon->data[index] && ft_isdigit(command_shablon->data[index])) ++index;
		--index;
		if (!command_shablon->data[index] || (!ft_isdigit(command_shablon->data[index]) && !ft_isspace(command_shablon->data[index])))
		{
			printf("ok %c\n", command_shablon->data[index]);
			is_error = true;
		}
		else
			while (command_shablon->data[++index] && ft_isspace(command_shablon->data[index])) ;

	}
	// --index;
	if (command_shablon->data[index] && !is_error)
		is_error = true;
	if (is_error)
	{
		printf("%s %s: %s: %s\n", "exit", "bash",command_shablon->data, "numeric argument required");
		exit_status = COMMAND_NOT_FOUND;
	}
	else
	{
		if (!command_shablon->data)
			exit_status = 0;
		else
			exit_status = ft_atoi(command_shablon->data);
	}
	ft_last_command_destructor(command_shablon);
	ft_vecstrdel(&data);
	exit(exit_status);
}