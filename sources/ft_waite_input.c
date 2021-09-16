#include "minishell.h"

int		ft_dis_strchr(const char *s, int c)
{
	int t;

	t = 0;
	while (s[t])
	{
		if (s[t] == c)
			return (t);
		t++;
	}
	if (s[t] == '\0' && !c)
		return (t);
	return (0);
}

char	*ft_strnull(void)
{
	char *str;

	if ((str = (char *)malloc(sizeof(char) * (0 + 1))) == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_single_join(char *c)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	if (c == NULL)
		return (ft_strnull());
	while (c && c[j] != '\n' && c[j] != '\0')
		j++;
	if ((str = (char *)malloc(sizeof(char) * j + 1)) == NULL)
		return (NULL);
	while (c[i] && i < j && c && c[i] != '\n')
	{
		str[i] = c[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_clean(char *bf, int length)
{
	int		i;
	int		j;
	char	*c;

	j = 0;
	i = 0;
	if (bf == NULL)
		return (NULL);
	while (bf[j] != '\n' && bf[j] != '\0')
		j++;
	if (bf[j] == '\0')
	{
		free(bf);
		return (NULL);
	}
	c = (char *)malloc(sizeof(char) * (length - j) + 1);
	while (bf[j] && bf)
	{
		c[i] = bf[j + 1];
		j++;
		i++;
	}
	c[i] = '\0';
	free(bf);
	return (c);
}

size_t		ft_joins(char const *s2, size_t i,int count, char *subjoin)
{
	int j;

	j = 0;
	while (s2[j] && j < count)
	{
		subjoin[i] = s2[j];
		i++;
		j++;
	}
	return (i);
}
char		*ft_equal_strjoin(char *s1, char *s2,char *s3,t_last_command *command_shablon)
{
	char	*subjoin;
	size_t	i;
	int len_s1;
	int len_s2;
	int len_s3;
	int len_3_araj;

	len_s1 = ft_zero_byte_strlen(s1);
	len_s2 = ft_zero_byte_strlen(s2);
	//ft_putstr("\nasd\n");
	 len_s3 =  (len_3_araj = find_equal_part(s3)) > 0 ?ft_zero_byte_strlen(s3) - len_3_araj:0;
	if(command_shablon->type_command == EXPORT && len_s3 == 1)
	{	
		free(s1);
		ft_print_error(BAD_ASSIGNMENT,NULL,' ',NULL);
		return(NULL);
	}
	if(command_shablon->type_command == EXPORT && len_s3 > 0 && len_s2 == 0)
	{	
		free(s1);
		ft_print_error(COMMAND_NOT_FOUND,s3 + (len_3_araj + 1),' ',NULL);
		return (NULL);
	}
	if(len_s3 == 0 && len_s2 == 0)
	{
		if(command_shablon->type_command == EXPORT)
			return(s1);
	}
	i = 0;
	subjoin = (char *)ft_calloc(sizeof(char),len_s1 + len_s2 + len_s3 + 1);
	if (!subjoin)
		return (NULL);
	if (len_s1 > 0)
		i = ft_joins(s1, i,len_s1, subjoin);
	if(len_s2 > 0)
		i = ft_joins(s2, i,len_s2, subjoin);
	if(len_s3 > 0)
		i = ft_joins(s3 + len_3_araj, i,len_s3, subjoin);
	free(s1);
	return (subjoin);
}
char		*ft_dis_strjoin(char *s1, char *s2,int mod)
{
	char	*subjoin;
	size_t	i;
	int len_s1;
	int len_s2;

	len_s1 = ft_zero_byte_strlen(s1);
	len_s2 = ft_zero_byte_strlen(s2);
				
	i = 0;
	subjoin = (char *)ft_calloc(sizeof(char),len_s1 + len_s2 + mod);
	if (!subjoin)
		return (NULL);
	if (len_s1 > 0)
		i = ft_joins(s1, i,len_s1, subjoin);
	if(mod == 2 && len_s1 > 0)
	{
		subjoin[i] = ' ';
		i++;
	}
	if(len_s2>0)
	i = ft_joins(s2, i,len_s2, subjoin);
	free(s1);
	return (subjoin);
}

int			get_next_line(int fd, char **line)
{
	t_form_next_line	next_line;
	static char			*c_line;

	if ((next_line.bf = ((char *)malloc(sizeof(char) * (1
							+ 1)))) == NULL && (c_line = NULL) == NULL)
		return (-1);
	if (fd < 0 || !line || 1 <= 0)
		return (-1);
	while ((next_line.r = read(0, next_line.bf, 1)) > 0)
	{
		next_line.bf[next_line.r] = '\0';
		c_line = ft_dis_strjoin(c_line, next_line.bf,1);
		if (ft_dis_strchr(c_line, '\n') || next_line.r == 0)
			break ;
	}
	free(next_line.bf);
	if (next_line.r < 0)
		return (-1);
	(*line) = ft_single_join(c_line);
	c_line = ft_clean(c_line, ft_zero_byte_strlen(c_line));
	if (next_line.r == 0 && !c_line)
		return (0);
	return (1);
}
