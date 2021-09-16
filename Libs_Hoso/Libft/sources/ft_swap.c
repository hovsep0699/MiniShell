#include "clist.h"

void ft_swap(void *a, void *b, size_t len)
{
    unsigned char *first;
	unsigned char *second;
	unsigned char tmp;
	size_t index;
	
	first = a;
	second = b;
	index = -1;
    while (++index != len)
    {
        tmp = first[index];
        first[index] = second[index];
        second[index] = tmp;
    }
}

