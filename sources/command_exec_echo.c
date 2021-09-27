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
int	ft_cd(t_last_command *command_shablon, char **envp_my, char **data, int count)
{
	int err;
	int end;
	// string_t absolute_path;
	char *new_path;
	// printf("okkk\n");
	// absolute_path = ft_string_default_constructor();
	// absolute_path.resize(&absolute_path, PATH_MAX);
	if (!command_shablon->data)
		return 0;
	new_path = calloc(PATH_MAX, sizeof(char));
	// ft_memmove(new_path, command_shablon->data, ft_zero_byte_strlen(command_shablon->data));
	if (getcwd(new_path, sizeof(new_path)) == NULL)
      perror("getcwd() error");
    else
      printf("current working directory is: %s\n", new_path);
	// printf("path: %s\n", new_path);
	// getcwd(new_path, PATH_MAX);
	// printf("new: %s\n", new_path);
	// printf("%s\n", getenv("PWD"));
	// absolute_path = ft_string_constructor(new_path);
	// end = absolute_path.rfind2(&absolute_path, command_shablon->data);
	// absolute_path.erase_between(&absolute_path, ft_zero_byte_strlen(command_shablon->envp[command_shablon->pwd_index]), end + ft_zero_byte_strlen(command_shablon->data));
	// printf("%s\n",absolute_path.data);
	// ft_string_destructor(&absolute_path);
	err = chdir(command_shablon->data);
	if (err == -1)
	{
		printf("%s\n", strerror(errno));
		return errno;
	}
	ft_strdel(&command_shablon->envp[command_shablon->oldpwd_index]);
	command_shablon->envp[command_shablon->oldpwd_index] = ft_strdup("OLDPWD=");
	command_shablon->envp[command_shablon->oldpwd_index] = ft_realloc_strjoin(command_shablon->envp[command_shablon->oldpwd_index], command_shablon->envp[command_shablon->pwd_index] + ft_strlen("PWD="));
	ft_strdel(&command_shablon->envp[command_shablon->pwd_index]);
	command_shablon->envp[command_shablon->pwd_index] = ft_strdup("PWD=");
	command_shablon->envp[command_shablon->pwd_index] = ft_realloc_strjoin(command_shablon->envp[command_shablon->pwd_index], command_shablon->data);
	return 0;
}

int	ft_pwd(t_last_command *command_shablon, char **envp_my, char **data, int count)
{
	int exit_status;

	if (!command_shablon->envp[command_shablon->home_index])
		exit_status = COMMAND_NOT_FOUND;
	else
	{
		printf("%s\n", command_shablon->envp[command_shablon->pwd_index] + ft_strlen("PWD="));
		exit_status = 0;
	}
	return exit_status;
}