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
int ft_isalnum_str(char *str,int *i)
{
	int index;

	index = 0;
	while (str[index])
	{
		if(!ft_isalnum(str[index]))
			break;
		index++;
	}
	*i += index - 1;
	return(index);
	
}
int ft_count_quote_character(char character,int *quoet_exist,int *dquoet_exist)
{
		if((character == CHAR_QUATES && *dquoet_exist == 1) && *quoet_exist == 1)
		{
			*quoet_exist = 0;
			return(true);
		}
		 else if ((character == CHAR_QUATES && *dquoet_exist == 1) && *quoet_exist == 0)
		 {
			*quoet_exist = 1;
			return(true);
		}
			
		else if((character == CHAR_DQUATES && *quoet_exist == 1) && *dquoet_exist == 1)
		{
			*dquoet_exist = 0;
			return(true);
		}
		else if((character == CHAR_DQUATES && *quoet_exist == 1) && *dquoet_exist == 0)
		{
			*dquoet_exist = 1;
			return(true);
		}
		return(false);
}
int ft_count_quote(char  *s)
{
	int	i;
	size_t	total;
	int quoet_exist;
	int dquoet_exist;

	i = 0;
	total = 0;
	quoet_exist = 1;
	dquoet_exist = 1;
	while (s[i])
	{
		if(ft_count_quote_character(s[i],&quoet_exist,&dquoet_exist))
			total++;
		else if(s[i] == '\\' && (quoet_exist != 0 || dquoet_exist != 0))
			total += 1;
		else if(s[i] == '$' && s[i + 1] == '?' && quoet_exist != 0)
			total += 2;
		else if(s[i] == '$' && quoet_exist != 0)
			total += ft_isalnum_str(s + i + 1,&i) + 1;
		i++;
	}
	return (total);
}

int exec_in_function(char **arguments,t_last_command *command_shablon, int count,char **envp_my)
{
	int i;
	int dollar_index;
	int end_of_line;
	
	
	i = command_shablon->index_command + 1;
	dollar_index = 0;
	end_of_line = 0;
	while (i < count)
	{
		if(end_of_line >= i)
		end_of_line = ft_vecstr_search2(arguments,";",i);
		if(arguments[i][0] == ';')
		{
			command_shablon->function_pointer[command_shablon->type_command - 1][command_shablon->util_commant](command_shablon,envp_my, arguments,count);
			command_shablon->index_command = i + 2;
			return (SUCCESS);
		}
		if(arguments[i][0] == '>')
		{	
			only_create_file(arguments[i + 1], command_shablon);
			command_shablon->util_commant = GREATHER;
			i += 2;
			continue;
		}
		//if(arguments[i][0] == '|')
		command_shablon->data = ft_equal_strjoin(command_shablon->data,command_shablon,arguments[i],end_of_line == i);
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
	
	i = 0;
	while (comand_shablon->index_command<count)
	{
		lower_case = ft_tolower_minishell(list_argument[i], &len);
		if(ft_strncmp(lower_case,"echo",4) == 0)
		{
			exeption = PARSER_ERROR;
			if(len == 4)
			{
				comand_shablon->type_command = ECHO;
				exeption =  exec_in_function(list_argument,comand_shablon,count,env_my);
			}
			else
			ft_print_error(exeption,list_argument[i],'\n',NULL);
		}
		else if(ft_strncmp(lower_case,"pwd",3) == 0)
		{
			comand_shablon->type_command = 2;
			if(len == 3)
				return (3);
			else return (-1);
		}
		else if(ft_strncmp(lower_case,"env",3) == 0)
		{
			if(len == 3)
			{
				comand_shablon->type_command = ENV;
				exeption =  exec_in_function(list_argument,comand_shablon,count,env_my);
			}
			else ft_print_error(PARSER_ERROR,list_argument[i],'\n',NULL);
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
		ft_strdel(&lower_case);
	}
	return(1);
}