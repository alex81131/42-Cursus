/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 08:15:44 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:07:03 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char*)s + i);
		}
		i++;
	}
	if (s[i] == c)
		return ((char*)s + i);
	return (NULL);
}
