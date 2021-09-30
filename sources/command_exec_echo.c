#include "minishell.h"

int ft_print_echo(t_last_command *command_shablon, char **envp, char **data,int count)
{
	// ft_setenv(envp, "PWD", "value");
	// printf("%s\n", getenv("PWD"));
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
	ft_last_command_destructor(command_shablon);
	ft_vecstrdel(&data);
	exit(exit_status);
}
// extern char **envv;
int	ft_cd(t_last_command *command_shablon, char **envp, char **data, int count)
{
	int err;
	int end;
	char *new_path;

	if (!command_shablon->data)
		return 0;
	// new_path = ft_calloc(PATH_MAX, sizeof(char));
	// if (getcwd(new_path, sizeof(new_path)) == NULL)
    //   perror("getcwd() error");
    // else
    //   printf("current working directory is: %s\n", new_path);
	err = chdir(command_shablon->data);
	if (err == -1)
	{
		printf("%s\n", strerror(errno));
		return errno;
	}
	return 0;
}

int	ft_pwd(t_last_command *command_shablon, char **envp_my, char **data, int count)
{

	printf("%s\n", getenv("PWD"));
	return 0;
}