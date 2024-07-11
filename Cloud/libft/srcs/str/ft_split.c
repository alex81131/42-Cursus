/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:22:35 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:07:00 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			char_in_string(char si, char c)
{
	if (si == c)
		return (1);
	if (si == '\0')
		return (1);
	return (0);
}

static char			*ft_copy(char *dest, char *src, char c)
{
	int i;

	i = 0;
	while (char_in_string(src[i], c) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int			ft_size(const char *str, char c)
{
	int i;
	int word;

	i = 0;
	word = 1;
	while (str[i])
	{
		if (char_in_string(str[i], c) == 0 &&
				(char_in_string(str[i + 1], c) == 1))
			word++;
		i++;
	}
	return (word);
}

static int			ft_cpy_tab(char **split, char *str, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (char_in_string(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (char_in_string(str[i + j], c) == 0)
				j++;
			if (!(split[k] = (char *)malloc(sizeof(char) * (j + 1))))
				return (0);
			ft_copy(split[k], str + i, c);
			i = i + j;
			k++;
		}
	}
	return (1);
}

char				**ft_split(const char *s, char c)
{
	int		i;
	char	*str;
	char	**split;

	i = 0;
	str = (char *)s;
	if (!(split = (char **)ft_calloc(sizeof(char *), (ft_size(s, c) + 1))))
		return (0);
	if (!(ft_cpy_tab(split, str, c)))
	{
		while (split[i++])
			free(split[i]);
		free(split);
		return (NULL);
	}
	return (split);
}
