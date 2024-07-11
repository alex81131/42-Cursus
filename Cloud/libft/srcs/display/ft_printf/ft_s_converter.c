/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:38:30 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:03:27 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_s_converter(char *str, size_t accu, char *flags)
{
	if (ft_char_in_string('.', flags) && accu == 0)
		return (ft_strdup(""));
	if (!str)
		str = "(null)";
	if (ft_char_in_string('.', flags) && accu < ft_strlen(str))
		return (ft_strndup(str, accu));
	return (ft_strdup(str));
}
