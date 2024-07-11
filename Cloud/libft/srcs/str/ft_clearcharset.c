/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearcharset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:19:06 by tclaudel          #+#    #+#             */
/*   Updated: 2020/04/22 15:09:05 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_allocate(char *str, char *charset)
{
	size_t	lmalloc;
	size_t	i;

	i = 0;
	lmalloc = 0;
	while (str[i])
	{
		if (!ft_strchr(charset, str[i]))
			lmalloc++;
		i++;
	}
	return (lmalloc);
}

char			*ft_clearcharset(char *str, char *charset, int free)
{
	size_t	lmalloc;
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	j = 0;
	lmalloc = size_allocate(str, charset);
	ret = malloc((sizeof(char) * lmalloc + 1));
	while (str[i])
	{
		if (!ft_strchr(charset, str[i]))
			ret[j++] = str[i];
		i++;
	}
	if (free == 1)
		ft_strdel(&str);
	ret[lmalloc] = 0;
	return (ret);
}
