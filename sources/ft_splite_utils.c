#include "minishell.h"

char * ft_add_space(char *source,int count, int mod,int index)
{
	char *tmp;
	int i;
	char tmp_character;

	i = 0;
	int j;
	 j = index;
//	if((tmp = (char *) malloc(sizeof(char) * (ft_strlen(source) + (count == 1? count + 1:count) )))== NULL)
	//	return (NULL);
	while (source[j])
	{
		tmp_character = source[j-1];	
		if(count == 0)
			return(tmp);
		if(count == 1 && j == index + 1)
			source[j] = ' ';
		if (count == 2)
			source[j+1] = ' ';
		if(count == 3)
		{
			source[j] = ' ';
			source[j+2] = ' ';
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
			count += splite_array[i-1] != ' ' ? 1 : 0;
			count += splite_array[i+2] != ' ' ? 1 : 0;
			if((ft_strncmp(splite_array+i,"<>",2) == 0) || (ft_strncmp(splite_array+i,">>",2) == 0))
			{
				i ++;
			}
			state = 0;
		}
		i++;			
	}
	//ft_putnbr_fd(i +c,1);
	//ft_putchar_fd('\n',1);
	return(count + i);
}
char *enter_split_sapce(char *not_splite)
{
	int i;
	int j;
	int state;
	char *splite_array;
	int len;

	i = 0;
	state = 0;
	j = 0;
	len = ft_len_array(not_splite);
	splite_array = ft_calloc(sizeof(char),len + 1);
	//ft_strlcpy(splite_array,not_splite,ft_strlen(not_splite) + 1);

	while (not_splite[i])	
	{
		
		if((not_splite[i] == '|' || not_splite[i] == '>' || not_splite[i] == '<' || not_splite[i] == ';') && i != 0)
		{	
			if(not_splite[i-1] != ' ')
					splite_array[j++] = ' ';
			if((ft_strncmp(not_splite+i,"<>",2) == 0) || (ft_strncmp(not_splite+i,">>",2) == 0))
			{
				
				splite_array[j++] = not_splite[i++];
				splite_array[j++] = not_splite[i];
				
			}
			else 
				splite_array[j++] = not_splite[i];
			if(not_splite[i+1] != ' ')
					splite_array[j++] = ' ';
			i++;
		}
		else
		 	splite_array[j++] = not_splite[i++];		
	}
	//ft_putstr_fd(splite_array,1);
	ft_strdel(&not_splite);
	// free(not_splite);
	return(splite_array);
}