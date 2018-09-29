/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/09/09 14:03:56 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIBFT_H
# define LIBFT_LIBFT_H

# include <inttypes.h>
# include <sys/_types/_size_t.h>
# include <sys/_types/_null.h>
# include <stdbool.h>

# define SPACE_CHARS (" \n\t\v\f\r")

int				ft_charinsequal(char c1, char c2);
void			*ft_realloc(void *data, size_t old_size, size_t new_size);
void			*ft_memset(void *dst, int c, size_t n);
void			ft_bzero(void *dst, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strlen(const char *src);
int				ft_strclen(const char *str, char c);
int				ft_strslen(const char *str, const char *c);
char			*ft_strdup(char *src);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_emplace_string(char *dst, const char *src, int pos);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t siz);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isalpha(int c);
int				ft_isnum(char *s);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_toupper(int c);
char			*ft_strtoupper(char *str);
int				ft_tolower(int c);
int				ft_isspace(char c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			free_array_of_strings(char ***words);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, size_t start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strjoin_front(char *s1, char *s2);
char			*ft_strjoin_back(char *s1, char *s2);
char			*ft_strjoin_both(char *s1, char *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c, int *num_words);
char			**ft_strssplit(
					const char *s,
					char *split_char,
					int *num_words);
char			**ft_split_once(
					const char *s,
					char *split_char,
					char *skip_chars);
void			ft_strsplit_release(char **words, int num_words);
char			*ft_strrmchar(char *str, const char *rm_chars);
char			*ft_strremovespaces(char *str);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
char			*ft_strrev(char *str);
int				ft_power(int nb, int pow);
double			ft_fpower(double nbr, int pow);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
void			ft_swap(int *a, int *b);
char			*ft_strupcase(char *str);
char			*ft_strlowcase(char *str);
int				ft_strisupper(char *str);
int				ft_strislower(char *str);
int				ft_strisalpha(char *str);
int				ft_strisdigit(char *str);
bool			ft_strisnumber(char *s);
bool			ft_strisspace(const char *str);
char			*ft_strtrim(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_countwords(const char *str, char c);
int				ft_countwordss(const char *str, char *c);
char			*ft_getword(const char *s, char c, int *i);
char			*ft_getsword(const char *s, char *c, int *i);
int				ft_sizeofnumber(int n);
int				ft_get_size(long long n, int base);
int				ft_atoi_base(const char *s, int base);
int				*ft_strsplittoint(char const *s, char c);
char			*ft_merge(char *a, char *b);
void			reverse_int_array(int *arr, int size);

/*
**	Filesystem
*/

int				is_directory(const char *path);
size_t			ft_read_file(const char *path, void **file);
size_t			ft_read_file_fd(int fd, void **file);
void			*map_file(const char *path, int64_t *size);
void			unmap_file(const void *file_ptr, int64_t size);
char			*fs_parent_dir(const char *path);

typedef struct	s_pair
{
	void		*first;
	void		*second;
}				t_pair;
extern t_pair	make_pair(void *first, void *second);
t_pair			*alloc_pair(void *first, void *second);

typedef struct	s_tuple
{
	void		*first;
	void		*second;
	void		*third;
}				t_tuple;
extern t_tuple	make_tuple(void *first, void *second, void *third);

int				ft_atoi(const char *str);
int				ft_natoi(const char *str, int max_len);
int				ft_atoi_end(const char *str, char **end);
double			ft_atod(const char *s);
double			ft_atod_end(const char *s, char **end);

char			*fs_change_extension(const char *path, const char *new_ext);
const char		*fs_file_name(const char *path);

#endif
