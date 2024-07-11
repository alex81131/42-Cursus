/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:54:09 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:07:25 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t i;
	size_t y;
	size_t sizea;
	size_t sizeb;

	sizea = 0;
	sizeb = 0;
	while (dest[sizea] != '\0')
		sizea++;
	while (src[sizeb] != '\0')
		sizeb++;
	if (count <= sizea)
		return (sizeb + count);
	i = 0;
	while (dest[i] != '\0' && i < count - 1)
		i++;
	y = 0;
	while (src[y] != '\0' && count - 1 > i)
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (sizea + sizeb);
}
