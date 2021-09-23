#include "libft.h"


void	ft_filecpy(char *input_file, char *output_file, char *mode)
{
	file_t *file;
	file_t *file2;

	file2 = NULL;
	file = ft_fopen(input_file, "r");
	if (!file)
		return ;
	ft_get_file(file);
	ft_set_file(file, file2, output_file, mode);
	ft_fclose(file);
	ft_file_destructor(file);
}
