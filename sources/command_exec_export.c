#include "minishell.h"
int ft_put_env_export(char **envp, dictionary_t *dictionary)
{
    int i;

    i = 0;
    while (envp[i] && envp[i+1] != '\0')
    {
        ft_putstr_fd(envp[i],1);
        ft_putchar_fd('\n',1);
        i++;
    }
    while (dictionary != NULL)
    {
        ft_putstr_fd(dictionary->key,1);
        ft_putstr_fd("=",1);
        if(dictionary->item != NULL && dictionary->item[0] != '\0')
            ft_putstr_fd(dictionary->item,1);
        else
            ft_putstr_fd("\'\'",1);
        ft_putchar_fd('\n',1);
        dictionary = dictionary->next;
    }
    return(1);
    
}
int 			ft_export(struct	s_last_command * dictioanry,char **envp, char **data,int count)
{
	dictionary_t *tmp;
    char **str;
    int i;
    int start_index;
    int end_index;
    if(dictioanry->data == NULL && dictioanry->env_exist == 1)
        return(UNPRINT_ERROR);
    if(ft_strlen(dictioanry->data) == 0)
    {
        ft_put_env_export(envp,dictioanry->variable_dic);
        return(SUCCESS);
    }
    start_index = ft_alloc_split_minishell(dictioanry->data,' ','\'','\"') + 1;
    str = ft_split_Vache(dictioanry->data,' ','\'','\"');
    end_index = 0;
    while (end_index < start_index)
    {
        if((i = find_data_int(str[end_index],dictioanry->variable_dic)) == -1)
	    {
		    if((tmp = ft_dictionary_create(str[end_index])) == NULL)
            {
                tmp = NULL;
                end_index++;
                continue;
            }
		    ft_dictionaryadd_back(&(dictioanry->variable_dic),tmp);
	    }
	    else
            change_item(str[end_index],i,dictioanry->variable_dic);
        tmp = NULL;
        end_index++;
    }
    ft_vecstrdel(&str);
    return(SUCCESS);
}

int ft_unset(struct	s_last_command * dictioanry, char **envp, char **data, int count)
{
    int i;
    int len;
    int contindex;
    int endindex;
    dictionary_t *tmp;
    dictionary_t *provide;

    i = 0;
    len = ft_strlen(dictioanry->data);
    int dict_key_len = 0;
    endindex = 0;
    contindex = 0;
    tmp = dictioanry->variable_dic;
    while (dictioanry->data[contindex])
    {	
       endindex = (endindex = ft_strcmp_char(dictioanry->data + contindex,' ',len)) > 0 ? endindex : len;
        while (tmp != NULL)
        {
            dict_key_len = ft_strlen(tmp->key);
           if(ft_strncmp(dictioanry->data + contindex,tmp->key,endindex) == 0 && endindex - contindex == dict_key_len)
            {
                if(dictioanry->variable_dic == tmp)
                    dictioanry->variable_dic = dictioanry->variable_dic->next;
                provide->next = tmp->next;
                ft_dictionary_del_key(tmp);
                break;
            }
            provide = tmp;
            tmp = tmp->next;
        }
        tmp = dictioanry->variable_dic;
        if (len <= endindex)
            break; 
        contindex = endindex + 1;
    }
    return(1);
    
}