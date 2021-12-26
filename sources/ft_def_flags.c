#include "minishell.h"

void ft_def_flag(t_dict *dict)
{
    dict->type_command = UNDEFINED;
    dict->fr_command = FNONE;
    dict->util_commant = NONE;
}