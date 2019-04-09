/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:04:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 12:24:03 by tmaluh           ###   ########.fr       */
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
# include <stddef.h>

/*
**	ft_gnl reading buffer size.
*/
# define BUFF_SIZE 2048

/*
**	For above school-42 norme cheats stuff:
*/
enum	e_bool {false, true} __attribute__((packed));

# define STR       typedef char*           string
# define CSTR      typedef const char*     cstring
# define USTR      typedef unsigned char*  ustring
# define UCHAR     typedef unsigned char   uchar
# define STRTAB    typedef char**          strtab
# define PVOID     typedef void*           pvoid
# define BOOL      typedef enum e_bool     bool

STR;
CSTR;
USTR;
UCHAR;
STRTAB;
PVOID;
BOOL;

/*
**	---------------------
**	My utilite functions:
**	---------------------
*/

/*
**	Reading file line by line. (Get Next Line)
**	\param fd: File descriptor.
**	\param line: pointer to string where will saved each line from file.
**	\return:
**	[0 - End of File.
**	 1 - Successful readed 1 line from file.
	 -1 - Reading error.]
*/
int8_t	ft_gnl(const int32_t fd, string *line);

/*
**	Randomize unsigned decimal number.
**	\param limits: Max random number.
**	\return random: number from 0 to \ref limits.
*/
size_t	ft_rand(size_t limits);

/*
**	Compare if one of \ref n arguments is equal to \ref cmp.
**	\param cmp: Value to compare.
**	\param n: Arguments counter in va_list.
**	\param ...: va_list.
**	\return true if one of argument is equal to \ref cmp, else - false.
*/
bool	ft_is_one_of_n(int64_t cmp, int64_t n, ...);

/*
**	Swap int32_t values.
*/
void	ft_swap(int32_t *a, int32_t *b);

/*
**	Swap char values.
*/
void	ft_cwap(char *a, char *b);

/*
**	-----------------
**	Output functions:
**	-----------------
*/

/*
**	Put \param c char to stdout.
*/
void	ft_putchar(char c);

/*
**	Put \param s string to stdout.
*/
void	ft_putstr(char const *s);

/*
**	Put \param s string to stdout followed by newline.
*/
void	ft_putendl(char const *s);

/*
**	Put \param n number to stdout.
*/
void	ft_putnbr(int32_t n);

/*
**	Put \param c char to specified \param fd output.
*/
void	ft_putchar_fd(char c, int32_t fd);

/*
**	Put \param s string to specified \param fd output.
*/
void	ft_putstr_fd(char const *s, int32_t fd);

/*
**	Put \param s string to specified \param fd output followed by newline.
*/
void	ft_putendl_fd(char const *s, int32_t fd);

/*
**	Put number \param n
*/
void	ft_putnbr_fd(int32_t n, int32_t fd);

/*
**	Print all strings from \param file to stdout or return false.
*/
bool	ft_putfile(string file);

/*
**	-----------------------
**	ctype.h libc functions:
**	-----------------------
*/

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII alphabet symbol, else - false.
*/
bool	ft_isalpha(uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII digit, else - false.
*/
bool	ft_isdigit(uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII alphabet symbol or is ASCII digit,
**	 else - false.
*/
bool	ft_isalnum(uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is lower ASCII symbol, else - false.
*/
bool	ft_isascii(uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII printable symbol, else - false.
*/
bool	ft_isprint(uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is lower case ASCII alphabet symbol, else - false.
*/
bool	ft_islower(uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is upper case ASCII alphabet symbol, else - false.
*/
bool	ft_isupper(uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is '\t' '\n' '\v' '\f' '\r' or ' ', else - false.
*/
bool	ft_isblank(uchar c);

/*
**	\param c - unsigned char.
**	\return If \ref c is lower case ASCII alphabet symbol
**	 return this symbol in upper case.
*/
uchar	ft_toupper(uchar c);

/*
**	\param c - unsigned char.
**	\return If \ref c is upper case ASCII alphabet symbol
**	 return this symbol in lower case.
*/
uchar	ft_tolower(uchar c);

/*
**	--------------------------------------------
**	strings.h libc\POSIX functions and my stuff:
**	--------------------------------------------
*/

/*
**	Free memory for string and set \param as to NULL.
**	\param as pointer to string.
*/
void	ft_strdel(string *as);

/*
**	Reverse string \param str.
*/
void	ft_strrev(string str);

/*
**	Replace all \param search symbols in string \param str to \param replace.
*/
bool	ft_strrepchr(cstring str, char search, char replace);

/*
**	Convert string \param str to int32_t number.
**	\return 0 if string \param str is invalid,
**	 else - number which contained in string.
*/
int32_t	ft_atoi(string str);

/*
**	Convert string \param str to int32_t number in \param base notation.
**	\return 0 if string \param str is invalid,
**	 else - number which contained in string converted in \param base notation.
*/
int32_t	ft_atoi_base(cstring str, int8_t base);

/*
**	Compare string \param s1 with \param s2.
**	\return difference of not matching symbols or 0 if strings equal.
*/
int8_t	ft_strcmp(cstring s1, cstring s2);

/*
**	Compare string \param s1 with \param s2 by \param n symbols.
**	\return difference of not matching symbols or 0 if strings equal.
*/
int8_t	ft_strncmp(cstring s1, cstring s2, size_t n);

/*
**	\return lenght of string \param str.
*/
size_t	ft_strlen(cstring str);

/*
**	Appends the NUL-terminated string \param src to the end of \param dest.
**	It will append at most \param dstsize - ft_strlen(\param dst) - 1 bytes,
**	 NUL-terminating the result.
*/
size_t	ft_strlcat(string dest, cstring src, size_t dstsize);

/*
**	Copies up to \param dstsize - 1 symbols from the NUL-terminated
**	 string \param str to \param dest, NUL-terminating the result.
*/
size_t	ft_strlcpy(string dest, cstring str, size_t dstsize);

/*
**	\return convert number \param n to string.
*/
string	ft_itoa(int32_t n);

/*
**	\return converted string \str alphabet symbols to lower case.
*/
string	ft_strlwr(string str);

/*
**	\return converted string \str alphabet symbols to upper case.
*/
string	ft_strupr(string str);

/*
**	\return new allocated copy string \param src
**	 or NULL if something went wrong.
*/
string	ft_strdup(cstring src);

/*
**	\return new allocated copied \param n symbols from string \param src
**	 or NULL if something went wrong.
*/
string	ft_strndup(cstring s1, size_t n);

/*
**	Copy string \param str to \param dest.
**	\return \param dest.
*/
string	ft_strcpy(string dest, cstring str);

/*
**	Copy \param len of \param src to \param dest.
**	\return \param dest.
*/
string	ft_strncpy(string dest, cstring src, size_t len);

/*
**	Appends string \param src to \param dest.
**	\return \param dest.
*/
string	ft_strcat(string dest, cstring src);

/*
**	Appends \param n symbols from string \param src to \param dest.
**	\return \param dest.
*/
string	ft_strncat(string dest, cstring src, size_t n);

/*
** \return a pointer to the first occurrence of the character \param c
**	 in the string \param s.
*/
string	ft_strchr(cstring s, uchar c);

/*
**	\return a pointer to the last occurrence of the character \param c
**	 in the string \param s
*/
string	ft_strrchr(cstring s, uchar c);

/*
** \return the first occurrence of the substring \param to_find
**  in the string \param str.
*/
string	ft_strstr(cstring str, cstring to_find);

/*
** \return the first occurrence of the null-termi-nated string
**	 \param to_find in the string \param str,
**	 where not more than \param len characters are searched.
*/
string	ft_strnstr(cstring str, cstring to_find, size_t len);

/*
**	\return allocate null-termi-nated string.
*/
string	ft_strnew(size_t size);

/*
**	\return allocate a “fresh” substring from the string \param s argument.
**	 The substring begins at index \param start and is of size \param len.
**	 If \param start and \param len aren’t refering to a valid substring,
**	 the behavior is undefined. If the allocation fails, returns NULL.
*/
string	ft_strsub(char const *s, uint32_t start, size_t len);

/*
**	\return allocate a “fresh” string ending with ’\0’,
**	 result of the concatenation of \param s1 and \param s2.
**	 If the allocation fails the function returns NULL.
*/
string	ft_strjoin(char const *s1, char const *s2);

/*
**	\return allocate a copy of the string \param s without whitespaces
**	 at the beginning or at the end of the string.
**	 Will be considered as whitespaces the following characters ’ ’, ’\n’, ’\t’.
**	 If s has no whitespaces at the beginning or at the end,
**	 the function returns a copy of \param s.
**	 If the allocation fails the function returns NULL.
*/
string	ft_strtrim(char const *s);

/*
** \return allocate an array of “fresh” strings (all ending with ’\0’,
**	 including the array itself) obtained by spliting \param s
**	 using the character \param c as a delimiter.
**	 If the allocation fails the function returns NULL.
*/
strtab	ft_strsplit(char const *s, char c);


/*
**	------------------------
**	stdlib.h libc functions:
**	------------------------
*/

/*
**	Erases the data in the \param n bytes of \param s,
**	 by writing zeros('\0') to that area.
*/
void	ft_bzero(pvoid s, size_t n);

/*
**	Free memory at pointer \param ap.
*/
void	ft_memdel(pvoid *ap);

/*
**	\return \param dest where fills the first \param len bytes of
**	 \param dest with the \param c.
*/
pvoid	ft_memset(pvoid dest, int32_t c, size_t len);

/*
**	\return \param dest where copies \param n bytes from
**	 \param src to \param dest.
*/
pvoid	ft_memcpy(pvoid dest, const pvoid src, size_t n);

/*
**	\return \param dest where copies no more than \param n bytes from
**	 \param src to \pararm dest, stopping when the symbol \param c is found.
*/
pvoid	ft_memccpy(pvoid dest, const pvoid src, uint8_t c, size_t n);

/*
**	\return \param dest where copies
**	\param len bytes from \param src to \param dest.
*/
pvoid	ft_memmove(pvoid dest, void const *src, size_t len);

/*
**	\return matching byte of \param s after scans the initial \param n bytes
**	 of \param s for the first instance of c.
*/
pvoid	ft_memchr(const pvoid s, uint8_t c, size_t n);

/*
**	\return pointer to allocated \param size bytes.
*/
pvoid	ft_memalloc(size_t size);

/*
**	Compares the first \param n bytes of \param s1 and \param s2.
**	\return an integer less than, equal to, or greater than zero
**	 if the first \param n bytes of \param s1 is found,
**	 respectively, to be less than, to match,
**	 or be greater than the first \param n bytes of \param s2.
*/
int32_t	ft_memcmp(const pvoid s1, const pvoid s2, size_t n);

#endif
