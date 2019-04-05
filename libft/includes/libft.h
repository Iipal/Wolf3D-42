/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:04:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/05 12:55:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdlib.h>

# define BUFF_SIZE 2048

enum	e_bool {false, true} __attribute__((packed));

# define _STR       typedef char*           string
# define _CSTR      typedef const char*     cstring
# define _USTR      typedef unsigned char*  ustring
# define _UCHAR     typedef unsigned char   uchar
# define _STRTAB    typedef char**          strtab
# define _PVOID     typedef void*           pvoid
# define _BOOL      typedef enum e_bool     bool

_STR;
_CSTR;
_USTR;
_UCHAR;
_STRTAB;
_PVOID;
_BOOL;

/*
**	My utilite functions:
*/
int32_t	ft_gnl(const int32_t fd, char **line);
size_t	ft_rand(size_t limits);
bool	ft_is_one_of_n(int64_t cmp, int64_t n, ...);
void	ft_swap(int32_t *a, int32_t *b);
void	ft_cwap(char *a, char *b);

/*
**	Output functions:
*/
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int32_t n);
void	ft_putchar_fd(char c, int32_t fd);
void	ft_putstr_fd(char const *s, int32_t fd);
void	ft_putendl_fd(char const *s, int32_t fd);
void	ft_putnbr_fd(int32_t n, int32_t fd);

/*
**	ctype.h libc functions:
*/
bool	ft_isalpha(uint8_t c);
bool	ft_isdigit(uint8_t c);
bool	ft_isalnum(uint8_t c);
bool	ft_isascii(uint8_t c);
bool	ft_isprint(uint8_t c);
bool	ft_islower(uint8_t c);
bool	ft_isupper(uint8_t c);
bool	ft_isblank(uint8_t c);
bool	ft_toupper(uint8_t c);
bool	ft_tolower(uint8_t c);

/*
**	strings.h libc\POSIX functions and ma stuff:
*/
void	ft_strdel(string *as);
void	ft_strrev(string str);

bool	ft_strrepchr(cstring str, char find_sumbol, char replace_sumbol);
bool	ft_strlwr(string str);
bool	ft_strupr(string str);

int32_t	ft_atoi(string str);
int32_t	ft_atoi_base(cstring str, int8_t base);
int8_t	ft_strcmp(cstring s1, cstring s2);
int8_t	ft_strncmp(cstring s1, cstring s2, size_t n);

size_t	ft_strlen(cstring str);
size_t	ft_strlcat(string dest, cstring src,
						size_t dstsize);
size_t	ft_strlcpy(string dest, cstring str, size_t dstsize);

string	ft_itoa(int32_t n);
string	ft_strdup(cstring src);
string	ft_strndup(cstring s1, size_t n);
string	ft_strcpy(string dest, cstring str);
string	ft_strncpy(string dest, cstring src, size_t len);
string	ft_strcat(string dest, cstring src);
string	ft_strncat(string dest, cstring src, size_t n);
string	ft_strchr(cstring s, uint8_t c);
string	ft_strrchr(cstring s, uint8_t c);
string	ft_strstr(cstring str, cstring to_find);
string	ft_strnstr(cstring str, cstring to_find, size_t len);
string	ft_strnew(size_t size);
string	ft_strsub(char const *s, uint32_t start, size_t len);
string	ft_strjoin(char const *s1, char const *s2);
string	ft_strtrim(char const *s);
strtab	ft_strsplit(char const *s, char c);

/*
**	stdlib.h libc functions:
*/
void	ft_bzero(pvoid s, size_t n);
void	ft_memdel(pvoid *ap);

pvoid	ft_memset(pvoid b, int32_t c, size_t len);
pvoid	ft_memcpy(pvoid dest, const pvoid src, size_t n);
pvoid	ft_memccpy(pvoid dest, const pvoid src, uint8_t c, size_t n);
pvoid	ft_memmove(pvoid dest, void const *src, size_t len);
pvoid	ft_memchr(const pvoid s, uint8_t c, size_t n);
pvoid	ft_memalloc(size_t size);

int32_t	ft_memcmp(const pvoid s1, const pvoid s2, size_t n);

#endif
