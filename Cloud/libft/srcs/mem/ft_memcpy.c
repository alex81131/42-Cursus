/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:07:19 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:05:47 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char		*s;
	unsigned char			*d;
	size_t					i;

	i = 0;
	if (!(dest) && !(src))
		return (NULL);
	s = (unsigned const char*)src;
	d = (unsigned char *)dest;
	while (n)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dest);
}
