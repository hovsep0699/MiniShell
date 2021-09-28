#include "cstring.h"
#include <stdio.h>

string_t ft_string_default_constructor()
{
    string_t str;

    str.data = NULL;
    str.erase = ft_string_erase;
    str.erase2 = ft_string_erase2;
    str.resize = ft_string_resize;
    str.erase_between = ft_string_erase_between;
    str.join = ft_string_join;
    str.join2 = ft_string_join2;
    str.substr = ft_string_substr;
    str.insert = ft_string_insert;
    str.insert2 = ft_string_insert2;
    str.find = ft_string_find;
    str.find2 = ft_string_find2;
    str.find3 = ft_string_find3;
    str.rfind = ft_string_rfind;
    str.rfind2 = ft_string_rfind2;
    str.rfind3 = ft_string_rfind3;
    str.tolower = ft_string_tolower;
    str.toupper = ft_string_tolower;
    str.compare = ft_string_compare;
    str.compare2 = ft_string_compare2;
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

    return cstr;
}

string_t ft_string_constructor(char *str)
{
    string_t string;


    string = ft_string_default_constructor();
    string.size = ft_zero_byte_strlen(str);
    string.data = ft_strdup(str);
    return string;
}

void    ft_string_resize(string_t *str, size_t size)
{
    ft_realloc(str->data, size);
    ft_bzero(str->data + str->size, size - str->size + 1);
    str->size = size;
}

void    ft_string_erase(string_t *str, size_t it)
{
    char *copy;
    size_t index;
    size_t copy_index;

    copy = (char *)malloc(sizeof(char) * str->size);
    index = 0;
    copy_index = 0;
    while (str->data[index])
    {
        if (index == it)
        {
            ++index;
            continue;
        }
        copy[copy_index] = str->data[index];
        ++index;
        ++copy_index;
    }
    copy[++copy_index] = '\0';
    ft_strdel(&str->data);
    str->data = copy;
    --str->size;
}

void    ft_string_erase2(string_t *str, size_t it, size_t len)
{
    char *copy;
    size_t index;
    size_t copy_index;

    copy = (char *)malloc(sizeof(char) * str->size);
    index = 0;
    copy_index = 0;
    while (str->data[index])
    {
        if (index == it)
        {
            index += len;
            continue;
        }
        copy[copy_index] = str->data[index];
        ++copy_index;
        ++index;
    }
    copy[++copy_index] = '\0';
    ft_strdel(&str->data);
    str->data = copy;
    str->size -= len;
}


void   ft_string_erase_between(string_t *str, size_t start, size_t end)
{
    char *copy;
    size_t tmp;

    if (start > end)
    {
        tmp = start;
        start = end;
        end = tmp;
    }
    copy = (char *)malloc(sizeof(char) * str->size);
    ft_strncpy(copy, str->data, start);
    copy[start - 1] = '\0';
    ft_strcat(copy, str->data + end);
    ft_strdel(&str->data);
    str->data = copy;
    str->size -= end - start + 1;
}


void ft_string_destructor(string_t *str)
{
    ft_strdel(&str->data);
    str->size = 0;
}

void    ft_string_join(string_t *str, string_t *str2)
{
    str->data = ft_realloc_strjoin(str->data, str2->data);
    str->size = ft_zero_byte_strlen(str->data);
}
void    ft_string_join2(string_t *str, char *str2)
{
    str->data = ft_realloc_strjoin(str->data, str2);
    str->size = ft_zero_byte_strlen(str->data);
}
void ft_string_substr(string_t *str, string_t *new, size_t start, size_t len)
{
    ft_strdel(&new->data);
    new->data = ft_substr(str->data, start, len);
}

void    ft_string_insert(string_t *str, size_t index, string_t *str2)
{
    char *new;
    size_t size;

    size = ft_zero_byte_strlen(str->data) + ft_zero_byte_strlen(str2->data);
    new = (char *)ft_calloc(size + 1, sizeof(char));
    ft_strncpy(new, str->data, index + 1);
    ft_strcat(new, str2->data);
    ft_strcat(new, str->data + index);
    ft_strdel(&str->data);
    str->data = new;
    str->size = size;
}

void    ft_string_insert2(string_t *str, size_t index, char *str2)
{
    char *new;
    size_t size;

    size = ft_zero_byte_strlen(str->data) + ft_zero_byte_strlen(str2);
    new = (char *)ft_calloc(size + 1, sizeof(char));
    ft_strncpy(new, str->data, index + 1);
    ft_strcat(new, str2);
    ft_strcat(new, str->data + index);
    ft_strdel(&str->data);
    str->data = new;
    str->size = size;
}

int     ft_string_find(string_t *str, char c)
{
    int index;

    index = -1;
    if (!c)
        return ft_zero_byte_strlen(str->data);
    while (str->data[++index])
    {
        if (str->data[index] == c)
            return index;
    }
    return -1;
}

int     ft_string_find2(string_t *str, char *needle)
{
	int h_index;
	int n_index;

	h_index = 0;
	if (!needle || !*needle)
		return (-1);
	while (str->data[h_index])
	{
		n_index = 0;
		if (str->data[h_index] == needle[n_index])
		{
			while (str->data[h_index + n_index] == needle[n_index])
			{
				if (needle[n_index + 1] == '\0')
					return (h_index);
				++n_index;
			}
		}
		++h_index;
	}
	return (-1);
}

int     ft_string_find3(string_t *str, string_t *needle)
{
	return ft_string_find2(str, needle->data);
}

int     ft_string_rfind(string_t *str, char c)
{
    int index;

    index = str->size;
    if (!c)
        return ft_zero_byte_strlen(str->data);
    while (str->data[--index])
    {
        if (str->data[index] == c)
            return index;
    }
    return -1;
}

int     ft_string_rfind2(string_t *str, char *needle)
{
	int h_index;
	int n_index;

	h_index = 0;
	if (!needle || !*needle)
		return (-1);
	while (str->data[h_index])
	{
		n_index = 0;
		if (str->data[str->size - h_index - 1] == needle[n_index])
		{
			while (str->data[str->size - h_index - 1 + n_index] == needle[n_index])
			{
				if (!needle[n_index + 1])
					return (str->size - h_index - 1);
				++n_index;
			}
		}
        ++h_index;
	}
	return (-1);
}

int     ft_string_rfind3(string_t *str, string_t *needle)
{
	return ft_string_rfind2(str, needle->data);
}

void    ft_string_reverse(string_t *str)
{
    ft_strdel(&str->data);
    str->data = ft_strrev(str->data);
}

void    ft_string_tolower(string_t *str)
{
    int index;

    index = -1;
    while (str->data[++index])
        str->data[index] += DIFF_ALPHA_CASES;
}

void    ft_string_toupper(string_t *str)
{
    int index;

    index = -1;
    while (str->data[++index])
        str->data[index] -= DIFF_ALPHA_CASES;
}

bool    ft_string_compare(string_t *str1, string_t *str2)
{
    if (!ft_strcmp(str1->data, str2->data))
        return true;
    return false;
}
bool    ft_string_compare2(string_t *str1, char *str2)
{
    if (!ft_strcmp(str1->data, str2))
        return true;
    return false;
}