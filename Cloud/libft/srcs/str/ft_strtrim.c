/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:06:56 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:43:34 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_charinstr(const char c, const char *sep)
{
	size_t		i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char				*ft_strtrim(const char *s1, const char *set)
{
	size_t		i;
	size_t		j;
	size_t		lmalloc;
	char		*str;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_charinstr(s1[i], set) && s1[i])
		i++;
	if (i - 1 == j)
	{
		if (!(str = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		str[0] = 0;
		return (str);
	}
	while (ft_charinstr(s1[j], set))
		j--;
	lmalloc = (j - i + 1);
	if (!(str = ft_strndup((s1 + i), lmalloc)))
		return (NULL);
	return (str);
}
