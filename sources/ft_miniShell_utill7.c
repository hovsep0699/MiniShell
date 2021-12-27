#include "minishell.h"

t_eqstr	ft_eqdef2(char *s1)
{
	t_eqstr	equ;

	equ.i = 0;
	equ.count = 0;
	equ.subjoin = NULL;
	equ.quate_exist = 1;
	equ.dquate_exist = 1;
	equ.end_index = 0;
	equ.count = ft_count_quote(s1);
	return (equ);
}

char	*ft_here_strjoin(char *s1, t_dict *dict)
{
	t_eqstr	equ;

	equ = ft_eqdef2(s1);
	equ.subjoin = (char *)ft_calloc(sizeof(char), (ft_zero_byte_strlen(s1) + 1));
	while (s1[equ.i])
		ft_join_util2(s1, &equ, dict, 0);
	ft_strdel(&s1);
	return (equ.subjoin);
}

int syntax_error(char *str)
{
	if(str == NULL)
	{
		ft_putstr_fd("syntax error near unexpected token `newline'\n" , 2);
		g_signal.exit_status = 2;
		return (0);
	}
	return (1);
}

int	ft_put_enxport_env(t_dict *dictionary, char **envp, char **data, int count)
{
	int				i;
	t_dictionary	*tmp;

	i = 0;
	tmp = dictionary->variable_dic;
	while (tmp != NULL)
	{
		printf("declare -x %s", tmp->key);
		if (tmp->item != NULL && tmp->item[0] != '\0')
			printf("=\"%s\"",tmp->item);
		printf("\n");
		tmp = tmp->next;
	}
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}
