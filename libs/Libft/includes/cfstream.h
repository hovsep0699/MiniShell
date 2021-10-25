#ifndef CFSTREAM_H
#define CFSTREAM_H


#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 32
# endif

# define STDIN_FILE 0
# define STDOUT_FILE 1
# define STDERR_FILE 2

# include <stdbool.h>
# include <fcntl.h>
# include "cstring.h"

typedef struct file
{
	int		fd;
	int		rows;
	int		size;
	char	**content;
}			file_t;

int					ft_getline(int fd, char **line);


void				ft_file_destructor(file_t *file);

char				*gnl_get_line(char *buffer);

char				*gnl_get_buffer(char *buffer);

char				*get_gnl_line(char *memory);

char				*get_gnl_buffer(char *s);

#endif
