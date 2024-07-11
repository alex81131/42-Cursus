/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:29:42 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:00:20 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		l;
	size_t		lmalloc;
	char		*str;

	i = 0;
	l = ft_strlen(s);
	if ((start >= l) || (len == 0))
		return (ft_calloc(sizeof(char), 1));
	lmalloc = (start - l < len ? start - l : len);
	if (!(str = (char*)malloc(sizeof(char) * (lmalloc + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
