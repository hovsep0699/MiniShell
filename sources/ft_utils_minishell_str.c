#include "minishell.h"

int ft_strcmp_char(char *str,char c,int count)
{
	int index;

	index = 0;
	if(str == NULL)
		return(-1);
	while (str[index] && index != count)
	{
		if(str[index] == c)
			return(index);
		index++;
	}
	return(-1);
}

char *ft_tolower_minishell(char *upper_str,int *len)
{
	char *lower_case;
	int i;
	int quoet_exist;
	int dquoet_exist;
	int j;

	*len =ft_zero_byte_strlen(upper_str) - ft_count_quote(upper_str);
	//ft_putnbr(*len);
	lower_case = (char *)ft_calloc(sizeof(char),*len);
	i = 0;
	j = 0;
	quoet_exist = 1;
	dquoet_exist = 1;
	while (upper_str[i])
	{
		if(ft_count_quote_character(upper_str[i],&quoet_exist,&dquoet_exist))
		{
			i++;
			continue;
		}
		else if(upper_str[i] == '\\' && (quoet_exist != 0 && dquoet_exist != 0))
		{
			i++;
			continue;
		}
		if (upper_str[i] >= 'A' && upper_str[i] <= 'Z')
			lower_case[j] = upper_str[i] + 32;
		else
			lower_case[j] = upper_str[i];
		i++;
		j++;
	}
	return (lower_case);
}

int free_space(char *clean_space)
{
	
	if(clean_space != NULL && ft_strlen(clean_space) != 0)
	{
		free(clean_space);
		clean_space = NULL;
	}
	return(1);
}

void    ft_char_pointer_erase(char *str, size_t it)
{
    char *copy;
    size_t index;
    size_t copy_index;

    copy = (char *)malloc(sizeof(char) * ft_zero_byte_strlen(str));
    index = 0;
    copy_index = 0;
    while (str[index])
    {
        if (index == it)
        {
            ++index;
            continue;
        }
        copy[copy_index] = str[index];
        ++index;
        ++copy_index;
    }
    copy[++copy_index] = '\0';
    ft_strdel(&str);
    str = copy;
}

int ft_default_set(t_last_command *command)
{
	command->echo_option = 0;
	command->data = NULL;
	command->quote_staet_new = 0;
	command->type_command = 0;
	command->index_command = 0;
	command->rut = 0;
	command->util_commant = 0;
	command->last_command = 0;
	command->dollar_exist = 0;
	command->env_exist = 0;
	command->function_pointer[0][0] = ft_print_echo;
	command->function_pointer[0][1] = ft_write_file;
	command->function_pointer[1][0] = ft_export;
	command->function_pointer[1][1] = ft_write_file;
	command->function_pointer[2][0] = ft_unset;
	command->function_pointer[2][1] = ft_write_file;
	command->function_pointer[3][0] = ft_put_env_export;
	command->function_pointer[3][1] = ft_write_file;
	return(1);
}