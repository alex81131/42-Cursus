/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:06:37 by tclaudel          #+#    #+#             */
/*   Updated: 2020/04/22 15:05:13 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft.h"

typedef struct	s_printf
{
	char		flags[5];
	char		option;
	char		zero;
	char		sign;
	char		*str;
	int			fd;
	size_t		width;
	size_t		accu;
	size_t		return_size;
	size_t		current_size;
}				t_printf;

char			*ft_strjoin_zero(char *s1, char *s2);
char			*ft_c_converter(int nb, t_printf *pf);
char			*ft_d_converter(int nb, t_printf *pf);
char			*ft_i_converter(int nb);
char			*ft_s_converter(char *str, size_t width, char *flags);
char			*ft_p_converter(long long address, t_printf *pf);
char			*ft_u_converter(unsigned int nb);
char			*ft_x_converter(unsigned int nb);
char			*ft_upx_converter(unsigned int nb);
char			*ft_pourcent_converter(void);
int				ft_is_pourcent(char c);
int				ft_is_flag(char c);
int				ft_is_option(char c);
char			*ft_analyser(char *tmp, t_printf *pf, va_list ap);
t_printf		*ft_set_flags(t_printf *pf, char *str);
char			*ft_new_fmt(char *old, t_printf *pf);
char			*ft_set_width(char *str, t_printf *pf, va_list ap, size_t i);
char			*ft_router(char *str, t_printf *pf, va_list ap);
char			*ft_apply_flags(char *str, t_printf *pf);
char			*ft_apply_convert(t_printf *pf, va_list ap);
int				ft_isone_nine(int c);
int				ft_is_in_flags(char c, t_printf *pf);
char			*ft_zero_flag(char *str, t_printf *pf, char sign);
char			*ft_width_accu(char *str, t_printf *pf, int *sign, char *str2);
char			*ft_itoa_pf(int n, t_printf *pf);
int				ft_char_in_string(char c, char *str);

#endif
