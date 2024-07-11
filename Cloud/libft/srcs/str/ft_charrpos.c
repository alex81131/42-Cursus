/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charrpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:11:11 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:06:26 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charrpos(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == 0)
		return (i);
	while (i--)
		if (s[i] == c)
			return (i);
	return (0);
}
