#include "minishell.h"

int ft_print_echo(t_last_command *command_shablon, char **envp, char **data,int count)
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
	if (!command_shablon->data)
		exit_status = 0;
	else
	{
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
		if (command_shablon->data[index] && !is_error)
			is_error = true;
		if (is_error)
		{
			printf("%s %s: %s: %s\n", "exit", "bash",command_shablon->data, "numeric argument required");
			exit_status = COMMAND_NOT_FOUND;
		}
		else
			exit_status = ft_atoi(command_shablon->data);
	}
	ft_vecstrdel(&data);
	ft_last_command_destructor(command_shablon);
	exit(exit_status);
}

int	ft_cd(t_last_command *command_shablon, char **envp, char **data, int count)
{
	int err;
	int end;
	char new_path[PATH_MAX];

	if (!command_shablon->data)
		return 0;
	err = chdir(command_shablon->data);
	
	if (err == -1)
	{
		printf("%s\n", strerror(errno));
		return errno;
	}
	getcwd(new_path, PATH_MAX);
	change_item(find_data("PWD",command_shablon->variable_dic),find_data_int("OLDPWD=",command_shablon->variable_dic),command_shablon->variable_dic);
	change_item(new_path, find_data_int("PWD=",command_shablon->variable_dic),command_shablon->variable_dic);
	
	return 0;
}

int	ft_pwd(t_last_command *command_shablon, char **envp_my, char **data, int count)
{
ft_putendl("\n\n\nparent\n");
	printf("%s\n", find_data("PWD",command_shablon->variable_dic));
	return 0;
}