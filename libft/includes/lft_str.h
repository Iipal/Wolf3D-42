/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:09:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/14 11:21:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_STR_H
# define LFT_STR_H

# include <string.h>
# include <stdlib.h>

# define _STR		typedef char*			string
# define _CSTR		typedef const char*		cstring
# define _USTR		typedef unsigned char*	ustring
# define _UCHAR		typedef unsigned char	uchar
# define _STRTAB	typedef char**			strtab

_STR;
_CSTR;
_USTR;
_UCHAR;
_STRTAB;

void	ft_strdel(string *as);
void	ft_strclr(string s);
void	ft_striter(string s, void (*f)(string));
void	ft_striteri(string s, void (*f)(unsigned int, string));

int		ft_atoi(string str);
int		ft_atoi_base(cstring str, int base);
int		ft_strcmp(cstring s1, cstring s2);
int		ft_strncmp(cstring s1, cstring s2, size_t n);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_count_if(char const *str, char const ch);
int		ft_strrepchr(cstring str, char find_sumbol, char replace_sumbol);

size_t	ft_strlen(cstring str);
size_t	ft_strlcat(string dest, cstring src,
						size_t dstsize);
size_t	ft_strlcpy(string dest, cstring str, size_t dstsize);

string	ft_itoa(int n);
string	ft_strdup(cstring src);
string	ft_strndup(cstring s1, size_t n);
string	ft_strcpy(string dest, cstring str);
string	ft_strncpy(string dest, cstring src, size_t len);
string	ft_strcat(string dest, cstring src);
string	ft_strncat(string dest, cstring src, size_t n);
string	ft_strchr(cstring s, int c);
string	ft_strrchr(cstring s, int c);
string	ft_strstr(cstring str, cstring to_find);
string	ft_strnstr(cstring str, cstring to_find, size_t len);
string	ft_strnew(size_t size);
string	ft_strmap(char const *s, char (*f)(char));
string	ft_strmapi(char const *s, char (*f)(unsigned int, char));
string	ft_strsub(char const *s, unsigned int start, size_t len);
string	ft_strjoin(char const *s1, char const *s2);
string	ft_strtrim(char const *s);
strtab	ft_strsplit(char const *s, char c);

#endif
