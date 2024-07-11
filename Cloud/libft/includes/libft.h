/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:46:51 by tclaudel          #+#    #+#             */
/*   Updated: 2020/04/22 15:06:34 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BLUE "\033[0;38;5;123m"
# define LIGHT_PINK "\033[0;38;5;200m"
# define PINK "\033[0;38;5;198m"
# define DARK_BLUE "\033[1;38;5;110m"
# define GREEN "\033[1;32;111m"
# define LIGHT_GREEN "\033[0;38;5;121m"
# define LIGHT_RED "\033[0;31;5;110m"
# define FLASH_GREEN "\033[33;32m"
# define WHITE_BOLD "\033[37m"
# define GREY "\033[3;90m"
# define ORANGE "\033[3;91m"
# define YELLOW "\033[0;33m"
# define YELLOW_BOLD "\033[1;33m"
# define RESET   "\033[0m"
# define WHITESPACES " \t\n\v\f\r"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

/*
** HASH
*/

typedef struct		s_hash
{
	char			*key;
	void			*value;
	char			*type;
	struct s_hash	*top;
	struct s_hash	*before;
	struct s_hash	*next;
	struct s_hash	*(*new)(char *, void *, char *);
	void			(*del)(struct s_hash **, struct s_hash *, struct s_hash *);
	void			(*print)(struct s_hash *, char *);
	void			(*add_back)(struct s_hash **, struct s_hash *);
	void			(*add_front)(struct s_hash **, struct s_hash *);
	void			(*del_all)(struct s_hash **);
	void			*(*search)(struct s_hash *, char *);
	size_t			(*len)(struct s_hash *);
	void			(*change)(struct s_hash *, char *, void *, char *);
	void			(*sort_key)(struct s_hash **, struct s_hash *);
	void			(*rsort_key)(struct s_hash **, struct s_hash *);
	void			(*sort_val)(struct s_hash **, struct s_hash *);
	void			(*rsort_val)(struct s_hash **, struct s_hash *);
	struct s_hash	*(*find)(struct s_hash *, char *);
}					t_hash;

void				ft_hashadd_front(t_hash **hash, t_hash *new);
void				ft_hashadd_back(t_hash **hash, t_hash *new);
void				ft_hashdel(t_hash **hash, t_hash *before, t_hash *next);
void				ft_hash_display(t_hash *hash, char *name);
void				ft_hash_free(t_hash **hash);
void				*ft_hash_search_value(t_hash *hash, char *key);
void				ft_hash_change_value(t_hash *hash, char *key,
					void *value, char *type);
void				ft_hash_sort_key(t_hash **alst, t_hash *hash);
void				ft_hash_revsort_key(t_hash **alst, t_hash *hash);
void				ft_hash_sort_value(t_hash **alst, t_hash *hash);
void				ft_hash_revsort_value(t_hash **alst, t_hash *hash);
size_t				ft_hashlen(t_hash *hash);
t_hash				*ft_hash_init(void);
t_hash				*ft_hashnew(char *key, void *value, char *type);
t_hash				*ft_hash_find(t_hash *hash, char *key);

typedef struct		s_strhash
{
	char	*key;
	char	*value;
}					t_strhash;

/*
** ALLOC
*/

void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);

/*
** LIST
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

/*
** CHAR
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** CONVERT
*/

int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);
char				*ft_itoa_u_base(unsigned int n, char *base);
char				*ft_itoa_ll_base(unsigned long n, char *base);
char				*ft_itoa_base(int n, char *base);

/*
** DISPLAY
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *str);
void				ft_putchar(char c);
int					ft_sprintf(char	*str, const char *s, ...);
int					ft_dprintf(int fd, const char *s, ...);
int					ft_printf(const char *s, ...);
int					ft_printfducul(char *s, ...);
void				ft_display_tab(char **tab, char *tabname);

/*
** MEM
*/

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memjoin(void *s1, void *s2, size_t size1, size_t size2);

/*
** STR
*/

size_t				ft_tablen(char **str);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *fi, const char *se, size_t len);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *dest, const char *src, size_t count);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(const char *s, char c);
char				*ft_strrev(char *str);
size_t				ft_strnlen(const char *str, size_t maxlen);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strfjoin(char *s1, char *s2, int free);
char				*ft_strtok(char *s, const char *charset);
size_t				ft_strcspn(char *s1, const char *s2);
size_t				ft_strspn(char *s1, const char *s2);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_count_whitespaces(char *str);
size_t				ft_charpos(const char *s, int c);
size_t				ft_charrpos(const char *s, int c);
char				*ft_clearcharset(char *str, char *charset, int free);
char				*ft_insert(char *src, char *insered, size_t n, int free);
size_t				ft_char_counter(char *s, char c);
char				**ft_tabjoin(char **t1, char **t2);

/*
** FREE
*/

void				ft_strdel(char **ptr);
int					ft_free_tab(char **strs);
void				ft_memdel(void **ptr);

/*
** READ
*/

ssize_t				get_next_line(int fd, char **line);

/*
** HASH
*/

t_strhash			*ft_strhash(char **key, char **value);
char				*ft_get_hash_value(t_strhash *hash, char *str);
void				*change_value(t_strhash *hash, char *str, char *new);

#endif
