/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:27:34 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/10 15:47:12 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
//	<ft_printf>
# include <stdarg.h>
//	<get_next_line>
# include <fcntl.h>

//	<libft>
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;
//		<ctype.h>
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
//		<string.h>
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strdup(const char *src);
//		<stdlib.h>
int		ft_atoi(const char *str);
int		ft_atoi_base(const char *str, const char *base);
void	*ft_calloc(size_t nmemb, size_t size);
//		<stdio.h>
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
//		Non-standard functions
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
//		Linked list functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstclear_no_content(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//	<ft_printf>
//		<printf_fd>
int		ft_printf_fd(int fd, const char *format, ...);
int		ft_putptr_fd(uintptr_t ptr, int fd);
int		ft_puthex_fd(unsigned int n, const char format, int fd);

int		ft_printf(const char *format, ...);
//		<printf>
int		ft_putchar(int c);
int		ft_putstr(char *str);
//		<int_decimal>
char	*ft_inttochar(char *str, unsigned int m, unsigned int len);
int		ft_putnbr(int n);
//		<unsigned_int>
int		ft_uputnbr(unsigned int n);
char	*ft_uitoa(unsigned int n);
//		<number_hex>
int		hex_digit(unsigned int n);
int		ft_puthex(unsigned int n, const char format);
//		<ptr>
int		ptr_digit(uintptr_t n);
int		ft_putptr(uintptr_t ptr);
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//	<get_next_line>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

char	*get_next_line(int fd);
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//	<fdf>
//		utils.c
void	free_array(char **array);
//		error.c
void	err_exit(const char *err, const char *msg);
void	perror_exit(const char *msg);
//		handle_arg.c
void	ft_tolower_char(char *c);
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//	<Minishell>
char	*ft_strndup(const char *str, int n);
char	*ft_strjoin_free(char *s1, char *s2, int option);

#endif
