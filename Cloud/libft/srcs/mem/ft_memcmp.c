/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:19:28 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:05:30 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*f;
	char	*s;
	size_t	i;

	i = 0;
	f = (char *)s1;
	s = (char *)s2;
	if (n == 0)
		return (0);
	while (i < n && f[i] == s[i])
		i++;
	if (i == n)
		i--;
	return ((unsigned char)f[i] - (unsigned char)s[i]);
}
