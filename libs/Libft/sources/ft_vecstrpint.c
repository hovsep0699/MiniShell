#include <cstring.h>


void    ft_vecstrprint(char **vecstr)
{
    int index;

    if (!vecstr || !*vecstr)
        return ;
    index = -1;
    while (vecstr[++index])
        ft_putendl(vecstr[index]);
}