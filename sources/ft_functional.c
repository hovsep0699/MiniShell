#include "minishell.h"


cmd_func_t    ft_search_builtin_func(t_dict *lcmd)
{
    int index;

    index = -1;
    while (++index < MAX_BUILTIN_FUNCS)
    {
       if (lcmd->type_command == lcmd->functions[index].name)
            return lcmd->functions[index].function;
    }
    return NULL;
}

cmd_func_t    ft_search_side_func(t_dict *lcmd)
{
    int index;

    index = -1;
    while (++index < MAX_SIDE_FUNCS)
    {
       if (lcmd->util_commant == lcmd->side_functions[index].name && lcmd->util_commant != NONE)
            return lcmd->side_functions[index].function;
    }
    return ft_search_builtin_func(lcmd);
}