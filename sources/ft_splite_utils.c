#include "minishell.h"

char * ft_add_space(char *source, int count, int mod, int index)
{
	char *tmp;
	int i;
	char tmp_character;

	i = 0;
	int j;
	 j = index;
	while (source[j])
	{
		tmp_character = source[j-1];	
		if(count == 0)
			return(tmp);
		if(count == 1 && j == index + 1)
			source[j] = ' ';
		if (count == 2)
			source[j + 1] = ' ';
		if(count == 3)
		{
			source[j] = ' ';
			source[j + 2] = ' ';
			j += 1;
		}
		source[j] = tmp_character;
	}
	
	
	return (tmp);
}
int ft_len_array(char *splite_array)
{
	int i;
	int state;
	int count;

	i = 0;
	state = 0;
	count = 0;
	while (splite_array[i])	
	{
		if((splite_array[i] == '|' || splite_array[i] == '>' || splite_array[i] == '<' || splite_array[i] == ';') && i != 0)
		{
			count += splite_array[i - 1] != ' ' ? 1 : 0;
			count += splite_array[i + 2] != ' ' ? 1 : 0;
			if((ft_strncmp(splite_array + i, "<>", 2) == 0) || (ft_strncmp(splite_array + i, ">>", 2) == 0))
				i++;
			state = 0;
		}
		i++;			
	}
	return(count + i);
}
char *enter_split_sapce(char **not_splite)
{
	int i;
	int j;
	int state;
	char *splite_array;
	int len;
	char *str;

	i = 0;
	state = 0;
	j = 0;

	str = ft_strdup(*(not_splite));
	len = ft_len_array(str);
	splite_array = ft_calloc(len + 1, sizeof(char));
	while (str[i])	
	{
		
		if((str[i] == '|' || str[i] == '>' || str[i] == '<' || str[i] == ';') && i != 0)
		{	
			if(str[i - 1] != ' ')
					splite_array[j++] = ' ';
			if((ft_strncmp(str + i, "<<", 2) == 0) || (ft_strncmp(str + i, ">>", 2) == 0))
			{
				
				splite_array[j++] = str[i++];
				splite_array[j++] = str[i];
				
			}
			else 
				splite_array[j++] = str[i];
			if(str[i + 1] != ' ')
					splite_array[j++] = ' ';
			i++;
		}
		else
		 	splite_array[j++] = str[i++];
	}
	ft_strdel(&str);
	return(splite_array);
}