#include "cstring.h"
#include <stdio.h>
string_t ft_string_default_constructor()
{
    string_t str;

    str.data = NULL;
    str.begin = NULL;
    str.end = NULL;
    str.erase = ft_string_erase;
    str.erase2 = ft_string_erase2;
    str.resize = ft_string_resize;
    str.erase_between = ft_string_erase_between;


    return str;
}

string_t ft_string_copy_constructor(string_t *str)
{
    string_t cstr;
    size_t   len;

    len = (str) ? ft_strlen(str->data) : 0;
    cstr = ft_string_default_constructor();
    cstr.data = ft_strdup(str->data);
    cstr.size = str->size;
    *cstr.begin = (string_iterator_t){0, str->data, ft_string_advance};
    *cstr.end = (string_iterator_t){len, str->data + len, ft_string_advance};



    return cstr;
}

string_t ft_string_constructor(char *str)
{
    string_t string;
    size_t   len;

    string = ft_string_default_constructor();
    len = (str) ? ft_strlen(str) : 0;
    string.data = ft_strdup(str);
    string.begin = (string_iterator_t *)malloc(sizeof(string_iterator_t));
    string.end = (string_iterator_t *)malloc(sizeof(string_iterator_t));
    *string.begin = (string_iterator_t){0, string.data, ft_string_advance};
    *string.end = (string_iterator_t){len, string.data + len, ft_string_advance};

    return string;
}

void    ft_string_resize(string_t *str, int size)
{
    ft_realloc(str->data, size);
    ft_bzero(str->data + str->size, size - str->size + 1);
    str->size = size;
}
string_iterator_t ft_striter_default_constructor(void)
{
    string_iterator_t it;

    it = (string_iterator_t){0, NULL, ft_string_advance};
    return it;
}

string_iterator_t ft_striter_copy_constructor(string_iterator_t *iter)
{
    string_iterator_t it;

    it = ft_striter_default_constructor();
    it.index = iter->index;
    it.ptr = iter->ptr;
    return it;
}

void    ft_string_advance(string_iterator_t *it, int size)
{
    string_iterator_t iter;

    iter = ft_striter_copy_constructor(it);
    iter.index += size;
    iter.ptr += iter.index;
    *it = iter;
}

void    ft_string_erase(string_t *str, string_iterator_t *it)
{
    char *copy;
    int index;
    int copy_index;

    copy = (char *)malloc(sizeof(char) * str->size);
    index = 0;
    copy_index = -1;
    while (str->data[index])
    {
        
       
        if (index == it->index)
        {
            ++index;
            continue;
        }
        copy[++copy_index] = str->data[index];
        ++index;
    }
    copy[++copy_index] = '\0';
    ft_strdel(&str->data);
    str->data = copy;
}

void    ft_string_erase2(string_t *str, int it)
{
    char *copy;
    int index;
    int copy_index;

    copy = (char *)malloc(sizeof(char) * str->size);
    index = 0;
    copy_index = -1;
    while (str->data[index])
    {
        if (index == it)
        {
            ++index;
            continue;
        }
        copy[++copy_index] = str->data[index];
        ++index;
    }
    copy[++copy_index] = '\0';
    ft_strdel(&str->data);
    str->data = copy;
}


void   ft_string_erase_between(string_t *str, string_iterator_t *start, string_iterator_t *end)
{
    char *copy;
    int index;
    int copy_index;

    copy = (char *)malloc(sizeof(char) * str->size);
    index = 0;
    copy_index = -1;
    while (str->data[index])
    {
        if (index == start->index)
        {
            index += end->index - start->index + 1;
            continue;
        }
        copy[++copy_index] = str->data[index];
        ++index;
    }
    copy[++copy_index] = '\0';
    ft_strdel(&str->data);
    str->data = copy;
}


void ft_string_destructor(string_t *str)
{
    ft_strdel(&str->data);
    ft_memdel((void **)&str->begin);
    ft_memdel((void **)&str->end);
}
