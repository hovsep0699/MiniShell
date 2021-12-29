/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:08:48 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/29 20:28:41 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTRING_H
# define CSTRING_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "ctypes.h"
# include "cstdlib.h"

# define DIFF_ALPHA_CASES 32

typedef struct s_string	t_string;
typedef struct s_sph	t_sph;

typedef void			(*t_resize)\
(t_string *str, size_t size);
typedef void			(*t_erase)\
(t_string *str, size_t it);
typedef void			(*t_erase2)\
(t_string *str, size_t it, size_t len);
typedef void			(*t_erase_between)\
(t_string *str, size_t start, size_t end);
typedef void			(*t_join)\
(t_string *str1, t_string *str2);
typedef void			(*t_join2)\
(t_string *str1, char *str2);
typedef void			(*t_substr)\
(t_string *str, t_string *new, size_t start, size_t len);
typedef void			(*t_insert2)\
(t_string *str, size_t index, char *str2);
typedef void			(*t_insert)\
(t_string *str, size_t index, t_string *str2);
typedef int				(*t_find)\
(t_string *str, char c);
typedef int				(*t_find2)\
(t_string *str, char *needle);
typedef int				(*t_find3)\
(t_string *str, t_string *needle);
typedef int				(*t_rfind)\
(t_string *str, char c);
typedef int				(*t_rfind2)\
(t_string *str, char *needle);
typedef int				(*t_rfind3)\
(t_string *str, t_string *needle);
typedef int				(*t_rfind4)\
(t_string *str, char c, int index);
typedef void			(*t_reverse)\
(t_string *str);
typedef void			(*t_tolower)\
(t_string *str);
typedef void			(*t_toupper)\
(t_string *str);
typedef bool			(*t_compare)\
(t_string	*str1, t_string *str2);
typedef bool			(*t_compare2)\
(t_string *str1, char *str2);

struct s_sph
{
	int		si;
	int		in;
	char	**spa;
};

struct s_string
{
	char			*data;
	size_t			size;
	t_resize		resize;
	t_erase			erase;
	t_erase2		erase2;
	t_erase_between	erase_between;
	t_join			join;
	t_join2			join2;
	t_substr		substr;
	t_insert2		insert2;
	t_insert		insert;
	t_find			find;
	t_find2			find2;
	t_find3			find3;
	t_rfind			rfind;
	t_rfind2		rfind2;
	t_rfind3		rfind3;
	t_rfind4		rfind4;
	t_reverse		reverse;
	t_tolower		tolower;
	t_toupper		toupper;
	t_compare		compare;
	t_compare2		compare2;
};

void		ft_t_stringolower(t_string *str);

bool		ft_string_compare(t_string *str1, t_string *str2);

bool		ft_string_compare2(t_string *str1, char *str2);

void		ft_t_stringoupper(t_string *str);

void		ft_string_insert(t_string *str, size_t index, t_string *str2);

void		ft_string_join(t_string *str, t_string *str2);

void		ft_string_insert2(t_string *str, size_t index, char *str2);

void		ft_string_join2(t_string *str, char *str2);

int			ft_string_find(t_string *str, char c);

int			ft_string_find2(t_string *str, char *needle);

int			ft_string_find3(t_string *str, t_string *needle);

int			ft_string_rfind(t_string *str, char c);

int			ft_string_rfind2(t_string *str, char *needle);

int			ft_string_rfind3(t_string *str, t_string *needle);

void		ft_ssubstr(t_string *str, t_string *new, size_t start, size_t len);

t_string	ft_string_default_constructor(void);

t_string	ft_string_copy_constructor(t_string *str);

void		ft_string_resize(t_string *str, size_t size);

void		ft_string_erase(t_string *str, size_t it);

void		ft_string_erase2(t_string *str, size_t it, size_t len);

void		ft_string_erase_between(t_string *str, size_t start, size_t end);

t_string	ft_string_constructor(char *str);

void		ft_string_destructor(t_string *str);

bool		ft_findchr(const char *s, int c);

size_t		ft_zero_byte_strlen(const char *s1);

char		*ft_realloc_strjoin(char *s1, char *s2);

size_t		ft_vecstrlen(char **str);

void		ft_putchar(char c);

void		ft_putchar_fd(char c, int fd);

void		ft_putstr(char *s);

void		ft_putstr_fd(char *s, int fd);

void		ft_putendl(char *s);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr(int n);

void		ft_putnbr_fd(int n, int fd);

void		*ft_memset(void *b, int c, size_t len);

void		ft_bzero(void *s, size_t n);

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		*ft_memccpy(void *dst, const void *src, int c, size_t n);

void		*ft_memchr(const void *s, int c, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t len);

void		ft_strdel(char **str);

bool		ft_strequ(char const *str1, char const *str2);

int			ft_atoi_error(const char *str);

char		**ft_strsplit(char const *s, char c);

int			ft_atoi(const char *str);

size_t		ft_strlen(const char *str);

char		*ft_strcat(char *dest, const char *src);

char		*ft_strncat(char *s1, const char *s2, size_t n);

size_t		ft_strlcat(char *dst, const char *src, size_t size);

int			ft_strcmp(const char *str1, const char *str2);

int			ft_strncmp(const char *str1, const char *str2, size_t n);

char		*ft_strcpy(char *dest, const char *src);

char		*ft_strncpy(char *dst, const char *src, size_t len);

size_t		ft_strlcpy(char *st, const char *src, size_t dstsize);

char		*ft_strstr(const char *haystack, const char *needle);

char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

char		*ft_strdup(const char *s1);

char		*ft_strchr(const char *s, int c);

char		*ft_strrchr(const char *s, int c);

char		*ft_vecstr_search(char **vecstr, char *search);

void		ft_vecstrdel(char ***vecstr);

char		*ft_strrev(char *str);

char		*ft_strjoin(char const *s1, char const *s2);

char		**ft_split(char const *s, char c);

char		*ft_itoa(int n);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char		*ft_strtrim(char const *s1, char const *set);

char		*ft_strnew(size_t size);

int			ft_vecstr_search1(char **vecstr, char *search);

int			ft_vecstr_search2(char **vecstr, char *search, int start_index);

char		**ft_vecstrcpy(char **vecstr);

char		**ft_vecstrncpy(char **vecstr, int n);

void		ft_vecstrprint(char **vecstr);

bool		ft_isnum_str(char *str);

char		**ft_vecstrinit(int size);

int			ft_string_rfind4(t_string *str, char c, int start);

char		**ft_vecstrlcpy(char **vecstr, int start, int n);

char		**ft_fvecstrcpy(char **vecstr1, char **vecstr2);

int			ft_vecstr_search3(char **vecstr, char *search, int start_index);

#endif
