#include <cstring.h>


bool ft_isnum_str(char *str)
{
    int index;

    if (!str)
        return false;
    index = -1;
    while (str[++index])
        if (!ft_isdigit(str[index]))
            return false;
    return true;
}