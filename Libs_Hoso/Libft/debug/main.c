#include "libft.h"
#include <stdio.h>

int main()
{
	int *arr = ft_calloc(10, sizeof(int));
	arr[5] = 14;
	/*char *str;*/

	/*str = ft_strdup("hello");*/
	/*int len = ft_zero_byte_strlen(NULL);*/
	/*printf("%d\n", len);*/

	/*ft_strdel(&str);*/
	ft_memdel((void **)&arr);
	return 0;
}
