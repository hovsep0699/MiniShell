#include "cstdlib.h"
#include "cstring.h"

void	*ft_realloc(void *ptr, size_t newsize)
{
	char	*newptr;
	size_t	cursize;

	if (!ptr)
		return (malloc(newsize));
	cursize = sizeof(ptr);
	if (newsize <= cursize)
		return (ptr);
	newptr = malloc(newsize);
	if (newptr)
		return (NULL);
	ft_memmove(newptr, ptr, cursize);
	ft_memdel(ptr);
	return (newptr);
}
