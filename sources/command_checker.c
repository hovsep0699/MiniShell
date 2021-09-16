#include "minishell.h"

int ft_alloc_split_minishell(char const *s, char c, char exp, char exp2)
{
	size_t	i;
	size_t	total;
	int exp_state;
	int exp_state2;

	i = 0;
	total = 0;
	exp_state = 1;
	exp_state2 = 1;
	while (s[i])
	{
		if((s[i] == exp && exp_state2 == 1) && exp_state == 1)
			exp_state = 0;
		 else if ((s[i] == exp && exp_state2 == 1) && exp_state == 0)
			exp_state = 1;
		if((s[i] == exp2 && exp_state == 1) && exp_state2 == 1)
			exp_state2 = 0;
		else if((s[i] == exp2 && exp_state == 1) && exp_state2 == 0)
			exp_state2 = 1;
		if (s[i] == c && exp_state && exp_state2)
			total++;
		
		i++;
	}
	return (total);
}
int exec_in_function(char **arguments,t_last_command *command_shablon, int count,char **envp_my)
{
	int i;
	
	
	i = command_shablon->index_command + 1;
	
	
	while (i < count)
	{
		if(arguments[i][0] == ';')
		{
			command_shablon->function_pointer[command_shablon->type_command - 1][command_shablon->util_commant](command_shablon,envp_my, arguments,count);
			command_shablon->index_command = i + 2;
			return (SUCCESS);
		}
		if(arguments[i][0] == '>')
		{	
			only_create_file(arguments[i + 1], command_shablon);
			command_shablon->util_commant = 1;
			i += 2;
			continue;
		}
		if(arguments[i][0] == '$' && ft_strlen(arguments[i]) > 1)
		{
			command_shablon->dollar_exist = 1;
			command_shablon->data = ft_equal_strjoin(command_shablon->data, find_data(arguments[i], command_shablon->variable_dic), arguments[i], command_shablon);
		}
		else
			command_shablon->data = ft_dis_strjoin(command_shablon->data,arguments[i], 2);
		i++;
	}

	if(count == i)
	{
		command_shablon->function_pointer[command_shablon->type_command - 1][command_shablon->util_commant](command_shablon, envp_my, arguments, count);
		command_shablon->index_command = i;
		return(SUCCESS);
	}
	return (1);
}


int system_command(char **list_argument, t_last_command *comand_shablon, char **env_my, int count)
{
	int len;
	char *lower_case;
	int i;
	int exeption;
	dictionary_t *tmp;
	dictionary_t *rut_dict = NULL;
	
	i = 0;
	while (comand_shablon->index_command<count)
	{
		len = ft_strlen(list_argument[i]);
		lower_case = ft_tolower_minishell(list_argument[i], len);
		if(ft_strncmp(lower_case,"echo",4) == 0)
		{
			exeption = PARSER_ERROR;
			if(len == 4)
			{
				comand_shablon->type_command = ECHO;
				exeption =  exec_in_function(list_argument,comand_shablon,count,env_my);
			}
			ft_print_error(exeption,list_argument[i],'\n',NULL);
		}
		else if(ft_strncmp(lower_case,"pwd",3) == 0)
		{
			comand_shablon->type_command = 2;
			if(len == 3)
				return (3);
			else return (-1);
		}
		else if(ft_strncmp(lower_case,"cd",2) == 0)
		{
			comand_shablon->type_command = 3;
			if(len == 2)
				return (4);
			else return (-1);
		}
		else if(ft_strncmp(lower_case,"exit",4) == 0)
		{
			comand_shablon->type_command = 4;
			if(len == 4)
				return (5);
			else return (-1);
		}
		else if(ft_strncmp(lower_case,"export",6) == 0)
		{
			comand_shablon->type_command = EXPORT;
			if(len == 6)
				exec_in_function(list_argument,comand_shablon,count,env_my);
				
		}
		else if(ft_strncmp(lower_case,"unset",6) == 0)
		{
			
			comand_shablon->type_command = UNSET;
			if(len == 5)
				exec_in_function(list_argument,comand_shablon,count,env_my);
		}
	}
	return(1);
}