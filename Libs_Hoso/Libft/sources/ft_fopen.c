#include "libft.h"

file_t *ft_fopen(char *filepath, char *mode)
{
	int flags;
	int fd;
	file_t *file;

	file = (file_t *)malloc(sizeof(file_t));
	if (!mode || !filepath || !file)
		return (NULL);
	if (*mode == 'r')
		flags = O_RDONLY;
	else if (*mode == 'w')
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	else if (*mode == 'a')
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else if (*mode == 'r' && *(mode + 1) == '+')
		flags = O_RDWR;
	else if (*mode == 'w' && *(mode + 1) == '+')
		flags = O_RDWR | O_CREAT | O_TRUNC;
	else if (*mode == 'a' && *(mode + 1) == '+')
		flags = O_RDWR | O_CREAT | O_APPEND;
	else
	{
		ft_file_destructor(file);
		return (NULL);
	}
	fd = open(filepath, flags, 0666);
	if (fd < 0)
	{
		ft_file_destructor(file);
		return (NULL);
	}
	file->fd = fd;
	file->rows = -1;
	file->size = -1;
	file->content = NULL;
	return (file);
}

file_t *ft_file_constructor(void)
{
	file_t *file;

	file = (file_t *)malloc(sizeof(file_t));
	file->fd = 0;
	file->rows = -1;
	file->size = -1;
	file->content = NULL;
	return file;
}

int ft_fclose(file_t *file)
{
	return (close(file->fd));
}

