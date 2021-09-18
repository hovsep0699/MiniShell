#ifndef CSTRING_H
#define CSTRING_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "ctypes.h"
# include "cstdlib.h"

#define DIFF_ALPHA_CASES 32
typedef struct string string_t;

struct string
{

    char                *data;
    size_t              size;
    void                (*resize)(string_t *str, size_t size);
    void                (*erase)(string_t *str, size_t it);
    void                (*erase2)(string_t *str, size_t it, size_t len);
    void                (*erase_between)(string_t *str, size_t start, size_t end);
    void                (*join)(string_t *str1, string_t *str2);
    void                (*join2)(string_t *str1, char *str2);
    void                (*substr)(string_t *str, string_t *new, size_t start, size_t len);
    void                (*insert2)(string_t *str, size_t index, char *str2);
    void                (*insert)(string_t *str, size_t index, string_t *str2);
    int                 (*find)(string_t *str, char c);
    int                 (*find2)(string_t *str, char *needle);
    int                 (*find3)(string_t *str, string_t *needle);
    int                 (*rfind)(string_t *str, char c);
    int                 (*rfind2)(string_t *str, char *needle);
    int                 (*rfind3)(string_t *str, string_t *needle);
    void                (*reverse)(string_t *str);
    void                (*tolower)(string_t *str);
    void                (*toupper)(string_t *str);
    bool                (*compare)(string_t *str1, string_t *str2);
    bool                (*compare2)(string_t *str1, char *str2);
};

void                ft_string_tolower(string_t *str);

bool                ft_string_compare(string_t *str1, string_t *str2);

bool                ft_string_compare2(string_t *str1, char *str2);

void                ft_string_toupper(string_t *str);

void                ft_string_insert(string_t *str, size_t index, string_t *str2);

void                ft_string_join(string_t *str, string_t *str2);

void                ft_string_insert2(string_t *str, size_t index, char *str2);

void                ft_string_join2(string_t *str, char *str2);

int                 ft_string_find(string_t *str, char c);

int                 ft_string_find2(string_t *str, char *needle);

int                 ft_string_find3(string_t *str, string_t *needle);

int                 ft_string_rfind(string_t *str, char c);

int                 ft_string_rfind2(string_t *str, char *needle);

int                 ft_string_rfind3(string_t *str, string_t *needle);

void                ft_string_substr(string_t *str, string_t *new, size_t start, size_t len);

string_t            ft_string_default_constructor(void);

string_t            ft_string_copy_constructor(string_t *str);

void                ft_string_resize(string_t *str, size_t size);

void                ft_string_erase(string_t *str, size_t it);

void                ft_string_erase2(string_t *str, size_t it, size_t len);

void                ft_string_erase_between(string_t *str, size_t start, size_t end);

string_t            ft_string_constructor(char *str);

void                ft_string_destructor(string_t *str);

bool				ft_findchr(const char *s, int c);

size_t				ft_zero_byte_strlen(const char *s1);

char				*ft_realloc_strjoin(char *s1, char *s2);

size_t				ft_vecstrlen(char **str);

void				ft_putchar(char c);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr(char *s);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl(char *s);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr(int n);

void				ft_putnbr_fd(int n, int fd);

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				ft_strdel(char **str);

bool				ft_strequ(char const *str1, char const *str2);

int					ft_atoi_error(const char *str);

char				**ft_strsplit(char const *s, char c);

int					ft_atoi(const char *str);

size_t				ft_strlen(const char *str);

char				*ft_strcat(char *dest, const char *src);

char				*ft_strncat(char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

int					ft_strcmp(const char *str1, const char *str2);

int					ft_strncmp(const char *str1, const char *str2, size_t n);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strncpy(char *dst, const char *src, size_t len);

size_t				ft_strlcpy(char *st, const char *src, size_t dstsize);

char				*ft_strstr(const char *haystack, const char *needle);

char				*ft_strnstr(const char *haystack, const char *needle, size_t len);

char				*ft_strdup(const char *s1);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

char				*ft_vecstr_search(char **vecstr, char *search);

void				ft_vecstrdel(char ***vecstr);

char				*ft_strrev(char *str);

char				*ft_strjoin(char const *s1, char const *s2);

char				**ft_split(char const *s, char c);

char				*ft_itoa(int n);

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strtrim(char const *s1, char const *set);

char				*ft_strnew(size_t size);


























#endif
