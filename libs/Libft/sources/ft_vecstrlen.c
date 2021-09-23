#include "cstring.h"

size_t ft_vecstrlen(char **str)
{
	size_t count;

	count = -1;
	while (str[++count]) ;
	return count;
}

