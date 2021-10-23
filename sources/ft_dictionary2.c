#include "minishell.h"

dictionary_t	*ft_dictionary_create(char *items)
{
	dictionary_t	*ptr;
	int				index;
	int				index_item;
	int				len_items;

	index_item = 1;
	len_items = ft_strlen(items);
	index = ft_find_element(items);
	if (index == -1)
		return (NULL);
	if (ft_isdigit(items[0]) == 1)
	{
		ft_print_error(FIRSTDIGIT, items, ' ', "export");
		return (NULL);
	}
	if (index == (-1))
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
	if (len_items != index)
		ft_joins_dict(items, index + 1, ft_strlen(items), ptr->item);
	return (ptr);
}

dictionary_t	*ft_dictionarylast(dictionary_t *lst)
{
	dictionary_t	*ptr;

	ptr = lst;
	if (lst == NULL)
		return (0);
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

int	find_equal_part(char *str)
{
	int	key_len;
	int	dict_len;
	int	final_len;

	key_len = 0;
	while (str[key_len] && ft_isalnum(str[key_len]))
		key_len++;
	if (ft_isalnum(str[key_len]))
		return ((key_len));
	return (-1);
}

char	*find_data(char *key, dictionary_t *command)
{
	int	klen;
	int	dlen;

	klen = 0;
	while (ft_isalnum(*(key + klen)))
		klen++;
	while (command != NULL)
	{
		dlen = ft_zero_byte_strlen(command->key);
		if (klen == dlen && ft_strncmp(key, command->key, dlen) == 0 )
		{
			if (command->item[0] == '\0')
				return (NULL);
			else
				return (command->item);
		}
		command = command->next;
	}
	return (NULL);
}
