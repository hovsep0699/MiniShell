#include "clist.h"
#include <stdio.h>

int main()
{
	list_t lst;
	char x;

	lst = ft_list_default_constructor();


	x = 'a';
	lst.push_back(&lst, &x, sizeof(int));
	x = 'b';
	lst.push_back(&lst, &x, sizeof(int));
	x = 'c';
	lst.push_back(&lst, &x, sizeof(int));
	// node_t *it;

	// it = lst.begin;
	// while (it != lst.end)
	// {
		printf("%c %d\n", *(char *)lst.begin->data, lst.size);
		lst.pop_front(&lst);
		// printf("%c\n", *(char *)lst.begin->data);
		// printf("%c\n", *(char *)lst.begin->next->next->data);
		// it = lst.advance(it, 1);
	// }
	
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
	
	// string_t str;
	// string_t str2;

	// str = ft_string_constructor(" world ");
	// str2 = ft_string_default_constructor();

	// printf("%d %s\n", str.begin->index, str.data);
	// it.advance(&it, 2);
	// printf("%d %d %s\n", it.index, it2.index, str.data);
	// printf("%s\n", str.data);

	// printf("%s\n", str2.data);
	// printf("%s %lu %lu\n", str.data, str.size, ft_zero_byte_strlen(str.data));
	// // ft_realloc(str.data, 25);
	// bool x = str.compare2(&str, " world ");
	// printf("%d\n", x);
	// printf("%s %lu %lu\n", str.data, str.size, ft_zero_byte_strlen(str.data));
	// printf("%s %lu %lu\n", str.data, str.size, ft_zero_byte_strlen(str.data));

	// ft_list_destructor(&lst);
	// ft_string_destructor(&str);
	// ft_list_destructor(&lst);
	return 0;
}
