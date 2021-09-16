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



file_t				*ft_file_constructor(void);

int					ft_getline(int fd, char **line);

void				ft_get_file(file_t *file);

void				ft_file_destructor(file_t *file);

void				ft_set_file(file_t *in, file_t *out, char *filepath, char *mode);

void				ft_set_file2(char **content, file_t *out, char *filepath, char *mode);

void				ft_filecpy(char *input_file, char *output_file, char *mode);

file_t				*ft_fopen(char *filepath, char *mode);

int					ft_fclose(file_t *file);

char				*gnl_get_line(char *buffer);

char				*gnl_get_buffer(char *buffer);

bool				ft_findchr(const char *s, int c);

size_t				ft_zero_byte_strlen(const char *s1);

char				*ft_realloc_strjoin(char *s1, char *s2);

char				*get_gnl_line(char *memory);

char				*get_gnl_buffer(char *s);

int					ft_file_rowslen(int fd);


#endif
