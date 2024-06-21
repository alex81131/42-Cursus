/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:40:16 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/21 19:53:06 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

//		<printf_fd>
int		ft_printf_fd(int fd, const char *format, ...);
int		ft_putptr_fd(uintptr_t ptr, int fd);
int		ft_uputnbr_fd(unsigned int n, int fd);
int		ft_puthex_fd(unsigned int n, const char format, int fd);

int		ft_printf(const char *format, ...);
//		<printf>
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_input_printf(va_list vl, const char format);
int		ft_printf(const char *format, ...);
//		<int_decimal>
int		ft_digit(int n);
char	*ft_inttochar(char *str, unsigned int m, int len);
char	*ft_itoa(int n);
int		ft_putnbr(int n);
//		<unsigned_int>
int		ft_udigit(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_uputnbr(unsigned int n);
//		<number_hex>
int		hex_digit(unsigned int n);
void	ft_put_hex(unsigned int n, const char format);
int		ft_puthex(unsigned int n, const char format);
//		<ptr>
int		ptr_digit(uintptr_t n);
void	ft_put_ptr(uintptr_t n);
int		ft_putptr(uintptr_t ptr);

#endif