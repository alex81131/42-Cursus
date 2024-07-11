/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:43:40 by tclaudel          #+#    #+#             */
/*   Updated: 2020/03/09 15:44:19 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert(char *src, char *insered, size_t n, int len)
{
	char	*dest;

	dest = ft_strndup(src, n);
	dest = ft_strfjoin(dest, insered, 1);
	dest = ft_strfjoin(dest, src + n + len, 1);
	ft_strdel(&src);
	return (dest);
}
