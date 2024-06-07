/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_s1.utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:12:28 by kyeh              #+#    #+#             */
/*   Updated: 2024/05/20 12:12:28 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ini_strjoin(char *s1)
{
	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	return (s1);
}

char	*ft_realloc_strjoin(char *s1, char const*s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	s1 = ini_strjoin(s1);
	if (!s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
/*
void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
		str[i++] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;

	result = malloc(count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, size * count);
	return (result);
}
*/
/*
sizeof(char) is guaranteed to be 1 by the C standard
*/