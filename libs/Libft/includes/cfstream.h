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

void				ft_file_destructor(file_t *file);

#endif
