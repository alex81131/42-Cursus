/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:47:02 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:04:04 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_x_converter(unsigned int nb)
{
	char *base;

	base = "0123456789abcdef";
	return (ft_itoa_u_base((nb), base));
}
