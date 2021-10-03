#include "minishell.h"


void	ft_dictionary_destructor(dictionary_t *dict)
{
	dictionary_t *tmp;
	
	while (dict != NULL)
	{
		tmp = dict;
		dict = dict->next;
		ft_dictionary_del_key(tmp);
		
	}
	
}

dictionary_t *ft_env_copy(char **env)
{
	int envp_count;
	int i;
	dictionary_t *tmp;
	dictionary_t *dict;

	dict = NULL;
	envp_count = ft_vecstrlen(env);
	i = 0;
	while (i < envp_count)
	{
		if((tmp = ft_dictionary_create(env[i])) == NULL)
   		{
       		tmp = NULL;
			break;
		}
		i++;
		ft_dictionaryadd_back(&dict, tmp);
		

	}
	return(dict);
}

int	ft_dictionarysize(dictionary_t *stack)
{
	dictionary_t	*ptr;
	int		q;

	q = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		
		stack = stack->next;
		q++;
	}
	return (q);
}

size_t		ft_joins_dict(char const *s2, size_t i,int count, char *subjoin)
{
	int j;

	j = 0;
	while (s2[i] && i < count)
	{
		subjoin[j] = s2[i];
		i++;
		j++;
	}
	return (i);
}

int ft_find_element(char *str)
{
	int i;

	i = 0;
	if(str == NULL || ft_strlen(str) < 2)
		return (-1);
	while (str[i])
	{
		if(str[i] == '=')
			return(i);
		i++;
	}
	return (-1);
}

dictionary_t *ft_dictionary_create(char *items)
{
	dictionary_t *ptr;
	int index;
	int index_item;
	int len_items;

	index_item = 1;
	len_items = ft_strlen(items);
	index = ft_find_element(items);
	if(index == -1)
		return (NULL);
	if(ft_isdigit(items[0]) == 1)
	{
		 ft_print_error(FIRSTDIGIT, items, ' ', "export");
		return(NULL);
	}
	if(index == (-1))
		index = len_items;
	else
		index_item = len_items - index;
	if (!(ptr = (dictionary_t *)ft_memalloc(sizeof(dictionary_t))))
		return (NULL);
	if (!(ptr->key = (char *)ft_calloc(index, sizeof(char))))
		return (NULL);
	if (!(ptr->item = (char *)ft_calloc(index_item, sizeof(char))))
		return (NULL);
	ptr->next = NULL;
	ft_joins_dict(items, 0, index, ptr->key);
	ptr->key[index] = '\0';
	if(len_items != index)
		ft_joins_dict(items, index + 1, ft_strlen(items), ptr->item);
	
//	ptr->item[index_item] = '\0';
	return (ptr);
}

dictionary_t	*ft_dictionarylast(dictionary_t *lst)
{
	dictionary_t	*ptr;

	ptr = lst;
	if (lst == NULL)
		return (0);
	while (ptr->next)
	{
		ptr = ptr->next;
		
	}
	
	return (ptr);
}

int find_equal_part(char *str)
{
	int key_len;
	int dict_len;
	int final_len;
	
	key_len = 0;
	while (str[key_len] && ft_isalnum(str[key_len]))
		key_len++;
	if(ft_isalnum(str[key_len]))
		return((key_len));
	return(-1);
}
char *find_data(char *key, dictionary_t *command)
{
	int key_len;
	int dict_len;

	key_len = 0;
	while (ft_isalnum(*(key + key_len)))
		key_len++;
	while (command != NULL)
	{
		dict_len = ft_zero_byte_strlen(command->key);
		if(key_len == dict_len && ft_strncmp(key, command->key, dict_len) == 0 )
		{
				if(command->item[0] == '\0')
					return(NULL);
				else return(command->item);
		}
		command = command->next;
	}
	return(NULL);
}
int find_data_int(char *key, dictionary_t *command)
{
	int key_len;
	int dict_len;
	int j;
	int i;

	i = 0;
	j = 0;
	while (key[j] && key[j] != '=')
		j++;
	key_len = ft_strlen(key);
	if(j == key_len)
		return(-1);
	
	while (command != NULL)
	{	
	

		dict_len = ft_strlen(command->key);
		
		if(j == dict_len && ft_strncmp(key, command->key, j) == 0)
		{
			return(i);
		}
		command = command->next;
		i++;
	}
	return(-1);
}

void change_item(char *new_item, int key_index, dictionary_t *dict)
{
	int len_new_item;
	int j;

	j = 0;
	while (new_item[j] && new_item[j] != '=')
		j++;
	len_new_item = ft_zero_byte_strlen(new_item);
	if(j == len_new_item)
		j = 0;
	else j++;
	while (key_index != 0)
	{
		dict = dict->next;
		key_index--;
	}
	ft_strdel(&dict->item);
	dict->item = ft_strdup(new_item + j);
}

void	ft_dictionaryadd_back(dictionary_t **lst, dictionary_t *new)
{
	dictionary_t	*ptr;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = ft_dictionarylast(*lst);
	new->next = ptr->next;
	ptr->next = new;
}

/*void ft_dictionary_del(dictionary_t *del_stack)
{
	int size = ft_dictionarysize(del_stack);
	if(size == 1)
		ft_memdel((void **)&del_stack);
}*/

void ft_dictionary_del_key(dictionary_t *del_stack)
{
	// if(del_stack->key != NULL)
	ft_memdel((void **)&del_stack->key);
	// if(del_stack->item != NULL)
	ft_memdel((void **)&del_stack->item);
	/*del_stack->next = NULL;*/
	ft_memdel((void **)&del_stack);
}
