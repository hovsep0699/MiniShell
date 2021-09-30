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
	subjoin[i] = '\0';
	return (i);
}

char		*ft_equal_strjoin(char *s1, t_last_command *command_shablon, char *pars_str, int end_of_line)
{
	char	*subjoin;
	int i;
	int len_key;
	int quate_exist;
	int dquate_exist;
	int end_index;
	char *tmp_str;
	int count;

	i = 0;
	count = 0;
	subjoin = NULL;
	quate_exist = 1;
	dquate_exist = 1;
	end_index = ft_zero_byte_strlen(s1);
	count = ft_count_quote(pars_str);
	//printf("\ncount = %i\n",(ft_zero_byte_strlen(pars_str) - count) + 1 + end_of_line);
	subjoin = (char *)ft_calloc(sizeof(char), (end_index + (ft_zero_byte_strlen(pars_str) - count) + 1 + end_of_line));
	if(end_index > 0)
		subjoin = ft_strcpy(subjoin, s1);
	while (pars_str[i])
	{
		if(ft_count_quote_character(pars_str[i], &quate_exist, &dquate_exist))
			++i;
		else if(pars_str[i] == '\\' && (dquate_exist != 0 && quate_exist != 0))
		{
			++i;
			subjoin[end_index++] = pars_str[i];
			++i;
		}
		else if(pars_str[i] == '$' && pars_str[i + 1] == '?' && quate_exist != 0)
		{
			tmp_str = ft_itoa(command_shablon->exit_status);
			len_key = ft_zero_byte_strlen(tmp_str);
			subjoin = ft_realloc_strjoin(subjoin, tmp_str);
			end_index += len_key;
			ft_strdel(&tmp_str);
			i += 2;
		}
		else if(pars_str[i] == '$' && quate_exist != 0)
		{
			subjoin = ft_realloc_strjoin(subjoin, find_data((pars_str + i + 1),command_shablon->variable_dic));
			end_index += ft_zero_byte_strlen(subjoin) - end_index;
			ft_isalnum_str(pars_str + i + 1, &i);
			i += 2;
		}
		else if(pars_str[i] == '~' && dquate_exist != 0 && quate_exist != 0 && i == 0 && (pars_str[i + 1] == '\0' || pars_str[i + 1] == '/'))
		{
			subjoin = ft_realloc_strjoin(subjoin, getenv("HOME"));
			end_index = ft_zero_byte_strlen(subjoin);
			i++;
		}
		else 
			subjoin[end_index++] = pars_str[i++];
	}
	if(!end_of_line)
		subjoin[end_index] = ' ';
	ft_strdel(&s1);
	return(subjoin);
}
char		*ft_dis_strjoin(char *s1, char *s2,int mod)
{
	char	*subjoin;
	size_t	i;
	int len_s1;
	int len_s2;
	int quoet_exist;
	int dquoet_exist;

	quoet_exist = 1;
	dquoet_exist = 1;
	len_s2 = ft_count_quote_character(*s2, &quoet_exist, &dquoet_exist);
	len_s1 = ft_zero_byte_strlen(s1);
	len_s2 = ft_zero_byte_strlen(s2) - len_s2;
	i = 0;
	subjoin = (char *)ft_calloc(sizeof(char), len_s1 + len_s2 + mod);
	if (!subjoin)
		return (NULL);
	if (len_s1 > 0)
		i = ft_joins(s1, i, len_s1, subjoin);
	if(mod == 2 && len_s1 > 0)
	{
		subjoin[i] = ' ';
		++i;
	}
	if(len_s2 > 0)
		i = ft_joins(s2, i, len_s2, subjoin);
	ft_strdel(&s1);
	return (subjoin);
}


//ara rad ara es vat kody :))

// int			get_next_line(int fd, char **line)
// {
// 	t_form_next_line	next_line;
// 	static char			*c_line;

// 	if ((next_line.bf = ((char *)malloc(sizeof(char) * (1
// 							+ 1)))) == NULL && (c_line = NULL) == NULL)
// 		return (-1);
// 	if (fd < 0 || !line || 1 <= 0)
// 		return (-1);
// 	while ((next_line.r = read(0, next_line.bf, 1)) > 0)
// 	{
// 		next_line.bf[next_line.r] = '\0';
// 		c_line = ft_dis_strjoin(c_line, next_line.bf,1);
// 		if (ft_dis_strchr(c_line, '\n') || next_line.r == 0)
// 			break ;
// 	}
// 	free(next_line.bf);
// 	if (next_line.r < 0)
// 		return (-1);
// 	(*line) = ft_single_join(c_line);
// 	c_line = ft_clean(c_line, ft_zero_byte_strlen(c_line));
// 	if (next_line.r == 0 && !c_line)
// 		return (0);
// 	return (1);
// }
