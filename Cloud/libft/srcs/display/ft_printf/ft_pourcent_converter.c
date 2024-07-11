/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcent_converter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 09:36:30 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:03:07 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pourcent_converter(void)
{
	char *c;

	if (!(c = malloc(sizeof(char) * 2)))
		return (NULL);
	c[0] = '%';
	c[1] = 0;
	return (c);
}
