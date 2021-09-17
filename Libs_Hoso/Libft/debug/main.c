#include "libft.h"
#include <stdio.h>

int main()
{
	// element_t arr[5];
	// arr[0] = (element_t){1,0,0};
	// arr[1] = (element_t){4,0,0};
	// arr[2] = (element_t){3,5,0};
	// arr[3] = (element_t){7,5,0};
	// arr[4] = (element_t){10,4,0};
	// list_t lst;
	// lst = ft_list_array_constructor(arr, 5);
	// node_t *it = lst.begin;
	// while (it != lst.end)
	// {
	// 	printf("%d\n", it->data.value);
	// 	it = lst.advance(it, 1);
	// }
	// printf("val: %d\n", lst.begin->data.value);
	
	string_t str;
	string_iterator_t it;
	string_iterator_t it2;

	str = ft_string_constructor("hello");
	it = *str.begin;
	it2 = *str.begin;

	// printf("%d %s\n", str.begin->index, str.data);
	it2.advance(&it2, 2);
	// it.advance(&it, 2);
	// printf("%d %d %s\n", it.index, it2.index, str.data);
	printf("%s\n", str.data);
	str.erase_between(&str, &it, &it2);
	printf("%s\n", str.data);


	// ft_list_destructor(&lst);
	ft_string_destructor(&str);
	return 0;
}
