#ifndef CSTDLIB_H
# define CSTDLIB_H

# include <stdlib.h>
# include <unistd.h>

/*
# define FT_MAX(x,y)(x > y ? x : y)
# define FT_MIN(x,y)(x < y ? x : y)
*/

void	*ft_realloc(void *ptr, size_t newsize);

void	*ft_memalloc(size_t size);

void	*ft_calloc(size_t count, size_t size);

void	ft_memdel(void **mem);

#endif
