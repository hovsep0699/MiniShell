#include "clist.h"

list_t	ft_list_array_constructor(void *arr, int elem_size, int size)
{
	list_t		list;
	int			index;
	void		*dst;

	dst = NULL;
	index = -1;
	list = ft_list_default_constructor();
	while (++index < size)
		list.push_back(&list, ft_memmove(dst, arr, elem_size), elem_size);
	return list;
}


/*list_t	ft_list_initalizer_string_constructor(char **arr, int size)*/
/*{*/
	/*list_t	list;*/
	/*int		index;*/

	/*index = -1;*/
	/*list = ft_list_default_constructor();*/
	/*while (++index < size)*/
		/*list.push_back(&list, arr[index]);*/
	/*return list;*/
/*}*/


/*list_t	ft_list_initalizer_char_constructor(char *arr, int size)*/
/*{*/
	/*list_t	list;*/
	/*int		index;*/

	/*index = -1;*/
	/*list = ft_list_default_constructor();*/
	/*while (++index < size)*/
		/*list.push_back(&list, &arr[index]);*/
	/*return list;*/
/*}*/

