/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:01:50 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:07:40 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *fi, const char *se, size_t len)
{
	const unsigned char	*f;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	f = (const unsigned char *)fi;
	s = (const unsigned char *)se;
	if (len == 0)
		return (0);
	while (i < len && f[i] == s[i] && f[i] != '\0')
		i++;
	if (i == len)
		i--;
	return ((unsigned char)f[i] - s[i]);
}
