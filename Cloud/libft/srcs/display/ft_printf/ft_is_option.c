/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:06:57 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:02:44 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_option(char c)
{
	char	*options;
	int		i;

	i = 0;
	options = "cspdiuxX%";
	while (options[i])
	{
		if (options[i] == c)
			return (1);
		i++;
	}
	return (0);
}
