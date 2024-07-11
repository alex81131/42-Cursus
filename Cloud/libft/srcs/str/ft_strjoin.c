/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:28:56 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:07:20 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		lmalloc;
	char		*str;
	size_t		i;
	size_t		ls1;

	i = 0;
	ls1 = ft_strlen(s1);
	lmalloc = ls1 + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (lmalloc + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[i + ls1] = s2[i];
		i++;
	}
	str[i + ls1] = '\0';
	return (str);
}
