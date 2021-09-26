#include "cstring.h"

size_t ft_vecstrlen(char **vecstr)
{
	size_t count;

	count = 0;
	while (vecstr[count])
		++count;
	return count;
}

